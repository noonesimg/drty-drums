/*
  ==============================================================================

    DrumEngine.cpp
    Created: 22 Nov 2022 6:00:16pm
    Author:  ivtar

  ==============================================================================
*/

#include "DrumEngine.h"
#include "DSP.h"

void DrumEngine::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    fDSP = new mydsp();
    fDSP->init(sampleRate);
    fUI = new MapUI();
    fDSP->buildUserInterface(fUI);
    outputs = new float* [2];
    for (int ch = 0; ch < 2; ++ch) {
        outputs[ch] = new float[samplesPerBlock];
    }
}

void DrumEngine::releaseResources()
{
    delete fDSP;
    delete fUI;
    for (int ch = 0; ch < 2; ++ch) {
        delete[] outputs[ch];
    }
    delete[] outputs;
}

void DrumEngine::processBlock(int numSamples)
{
    fDSP->compute(numSamples, NULL, outputs);
}

void DrumEngine::setGate(DrumVoices voice, float value)
{
    switch (voice) {
    case KICK:
        fUI->setParamValue(DSPParameters::kick_gate, value); break;
    case SNARE: 
        fUI->setParamValue(DSPParameters::snare_gate, value); break;
    case HIHAT: 
        fUI->setParamValue(DSPParameters::hihat_gate, value); break;
    case COWBELL: 
        fUI->setParamValue(DSPParameters::cowbell_gate, value); break;
    }
}




