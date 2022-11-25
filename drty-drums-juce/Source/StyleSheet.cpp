/*
  ==============================================================================

    StyleSheet.cpp
    Created: 25 Nov 2022 11:40:33am
    Author:  ivtar

  ==============================================================================
*/

#include "StyleSheet.h"
namespace juce {
    void StyleSheet::drawRotarySlider(Graphics& g, int x, int y, int width, int height,
        float sliderPos, float rotaryStartAngle,
        float rotaryEndAngle, Slider& slider) 
    {
        auto bounds = Rectangle<int>(x, y, width, height).toFloat().reduced(5);
        auto radius = jmin(jmin(bounds.getWidth(), bounds.getHeight()) / 2.0f, 40.f);

        float halfRadius = radius / 2;

        auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        auto lineW = jmin(8.0f, radius * 0.25f);
        auto arcRadius = radius - lineW * 0.5f;


        // dial shadow
        auto knobShadowBounds = bounds.reduced(10);
        auto knobShadowRadius = arcRadius - 5;
        
        Path knobShadow;
        knobShadow.addEllipse(knobShadowBounds.getCentreX() - knobShadowRadius,
                              knobShadowBounds.getCentreY() - knobShadowRadius,
                              knobShadowRadius * 2, knobShadowRadius * 2);
        
        g.setColour(BasicColors::shadow);
        g.fillPath(knobShadow);

        // main dial circle
        auto knobRadius = knobShadowRadius - 2.0;

        Path knobCircle;
        knobCircle.addEllipse(knobShadowBounds.getCentreX() - knobRadius,
                              knobShadowBounds.getCentreY() - knobRadius,
                              knobRadius * 2, knobRadius * 2);
        auto knobGradient = juce::ColourGradient::vertical(BasicColors::knobLight, 
                                                           knobShadowBounds.getCentreY() - knobRadius,
                                                           BasicColors::knobDark,
                                                           knobShadowBounds.getCentreY() + knobRadius);
        g.setGradientFill(knobGradient);
        g.fillPath(knobCircle);

        
        // main dial circle
        auto knobCenterRadius = knobRadius / 1.2;

        Path knobCenterCircle;
        knobCenterCircle.addEllipse(knobShadowBounds.getCentreX() - knobCenterRadius,
                                    knobShadowBounds.getCentreY() - knobCenterRadius,
                                    knobCenterRadius * 2, knobCenterRadius * 2);
        
        auto knobCenterGradient = juce::ColourGradient::vertical(BasicColors::knobLight,
                                                                 knobShadowBounds.getCentreY() + knobCenterRadius,
                                                                 BasicColors::knobDark,
                                                                 knobShadowBounds.getCentreY() - knobCenterRadius / 2);

        g.setGradientFill(knobCenterGradient);
        g.fillPath(knobCenterCircle);

        // dial background path
        Path backgroundArc;
        backgroundArc.addCentredArc(bounds.getCentreX(),
            bounds.getCentreY(),
            arcRadius,
            arcRadius,
            0.0f,
            rotaryStartAngle,
            rotaryEndAngle,
            true);

        g.setColour(BasicColors::lines);
        g.strokePath(backgroundArc, PathStrokeType(1.5, PathStrokeType::curved, PathStrokeType::rounded));

        // dial active arc
        if (slider.isEnabled())
        {
            Path valueArc;
            valueArc.addCentredArc(bounds.getCentreX(),
                bounds.getCentreY(),
                arcRadius,
                arcRadius,
                0.0f,
                rotaryStartAngle,
                toAngle,
                true);

            auto arcGradient = juce::ColourGradient::vertical(BasicColors::accent,
                                                               knobShadowBounds.getCentreY() - knobRadius,
                                                               BasicColors::accentDart,
                                                               knobShadowBounds.getCentreY() + knobRadius);
            
            g.setGradientFill(arcGradient);
            g.strokePath(valueArc, PathStrokeType(2.0, PathStrokeType::curved, PathStrokeType::rounded));
        }
        
        auto thumbWidth = knobRadius / 3.0;
        auto centerDiff = knobRadius / 1.5;
        auto thimbAccentWidth = thumbWidth / 2;

        Point<float> thumbPoint(bounds.getCentreX() + centerDiff * std::cos(toAngle - MathConstants<float>::halfPi),
            bounds.getCentreY() + centerDiff * std::sin(toAngle - MathConstants<float>::halfPi));


        g.setColour(BasicColors::accentDart.interpolatedWith(BasicColors::accent, toAngle / rotaryEndAngle));
        g.fillEllipse(Rectangle<float>(thimbAccentWidth, thimbAccentWidth).withCentre(thumbPoint));

        auto name = slider.getName();

        auto textCenter = bounds.getCentre();
        textCenter.addXY(0, knobShadowRadius + 2);
        g.setFont(12);
        g.setColour(BasicColors::text);
        g.drawText(name, Rectangle<float>(bounds.getWidth(), 20).withCentre(textCenter), juce::Justification::centredBottom);
            
    }
}