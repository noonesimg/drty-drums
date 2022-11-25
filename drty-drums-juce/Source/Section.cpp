/*
  ==============================================================================

    Section.cpp
    Created: 23 Nov 2022 5:43:52pm
    Author:  ivtar

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Section.h"
#include "StyleSheet.h"

//==============================================================================
Section::Section(juce::String name)
{
    this->name = name;
}

Section::~Section()
{
}

void Section::addItem(juce::Component* item, SectionElement el)
{
    addAndMakeVisible(item);
    elements.push_back(el);
    items.push_back(item);
}

void Section::paint (juce::Graphics& g)
{
    g.fillAll(BasicColors::bg);

    g.setColour(BasicColors::lines);
    g.drawRoundedRectangle(2, 2, getWidth() - 4, getHeight() - 4, 5, 2);

    auto font = juce::Font(20.f, juce::Font::plain);
    g.setFont(font);

    auto labelWidth = font.getStringWidth(name);
    auto labelHeight = (int)font.getHeight();

    juce::Rectangle textArea{ 20, -3, labelWidth + 20, labelHeight };
    
    g.setColour(BasicColors::bg);
    g.fillRect(textArea);

    g.setColour(BasicColors::sectionText);
    g.drawText(name, textArea, juce::Justification::centred);
}

void Section::resized()
{
    juce::Grid grid;
    grid.setGap(juce::Grid::Px(5));

    using Track = juce::Grid::TrackInfo;
    using Fr = juce::Grid::Fr;
    using Span = juce::GridItem::Span;

    for (int i = 0; i < numRows; i++) {
        grid.templateRows.add(Track(Fr(1)));
    }

    for (int i = 0; i < numColumns; i++) {
        grid.templateColumns.add(Track(Fr(1)));
    }

    int i = 0;
    for (auto comp : items) {
        auto el = elements.at(i);
        grid.items.add(juce::GridItem(comp).withArea(
            el.rowStart, 
            el.colStart, 
            Span(el.rowSpan), 
            Span(el.colSpan)));
        i++;
    }

    grid.performLayout(getLocalBounds()
        .withTrimmedLeft(10)
        .withTrimmedRight(10)
        .withTrimmedTop(15)
        .withTrimmedBottom(10));

}

void Section::addEmpty()
{
    items.push_back(new juce::Component());
}
