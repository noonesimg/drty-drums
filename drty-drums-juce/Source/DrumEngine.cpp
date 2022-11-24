/*
  ==============================================================================

    DrumEngine.cpp
    Created: 22 Nov 2022 6:00:16pm
    Author:  ivtar

  ==============================================================================
*/

#include "DrumEngine.h"
#include "DSP.h"

void DrumEngine::prepare(double sampleRate, int samplesPerBlock)
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

void DrumEngine::release()
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

void DrumEngine::setParameter(const char * path, float value)
{
    fUI->setParamValue(path, value);
}

float DrumEngine::getParameter(const char* path)
{
    return fUI->getParamValue(path);
}

void DrumEngine::parameterChanged(const juce::String& parameterID, float newValue)
{
    std::string paramId = parameterID.toStdString();
    fUI->setParamValue(paramId, newValue);
}





