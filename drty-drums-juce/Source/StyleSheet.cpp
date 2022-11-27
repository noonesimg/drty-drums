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

    void StyleSheet::drawButtonBackground(Graphics& g, Button& button,
        const Colour& backgroundColour,
        bool shouldDrawButtonAsHighlighted,
        bool shouldDrawButtonAsDown)
    {
        auto cornerSize = 6.0f;
        auto bounds = button.getLocalBounds().toFloat().reduced(0.5f, 0.5f);
        auto infilBounds = bounds.reduced(5);

        auto baseColour = backgroundColour.withMultipliedSaturation(button.hasKeyboardFocus(true) ? 1.3f : 0.9f)
            .withMultipliedAlpha(button.isEnabled() ? 1.0f : 0.5f);

        if (shouldDrawButtonAsDown || shouldDrawButtonAsHighlighted)
            baseColour = baseColour.contrasting(shouldDrawButtonAsDown ? 0.2f : 0.05f);

        auto parent = button.getParentComponent();
        if (parent->getName() == "section")
        {
            Path base;
            base.addRoundedRectangle(bounds, cornerSize);

            auto baseGradient = juce::ColourGradient::vertical(BasicColors::knobLight, BasicColors::knobDark, bounds);
            if (shouldDrawButtonAsDown) {
                g.setColour(BasicColors::knobMedium);
            }
            else {
                g.setGradientFill(baseGradient);
            }

            g.fillPath(base);
            
            Path infill;
            infill.addRoundedRectangle(infilBounds, cornerSize - 2);

            if (shouldDrawButtonAsDown) {
                g.setColour(BasicColors::knobMedium);
            }
            else {
                g.setColour(BasicColors::knobLight);
            }

            g.fillPath(infill);

            auto ledPoint = infilBounds.getCentre();
            auto ledBounds = juce::Rectangle<float>(ledPoint.getX() - 10, ledPoint.getY() + 15, 20, 5);
            auto ledBgBounds = ledBounds.reduced(-5);
            auto ledGradient = juce::ColourGradient::vertical(BasicColors::knobDark, BasicColors::knobLight, ledBgBounds);

            Path ledBg;
            ledBg.addRoundedRectangle(ledBgBounds, 7);
            g.setGradientFill(ledGradient);
            g.fillPath(ledBg);

            Path led;
            led.addRoundedRectangle(ledBounds, 3);

            if (shouldDrawButtonAsDown) {
                g.setColour(BasicColors::accent);
            }
            else if (shouldDrawButtonAsHighlighted) {
                g.setColour(BasicColors::accentDart);
            }
            else {
                g.setColour(BasicColors::knobLight);
            }
            g.fillPath(led);
        }
        else
        {
            g.setColour(baseColour);
            Path path;
            path.addRoundedRectangle(bounds.getX(), bounds.getY(),
                bounds.getWidth(), bounds.getHeight(),
                cornerSize, cornerSize, true, true, true, true);

            g.fillPath(path);
            g.setColour(BasicColors::lines);
            g.strokePath(path, PathStrokeType(2.0f));
        }
    }

    void StyleSheet::drawButtonText(Graphics& g,
        TextButton& button,
        bool shouldDrawButtonAsHighlighted,
        bool shouldDrawButtonAsDown)
    {
        Font font(getTextButtonFont(button, button.getHeight()));
        g.setFont(font);
        g.setColour(BasicColors::text);

        const int yIndent = jmin(4, button.proportionOfHeight(0.3f));
        const int cornerSize = jmin(button.getHeight(), button.getWidth()) / 2;

        const int fontHeight = roundToInt(font.getHeight() * 0.6f);
        const int leftIndent = jmin(fontHeight, 2 + cornerSize / (button.isConnectedOnLeft() ? 4 : 2));
        const int rightIndent = jmin(fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2));
        const int textWidth = button.getWidth() - leftIndent - rightIndent;

        if (textWidth > 0)
            g.drawFittedText(button.getButtonText(),
                leftIndent, yIndent, textWidth, button.getHeight() - yIndent * 2,
                Justification::centred, 2);
    }

    void StyleSheet::drawLinearSlider(Graphics& g, int x, int y, int width, int height,
        float sliderPos,
        float minSliderPos,
        float maxSliderPos,
        const Slider::SliderStyle style, Slider& slider)
    {
        height /= 1.2;
        sliderPos /= 1.2;

        auto trackWidth = jmin(6.0f, (float)width * 0.25f) / 2;

        Point<float> startPoint((float)x + (float)width * 0.5f, (float)(height + y));

        Point<float> endPoint(startPoint.x, (float)y);

        Path backgroundTrack;
        backgroundTrack.startNewSubPath(startPoint);
        backgroundTrack.lineTo(endPoint);

        g.setColour(BasicColors::lines);
        g.strokePath(backgroundTrack, { trackWidth, PathStrokeType::curved, PathStrokeType::rounded });

        Path valueTrack;
        Point<float> minPoint, maxPoint, thumbPoint;
        
        auto kx = ((float)x + (float)width * 0.5f);
        auto ky = sliderPos;

        minPoint = startPoint;
        maxPoint = { kx, ky };

        auto thumbWidth = getSliderThumbRadius(slider);

        valueTrack.startNewSubPath(minPoint);
        valueTrack.lineTo(maxPoint);

        auto valueGradient = juce::ColourGradient::vertical(BasicColors::accentDart, startPoint.getY(), BasicColors::accent, ky);

        g.setGradientFill(valueGradient);
        g.strokePath(valueTrack, { trackWidth, PathStrokeType::curved, PathStrokeType::rounded });

        Path thumb;
        auto thumbRect = juce::Rectangle<float>(thumbWidth * 2, thumbWidth).withCentre(maxPoint);
        auto thumbGradient = juce::ColourGradient::vertical(BasicColors::knobLight, BasicColors::knobDark, thumbRect);

        thumb.addRoundedRectangle(thumbRect, 2);

        g.setGradientFill(thumbGradient);
        g.fillPath(thumb);

        Path thumbInner;
        auto thumbInnerRect = thumbRect.reduced(2);
        thumbGradient = juce::ColourGradient::vertical(BasicColors::knobMedium, BasicColors::knobLight, thumbInnerRect);

        thumbInner.addRoundedRectangle(thumbInnerRect, 2);

        g.setGradientFill(thumbGradient);
        g.fillPath(thumbInner);

        g.setColour(BasicColors::accent.interpolatedWith(BasicColors::accentDart, sliderPos / maxSliderPos));
        g.fillRoundedRectangle(thumbInnerRect.reduced(3), 2);


        auto name = slider.getName();

        auto textCenter = startPoint;
        textCenter.addXY(0, 15);
        g.setFont(12);
        g.setColour(BasicColors::text);
        g.drawText(name, Rectangle<float>(width, 20).withCentre(textCenter), juce::Justification::centredBottom);
    }
}