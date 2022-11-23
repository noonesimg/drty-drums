/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

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

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DrtydrumsAudioProcessor& audioProcessor;

    juce::TextButton kickButton;
    std::vector<std::unique_ptr<ButtonAttachment>> buttonAttachments;

    void addButton(int x, int y, int width, int height, const char* text, const char* paramId);


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrtydrumsAudioProcessorEditor)
};
