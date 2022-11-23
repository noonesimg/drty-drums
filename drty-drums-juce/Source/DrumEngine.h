#pragma once
#include "DSPParameters.h"

class MapUI;
class mydsp;

class DrumEngine {

public:
	void prepareToPlay(double sampleRate, int samplesPerBlock);
	void releaseResources();
	void processBlock(int numSamples);
	void setGate(DrumVoices voice, float value);

	float** outputs;

private:
	MapUI* fUI;
	mydsp* fDSP;
};