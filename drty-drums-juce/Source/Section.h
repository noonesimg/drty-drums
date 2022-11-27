/*
  ==============================================================================

    Section.h
    Created: 23 Nov 2022 5:43:52pm
    Author:  ivtar

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/

struct SectionElement {
    const char* text;
    const char* paramId;
    int rowStart;
    int colStart;
    int rowSpan;
    int colSpan;
};

class Section  : public juce::Component
{
public:
    Section(juce::String name);
    ~Section() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void addItem(juce::Component* item, SectionElement el);
    void addEmpty();

    int numRows = 3;
    int numColumns = 2;

    std::vector<SectionElement> elements;

    std::vector<juce::Component*> items;
    
private:
    juce::String name;
    juce::String componentName = "section";
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Section)
};
