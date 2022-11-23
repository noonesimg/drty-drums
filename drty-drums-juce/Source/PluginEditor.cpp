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
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 300);
    setResizable(true, true);
    
    addButton(10, 10, 100, 100, "kick", DSPParameterContants::kickGateParamID);
    addButton(120, 10, 100, 100, "snare", DSPParameterContants::snareGateParamID);
    addButton(230, 10, 100, 100, "hihat", DSPParameterContants::hihatGateParamID);
    addButton(340, 10, 100, 100, "cowbell", DSPParameterContants::cowbellGateParamID);
}

void DrtydrumsAudioProcessorEditor::addButton(int x, int y, int width, int height, const char* text, const char* paramId)
{
    using namespace DSPParameterContants;
    auto* btn = new juce::TextButton(text);
    addAndMakeVisible(btn);
    btn->setBounds(x, y, width, height);

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
}

DrtydrumsAudioProcessorEditor::~DrtydrumsAudioProcessorEditor()
{
}

//==============================================================================
void DrtydrumsAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void DrtydrumsAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
