/*
  ==============================================================================

    StyleSheet.h
    Created: 25 Nov 2022 11:40:33am
    Author:  ivtar

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

namespace BasicColors {
    //inline const auto bg = juce::Colour(62, 70, 79);
    inline const auto bg = juce::Colour(33, 33, 33);
    inline const auto shadow = juce::Colour(39, 45, 51);
    inline const auto knobDark = juce::Colour(27, 30, 34);
    inline const auto knobLight = juce::Colour(51, 64, 77);
    inline const auto knobMedium = juce::Colour(37, 41, 49);
    inline const auto accent = juce::Colour(255, 187, 0);
    inline const auto accentDart = juce::Colour(255, 50, 0);
    inline const auto lines = juce::Colour(86, 102, 117);
    inline const auto sectionText = juce::Colour(131, 155, 176);
    inline const auto text = juce::Colour(119, 141, 161);
};

namespace juce {
    class StyleSheet : public juce::LookAndFeel_V4
    {
    public:
        // Add methods later
        void drawRotarySlider(Graphics&, int x, int y, int width, int height,
            float sliderPosProportional, float rotaryStartAngle,
            float rotaryEndAngle, Slider&) override;

        void drawButtonBackground(Graphics& g, Button& button,
            const Colour& backgroundColour,
            bool shouldDrawButtonAsHighlighted,
            bool shouldDrawButtonAsDown) override;
        
        void drawButtonText(Graphics& g,
            TextButton& button,
            bool shouldDrawButtonAsHighlighted,
            bool shouldDrawButtonAsDown) override;

        void drawLinearSlider(Graphics& g, int x, int y, int width, int height,
            float sliderPos,
            float minSliderPos,
            float maxSliderPos,
            const Slider::SliderStyle style, Slider& slider) override;

    };
}
