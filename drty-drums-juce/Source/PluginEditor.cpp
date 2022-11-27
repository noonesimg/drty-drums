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
    setResizeLimits(540, 440, 1300, 940);
    juce::LookAndFeel::setDefaultLookAndFeel(&lookAndFeel);


    // init mixer section
    mixer.numColumns = 4;
    mixer.numRows = 1;
    addSliderToSection(mixer, SectionElement{
            "kick", DSPParameterContants::kickLevelParamID, 
            1, 1, 1, 1
        }, SliderStyle::LinearVertical);
    addSliderToSection(mixer, SectionElement{
            "snare", DSPParameterContants::snareLevelParamID,
            1, 2, 1, 1
        }, SliderStyle::LinearVertical);
    addSliderToSection(mixer, SectionElement{
            "hihat", DSPParameterContants::hihatLevelParamID,
            1, 3, 1, 1
        }, SliderStyle::LinearVertical);
    addSliderToSection(mixer, SectionElement{
            "cowbell", DSPParameterContants::cowbellLevelParamID,
            1, 4, 1, 1
        }, SliderStyle::LinearVertical);
    addAndMakeVisible(mixer);

    // init reverb send section
    revSends.numColumns = 3;
    revSends.numRows = 1;
    addSliderToSection(revSends, SectionElement{
            "snare", DSPParameterContants::snareReverbSendParamID,
            1, 1, 1, 1
        });
    addSliderToSection(revSends, SectionElement{
            "hihat", DSPParameterContants::hihatReverbSendParamID,
            1, 2, 1, 1
        });
    addSliderToSection(revSends, SectionElement{
            "cowbell", DSPParameterContants::cowbellReverbSendParamID,
            1, 3, 1, 1
        });
    addAndMakeVisible(revSends);

    // init delay send section
    delSends.numColumns = 3;
    delSends.numRows = 1;
    addSliderToSection(delSends, SectionElement{
            "snare", DSPParameterContants::snareDelaySendParamID,
            1, 1, 1, 1
        });
    addSliderToSection(delSends, SectionElement{
            "hihat", DSPParameterContants::hihatDelaySendParamID,
            1, 2, 1, 1
        });
    addSliderToSection(delSends, SectionElement{
            "cowbell", DSPParameterContants::cowbellDelaySendParamID,
            1, 3, 1, 1
        });
    addAndMakeVisible(delSends);

    compFx.numColumns = 2;
    compFx.numRows = 1;
    addSliderToSection(compFx, SectionElement{
            "attack", DSPParameterContants::compressorAttackParamID,
            1, 1, 1, 1
        });
    addSliderToSection(compFx, SectionElement{
            "threshold", DSPParameterContants::compressorThresholdParamID,
            1, 2, 1, 1
        });
    addAndMakeVisible(compFx);

    // init delay settings section
    delFx.numColumns = 2;
    delFx.numRows = 1;
    addSliderToSection(delFx, SectionElement{
            "ratio", DSPParameterContants::delayRatioParamID,
            1, 1, 1, 1
        });
    addSliderToSection(delFx, SectionElement{
            "feedback", DSPParameterContants::delayFeedbackParamID,
            1, 2, 1, 1
        });
    addAndMakeVisible(delFx);


    // init kick settings section
    addSliderToSection(kick, SectionElement{
            "decay", DSPParameterContants::kickDecayParamID,
            1, 1, 1, 1
        });
    addSliderToSection(kick, SectionElement{
            "color", DSPParameterContants::kickColorParamID,
            1, 2, 1, 1
        });
    addSliderToSection(kick, SectionElement{
            "noise", DSPParameterContants::kickNoiseParamID,
            2, 1, 1, 1
        });
    addSliderToSection(kick, SectionElement{
            "drive", DSPParameterContants::kickDriveParamID,
            2, 2, 1, 1
        });
    addButtonToSection(kick, SectionElement{
            "kick", DSPParameterContants::kickGateParamID,
            3, 1, 1, 2
        });
    addAndMakeVisible(kick);

    // init snare settings section
    addSliderToSection(snare, SectionElement{
            "decay", DSPParameterContants::snareDecayParamID,
            1, 1, 1, 1
        });
    addSliderToSection(snare, SectionElement{
            "color", DSPParameterContants::snareColorParamID,
            1, 2, 1, 1
        });
    addSliderToSection(snare, SectionElement{
            "noise", DSPParameterContants::snareNoiseParamID,
            2, 1, 1, 1
        });
    addSliderToSection(snare, SectionElement{
            "drive", DSPParameterContants::snareDriveParamID,
            2, 2, 1, 1
        });
    addButtonToSection(snare, SectionElement{
            "snare", DSPParameterContants::snareGateParamID,
            3, 1, 1, 2
        });
    addAndMakeVisible(snare);

    // init hihat settings section
    addSliderToSection(hihat, SectionElement{
            "decay", DSPParameterContants::hihatDecayParamID,
            1, 1, 1, 1
        });
    addSliderToSection(hihat, SectionElement{
            "color", DSPParameterContants::hihatColorParamID,
            1, 2, 1, 1
        });
    addSliderToSection(hihat, SectionElement{
            "noise", DSPParameterContants::hihatNoiseParamID,
            2, 1, 1, 1
        });
    addSliderToSection(hihat, SectionElement{
            "drive", DSPParameterContants::hihatDriveParamID,
            2, 2, 1, 1
        });
    addButtonToSection(hihat, SectionElement{
            "hihat", DSPParameterContants::hihatGateParamID,
            3, 1, 1, 2
        });
    addAndMakeVisible(hihat);

    // init cowbell settings section
    addSliderToSection(cowbell, SectionElement{
            "decay", DSPParameterContants::cowbellDecayParamID,
            1, 1, 1, 1
        });
    addSliderToSection(cowbell, SectionElement{
            "color", DSPParameterContants::cowbellColorParamID,
            1, 2, 1, 1
        });
    addSliderToSection(cowbell, SectionElement{
            "detune", DSPParameterContants::cowbellDetuneParamID,
            2, 1, 1, 2
        });
    addButtonToSection(cowbell, SectionElement{
            "cowbell", DSPParameterContants::cowbellGateParamID,
            3, 1, 1, 2
        });
    addAndMakeVisible(cowbell);

    setSize(720, 500);
}



