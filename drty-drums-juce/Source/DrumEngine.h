#pragma once
#include "DSPParameters.h"

class MapUI;
class mydsp;

class DrumEngine : public juce::AudioProcessorValueTreeState::Listener {

public:
	DrumEngine(DSPParameters& parameters) : parameters(parameters) {

	};

	void prepare(double sampleRate, int samplesPerBlock);
	void release();
	void processBlock(int numSamples);

	void setParameter(const char* path, float value);

	void parameterChanged(const juce::String& parameterID, float newValue) override;

	float** outputs;

private:
	DSPParameters& parameters;

	MapUI* fUI;
	mydsp* fDSP;
};