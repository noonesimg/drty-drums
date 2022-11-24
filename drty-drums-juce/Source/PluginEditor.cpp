/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DrtydrumsAudioProcessorEditor::DrtydrumsAudioProcessorEditor (DrtydrumsAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setResizable(true, true);
    
    mixer.numColumns = 4;
    mixer.numRows = 1;
    addSliderToSection(DSPParameterContants::kickLevelParamID, mixer);
    addSliderToSection(DSPParameterContants::snareLevelParamID, mixer);
    addSliderToSection(DSPParameterContants::hihatLevelParamID, mixer);
    addSliderToSection(DSPParameterContants::cowbellLevelParamID, mixer);
    addAndMakeVisible(mixer);


    sends.numColumns = 3;
    sends.numRows = 2;
    addKnobToSection(DSPParameterContants::snareReverbSendParamID, sends);
    addKnobToSection(DSPParameterContants::hihatReverbSendParamID, sends);
    addKnobToSection(DSPParameterContants::cowbellReverbSendParamID, sends);

    addKnobToSection(DSPParameterContants::snareDelaySendParamID, sends);
    addKnobToSection(DSPParameterContants::hihatDelaySendParamID, sends);
    addKnobToSection(DSPParameterContants::cowbellDelaySendParamID, sends);
    addAndMakeVisible(sends);

    fx.numColumns = 2;
    fx.numRows = 2;
    addKnobToSection(DSPParameterContants::delayRatioParamID, fx);
    addKnobToSection(DSPParameterContants::delayFeedbackParamID, fx);
    addKnobToSection(DSPParameterContants::compressorThresholdParamID, fx);
    addAndMakeVisible(fx);

    addKnobToSection(DSPParameterContants::kickDecayParamID, kick);
    addKnobToSection(DSPParameterContants::kickColorParamID, kick);
    addKnobToSection(DSPParameterContants::kickNoiseParamID, kick);
    addKnobToSection(DSPParameterContants::kickDriveParamID, kick);
    addButtonToSection("kick", DSPParameterContants::kickGateParamID, kick);
    addAndMakeVisible(kick);

    addKnobToSection(DSPParameterContants::snareDecayParamID, snare);
    addKnobToSection(DSPParameterContants::snareColorParamID, snare);
    addKnobToSection(DSPParameterContants::snareNoiseParamID, snare);
    addKnobToSection(DSPParameterContants::snareDriveParamID, snare);
    addButtonToSection("snare", DSPParameterContants::snareGateParamID, snare);
    addAndMakeVisible(snare);

    addKnobToSection(DSPParameterContants::hihatDecayParamID, hihat);
    addKnobToSection(DSPParameterContants::hihatColorParamID, hihat);
    addKnobToSection(DSPParameterContants::hihatNoiseParamID, hihat);
    addKnobToSection(DSPParameterContants::hihatDriveParamID, hihat);
    addButtonToSection("hihat", DSPParameterContants::hihatGateParamID, hihat);
    addAndMakeVisible(hihat);

    addKnobToSection(DSPParameterContants::cowbellDecayParamID, cowbell);
    addKnobToSection(DSPParameterContants::cowbellColorParamID, cowbell);
    addKnobToSection(DSPParameterContants::cowbellDetuneParamID, cowbell);
    cowbell.addEmpty();
    addButtonToSection("cowbell", DSPParameterContants::cowbellGateParamID, cowbell);
    addAndMakeVisible(cowbell);

    setSize(600, 400);
}



void DrtydrumsAudioProcessorEditor::addButtonToSection(const char* text, const char* paramId, Section& section)
{
    using namespace DSPParameterContants;
    auto* btn = new juce::TextButton(text);
    
    btn->onStateChange = [this, btn]() {
        switch (btn->getState()) {
        case juce::Button::ButtonState::buttonDown:
            btn->setToggleState(true, true);
            break;
        case juce::Button::ButtonState::buttonNormal:
        case juce::Button::ButtonState::buttonOver:
            btn->setToggleState(false, true);
            break;
        }
    };
    buttonAttachments.push_back(std::make_unique<ButtonAttachment>(audioProcessor.valueTreeState, paramId, *btn));
    audioProcessor.valueTreeState.addParameterListener(paramId, &audioProcessor.drumEngine);

    section.addItem(btn);
}

void DrtydrumsAudioProcessorEditor::addKnobToSection(const char* paramId, Section& section)
{
    using namespace DSPParameterContants;
    auto* slider = new juce::Slider();
    slider->setSliderStyle(juce::Slider::RotaryVerticalDrag);
    slider->setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider->setRange(0, 1, 0.01);
    section.addItem(slider);

    sliderAttachments.push_back(std::make_unique<SliderAttachment>(audioProcessor.valueTreeState, paramId, *slider));
    audioProcessor.valueTreeState.addParameterListener(paramId, &audioProcessor.drumEngine);
    slider->setValue(audioProcessor.drumEngine.getParameter(paramId));
}

void DrtydrumsAudioProcessorEditor::addSliderToSection(const char* paramId, Section& section)
{
    using namespace DSPParameterContants;
    auto* slider = new juce::Slider();
    slider->setSliderStyle(juce::Slider::LinearVertical);
    slider->setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider->setRange(0, 1, 0.01);
    section.addItem(slider);

    sliderAttachments.push_back(std::make_unique<SliderAttachment>(audioProcessor.valueTreeState, paramId, *slider));
    audioProcessor.valueTreeState.addParameterListener(paramId, &audioProcessor.drumEngine);
    slider->setValue(audioProcessor.drumEngine.getParameter(paramId));
}

DrtydrumsAudioProcessorEditor::~DrtydrumsAudioProcessorEditor()
{
}

//==============================================================================
void DrtydrumsAudioProcessorEditor::paint (juce::Graphics& g)
{
    auto bg = juce::Colour(20, 20, 20);
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (bg);
}

void DrtydrumsAudioProcessorEditor::resized()
{
    using Span = juce::GridItem::Span;
    using Track = juce::Grid::TrackInfo;
    using Fr = juce::Grid::Fr;

    // mixer
    juce::Grid grid;
    grid.templateRows = { Track(Fr(1)), Track(Fr(1)) };
    grid.templateColumns = { Track(Fr(1)), Track(Fr(1)), Track(Fr(1)), Track(Fr(1)) };
    grid.setGap(juce::Grid::Px(5));
    grid.items.add(juce::GridItem(&mixer));


    // sends
    grid.setGap(juce::Grid::Px(5));
    grid.items.add(juce::GridItem(&sends).withArea(1, 2, Span(1), Span(2)));

    // fx
    grid.items.add(juce::GridItem(&fx));


    // bottom half
    auto voices = {
        &kick,
        &snare,
        &hihat,
        &cowbell
    };
    for (auto section : voices)
    {
        auto gi = juce::GridItem(*section);
        gi.minWidth = 100.f;
        gi.minHeight = 100.f;

       grid.items.add(gi);
    }
    
    grid.performLayout(getLocalBounds()
        .withTrimmedLeft(10)
        .withTrimmedRight(10)
        .withTrimmedTop(10)
        .withTrimmedBottom(10));
}