void DrtydrumsAudioProcessorEditor::addButtonToSection(Section& section, SectionElement el)
{
    using namespace DSPParameterContants;
    auto* btn = new juce::TextButton(el.text);
    
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
    buttonAttachments.push_back(std::make_unique<ButtonAttachment>(audioProcessor.valueTreeState, el.paramId, *btn));
    audioProcessor.valueTreeState.addParameterListener(el.paramId, &audioProcessor.drumEngine);

    section.addItem(btn, el);
}

void DrtydrumsAudioProcessorEditor::addSliderToSection(Section& section, SectionElement el, SliderStyle style)
{
    using namespace DSPParameterContants; 
    auto* slider = new juce::Slider();
    slider->setName(el.text);
    slider->setSliderStyle(style);
    slider->setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    slider->setRange(0, 1, 0.01);
    section.addItem(slider, el);

    sliderAttachments.push_back(std::make_unique<SliderAttachment>(audioProcessor.valueTreeState, el.paramId, *slider));
    audioProcessor.valueTreeState.addParameterListener(el.paramId, &audioProcessor.drumEngine);
    slider->setValue(audioProcessor.drumEngine.getParameter(el.paramId));
}

DrtydrumsAudioProcessorEditor::~DrtydrumsAudioProcessorEditor()
{
    juce::LookAndFeel::setDefaultLookAndFeel(nullptr);
}

//==============================================================================
void DrtydrumsAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (BasicColors::bg);
}

void DrtydrumsAudioProcessorEditor::resized()
{
    using GridItem = juce::GridItem;
    using Span = juce::GridItem::Span;
    using Track = juce::Grid::TrackInfo;
    using Fr = juce::Grid::Fr;
    
    // grid
    juce::Grid grid;
    grid.setGap(juce::Grid::Px(3));

    // 5 rows 
    for (int i = 0; i < 5; i++)
        grid.templateRows.add(Track(Fr(1)));

    // 8 cols
    for (int i = 0; i < 8; i++)
        grid.templateColumns.add(Track(Fr(1)));

    // sends
    grid.items.add(GridItem(&mixer).withArea(1, 1, Span(2), Span(3)));

    // reverb sends
    grid.items.add(GridItem(&revSends).withArea(1, 4, Span(1), Span(3)));

    // delay sends
    grid.items.add(GridItem(&delSends).withArea(2, 4, Span(1), Span(3)));
    

    // comp fx
    grid.items.add(GridItem(&compFx).withArea(1, 7, Span(1), Span(2)));

    // delay fx
    grid.items.add(GridItem(&delFx).withArea(2, 7, Span(1), Span(2)));


    // bottom half
    auto voices = {
        &kick,
        &snare,
        &hihat,
        &cowbell
    };

    int i = 1;
    for (auto section : voices)
    {
        grid.items.add(GridItem(*section).withArea(3, i, Span(3), Span(2)));
        i += 2;
    }
    
    grid.performLayout(getLocalBounds()
        .withTrimmedLeft(10)
        .withTrimmedRight(10)
        .withTrimmedTop(10)
        .withTrimmedBottom(10));
}
