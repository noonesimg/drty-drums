/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Section.h"
#include "StyleSheet.h"


//==============================================================================
/**
*/
class DrtydrumsAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    using SliderStyle = juce::Slider::SliderStyle;

    DrtydrumsAudioProcessorEditor (DrtydrumsAudioProcessor&);
    ~DrtydrumsAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    using ButtonAttachment = juce::AudioProcessorValueTreeState::ButtonAttachment;
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DrtydrumsAudioProcessor& audioProcessor;


    Section kick{ "kick" };
    Section snare{ "snare" };
    Section hihat{ "hihat" };
    Section cowbell{ "cowbell" };

    Section mixer{ "mixer" };
    Section revSends{ "reverb sends" };
    Section delSends{ "delay sends" };

    Section delFx{ "delay" };
    Section compFx{ "compressor" };



    std::vector<juce::TextButton*> buttons;
    std::vector<std::unique_ptr<ButtonAttachment>> buttonAttachments;
    std::vector<std::unique_ptr<SliderAttachment>> sliderAttachments;

    void addButtonToSection(Section& section, SectionElement el);
    void addKnobToSection(Section& section, SectionElement el);
    void addSliderToSection(Section& section, SectionElement el, SliderStyle style = SliderStyle::RotaryVerticalDrag);

    juce::StyleSheet lookAndFeel;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrtydrumsAudioProcessorEditor)
};
