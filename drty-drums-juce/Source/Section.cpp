/*
  ==============================================================================

    Section.cpp
    Created: 23 Nov 2022 5:43:52pm
    Author:  ivtar

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Section.h"

//==============================================================================
Section::Section(juce::String name)
{
    this->name = name;
}

Section::~Section()
{
}

void Section::addItem(juce::Component* item)
{
    addAndMakeVisible(item);
    items.push_back(item);
}

void Section::paint (juce::Graphics& g)
{
    auto bg = juce::Colour(20, 20, 20);
    g.fillAll(bg);   // clear the background

    g.setColour(juce::Colours::darkgrey);
    g.drawRoundedRectangle(2, 2, getWidth() - 4, getHeight() - 4, 5, 2);

    auto font = juce::Font(20.f, juce::Font::plain);
    g.setFont(font);

    auto labelWidth = font.getStringWidth(name);
    auto labelHeight = (int)font.getHeight();

    juce::Rectangle textArea{ 20, -3, labelWidth + 20, labelHeight };
    
    g.setColour(bg);
    g.fillRect(textArea);

    g.setColour(juce::Colours::white);
    g.drawText(name, textArea, juce::Justification::centred);
}

void Section::resized()
{
    juce::Grid grid;

    using Track = juce::Grid::TrackInfo;
    using Fr = juce::Grid::Fr;

    for (int i = 0; i < numRows; i++) {
        grid.templateRows.add(Track(Fr(1)));
    }

    for (int i = 0; i < numColumns; i++) {
        grid.templateColumns.add(Track(Fr(1)));
    }

    for (auto comp : items) {
        grid.items.add(juce::GridItem(comp));
    }

    grid.performLayout(getLocalBounds()
        .withTrimmedLeft(10)
        .withTrimmedRight(10)
        .withTrimmedTop(10)
        .withTrimmedBottom(10));

}

void Section::addEmpty()
{
    items.push_back(new juce::Component());
}
