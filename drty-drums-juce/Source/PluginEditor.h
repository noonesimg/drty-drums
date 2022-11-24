/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Section.h"

//==============================================================================
/**
*/
class DrtydrumsAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
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
    Section sends{ "sends" };
    Section fx{ "fx" };



    std::vector<juce::TextButton*> buttons;
    std::vector<std::unique_ptr<ButtonAttachment>> buttonAttachments;
    std::vector<std::unique_ptr<SliderAttachment>> sliderAttachments;

    void addButtonToSection(const char* text, const char* paramId, Section& section);
    void addKnobToSection(const char* paramId, Section& section);
    void addSliderToSection(const char* paramId, Section& section);


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrtydrumsAudioProcessorEditor)
};
