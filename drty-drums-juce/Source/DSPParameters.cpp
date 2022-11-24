/*
  ==============================================================================

    DSPParameters.cpp
    Created: 23 Nov 2022 10:40:11am
    Author:  ivtar

  ==============================================================================
*/

#include "DSPParameters.h"

DSPParameters::DSPParameters(juce::AudioProcessorValueTreeState& valueTreeState) {
    using namespace DSPParameterContants;

    kickGate = valueTreeState.getRawParameterValue(kickGateParamID);
    snareGate = valueTreeState.getRawParameterValue(snareGateParamID);
    hihatGate = valueTreeState.getRawParameterValue(hihatGateParamID);
    cowbellGate = valueTreeState.getRawParameterValue(cowbellGateParamID);

    kickColor = valueTreeState.getRawParameterValue(kickColorParamID);
    snareColor = valueTreeState.getRawParameterValue(snareColorParamID);
    hihatColor = valueTreeState.getRawParameterValue(hihatColorParamID);
    cowbellColor = valueTreeState.getRawParameterValue(cowbellColorParamID);

    kickDecay = valueTreeState.getRawParameterValue(kickDecayParamID);
    snareDecay = valueTreeState.getRawParameterValue(snareDecayParamID);
    hihatDecay = valueTreeState.getRawParameterValue(hihatDecayParamID);
    cowbellDecay = valueTreeState.getRawParameterValue(cowbellDecayParamID);

    kickNoise = valueTreeState.getRawParameterValue(kickNoiseParamID);
    snareNoise = valueTreeState.getRawParameterValue(snareNoiseParamID);
    hihatNoise = valueTreeState.getRawParameterValue(hihatNoiseParamID);

    kickDrive = valueTreeState.getRawParameterValue(kickDriveParamID);
    snareDrive = valueTreeState.getRawParameterValue(snareDriveParamID);
    hihatDrive = valueTreeState.getRawParameterValue(hihatDriveParamID);

    cowbellDetune = valueTreeState.getRawParameterValue(cowbellDetuneParamID);


    kickLevel = valueTreeState.getRawParameterValue(kickLevelParamID);
    snareLevel = valueTreeState.getRawParameterValue(snareLevelParamID);
    hihatLevel = valueTreeState.getRawParameterValue(hihatLevelParamID);
    cowbellLevel = valueTreeState.getRawParameterValue(cowbellLevelParamID);


    snareReverbSend = valueTreeState.getRawParameterValue(snareReverbSendParamID);
    hihatReverbSend = valueTreeState.getRawParameterValue(hihatReverbSendParamID);
    cowbellReverbSend = valueTreeState.getRawParameterValue(cowbellReverbSendParamID);

    snareDelaySend = valueTreeState.getRawParameterValue(snareDelaySendParamID);
    hihatDelaySend = valueTreeState.getRawParameterValue(hihatDelaySendParamID);
    cowbellDelaySend = valueTreeState.getRawParameterValue(cowbellDelaySendParamID);

    delayRatio = valueTreeState.getRawParameterValue(delayRatioParamID);
    delayFeedback = valueTreeState.getRawParameterValue(delayFeedbackParamID);

    compThreshold = valueTreeState.getRawParameterValue(compressorThresholdParamID);
    compAttack = valueTreeState.getRawParameterValue(compressorAttackParamID);
}

juce::AudioProcessorValueTreeState::ParameterLayout DSPParameters::makeLayout() {
    using namespace DSPParameterContants;

    juce::AudioProcessorValueTreeState::ParameterLayout layout;

    layout.add(std::make_unique<juce::AudioParameterBool>(kickGateParamID, gateParamName, false));
    layout.add(std::make_unique<juce::AudioParameterBool>(snareGateParamID, gateParamName, false));
    layout.add(std::make_unique<juce::AudioParameterBool>(hihatGateParamID, gateParamName, false));
    layout.add(std::make_unique<juce::AudioParameterBool>(cowbellGateParamID, gateParamName, false));

    layout.add(std::make_unique<juce::AudioParameterFloat>(kickColorParamID, colorParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(snareColorParamID, colorParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(hihatColorParamID, colorParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(cowbellColorParamID, colorParamName, 0, 1, 0));

    layout.add(std::make_unique<juce::AudioParameterFloat>(kickDecayParamID, decayParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(snareDecayParamID, decayParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(hihatDecayParamID, decayParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(cowbellDecayParamID, decayParamName, 0, 1, 0));

    layout.add(std::make_unique<juce::AudioParameterFloat>(kickNoiseParamID, noiseParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(snareNoiseParamID, noiseParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(hihatNoiseParamID, noiseParamName, 0, 1, 0));

    layout.add(std::make_unique<juce::AudioParameterFloat>(kickDriveParamID, driveParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(snareDriveParamID, driveParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(hihatDriveParamID, driveParamName, 0, 1, 0));

    layout.add(std::make_unique<juce::AudioParameterFloat>(cowbellDetuneParamID, detuneParamName, 0, 1, 0));


    layout.add(std::make_unique<juce::AudioParameterFloat>(kickLevelParamID, levelParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(snareLevelParamID, levelParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(hihatLevelParamID, levelParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(cowbellLevelParamID, levelParamName, 0, 1, 0));


    layout.add(std::make_unique<juce::AudioParameterFloat>(snareReverbSendParamID, reverbSendParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(hihatReverbSendParamID, reverbSendParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(cowbellReverbSendParamID, reverbSendParamName, 0, 1, 0));

    layout.add(std::make_unique<juce::AudioParameterFloat>(snareDelaySendParamID, delaySendParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(hihatDelaySendParamID, delaySendParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(cowbellDelaySendParamID, delaySendParamName, 0, 1, 0));

    layout.add(std::make_unique<juce::AudioParameterFloat>(delayRatioParamID, delayRatioParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(delayFeedbackParamID, delayFeedbackParamName, 0, 1, 0));

    layout.add(std::make_unique<juce::AudioParameterFloat>(compressorThresholdParamID, compressorThresholdParamName, 0, 1, 0));
    layout.add(std::make_unique<juce::AudioParameterFloat>(compressorAttackParamID, compressorAttackParamName, 0, 1, 0));

    return layout;
};