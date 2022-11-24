/*
  ==============================================================================

    DrumEngineParameters.h
    Created: 22 Nov 2022 5:01:37pm
    Author:  ivtar

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

namespace DSPParameterContants {
	
	constexpr auto gateParamName = "gate";
	constexpr auto kickGateParamID = "kk_gate";
	constexpr auto snareGateParamID = "snr_gate";
	constexpr auto hihatGateParamID = "hh_gate";
	constexpr auto cowbellGateParamID = "cwbl_gate";
	
	constexpr auto freqParamName = "freq";
	constexpr auto kickFreqParamID = "kk_freq";
	constexpr auto snareFreqParamID = "snr_freq";
	constexpr auto hihatFreqParamID = "hh_freq";
	constexpr auto cowbellFreqParamID = "cwbl_freq";

	constexpr auto colorParamName = "color";
	constexpr auto kickColorParamID = "kk_color";
	constexpr auto snareColorParamID = "snr_color";
	constexpr auto hihatColorParamID = "hh_color";
	constexpr auto cowbellColorParamID = "cwbl_color";
	
	constexpr auto decayParamName = "decay";
	constexpr auto kickDecayParamID = "kk_decay";
	constexpr auto snareDecayParamID = "snr_decay";
	constexpr auto hihatDecayParamID = "hh_decay";
	constexpr auto cowbellDecayParamID = "cwbl_decay";

	constexpr auto noiseParamName = "noise";
	constexpr auto kickNoiseParamID = "kk_noise";
	constexpr auto snareNoiseParamID = "snr_noise";
	constexpr auto hihatNoiseParamID = "hh_noise";

	constexpr auto driveParamName = "drive";
	constexpr auto kickDriveParamID = "kk_drive";
	constexpr auto snareDriveParamID = "snr_drive";
	constexpr auto hihatDriveParamID = "hh_drive";

	constexpr auto detuneParamName = "detune";
	constexpr auto cowbellDetuneParamID = "cwbl_detune";

	constexpr auto levelParamName = "level";
	constexpr auto kickLevelParamID = "kk_lvl";
	constexpr auto snareLevelParamID = "snr_lvl";
	constexpr auto hihatLevelParamID = "hh_lvl";
	constexpr auto cowbellLevelParamID = "cwbl_lvl";

	constexpr auto reverbSendParamName = "reberb send";
	constexpr auto snareReverbSendParamID = "snr_rvb";
	constexpr auto hihatReverbSendParamID = "hh_rvb";
	constexpr auto cowbellReverbSendParamID = "cwbl_rvb";

	constexpr auto delaySendParamName = "delay send";
	constexpr auto snareDelaySendParamID = "snr_del";
	constexpr auto hihatDelaySendParamID = "hh_del";
	constexpr auto cowbellDelaySendParamID = "cwbl_del";

	constexpr auto delayRatioParamName = "delay ratio";
	constexpr auto delayRatioParamID = "del_ratio";

	constexpr auto delayFeedbackParamName = "delay feedback";
	constexpr auto delayFeedbackParamID = "del_fb";

	constexpr auto compressorThresholdParamName = "threshold";
	constexpr auto compressorThresholdParamID = "cmp_thrs";

	constexpr auto compressorAttackParamName = "attack";
	constexpr auto compressorAttackParamID = "cmp_att";
}

struct DSPParameters {
	std::atomic<float>* kickGate = nullptr;
	std::atomic<float>* snareGate = nullptr;
	std::atomic<float>* hihatGate = nullptr;
	std::atomic<float>* cowbellGate = nullptr;

	std::atomic<float>* kickFreq = nullptr;
	std::atomic<float>* snareFreq = nullptr;
	std::atomic<float>* hihatFreq = nullptr;
	std::atomic<float>* cowbellFreq = nullptr;

	std::atomic<float>* kickColor = nullptr;
	std::atomic<float>* snareColor = nullptr;
	std::atomic<float>* hihatColor = nullptr;
	std::atomic<float>* cowbellColor = nullptr;

	std::atomic<float>* kickDecay = nullptr;
	std::atomic<float>* snareDecay = nullptr;
	std::atomic<float>* hihatDecay = nullptr;
	std::atomic<float>* cowbellDecay = nullptr;

	std::atomic<float>* kickNoise = nullptr;
	std::atomic<float>* snareNoise = nullptr;
	std::atomic<float>* hihatNoise = nullptr;

	std::atomic<float>* kickDrive = nullptr;
	std::atomic<float>* snareDrive = nullptr;
	std::atomic<float>* hihatDrive = nullptr;

	std::atomic<float>* cowbellDetune = nullptr;

	std::atomic<float>* kickLevel = nullptr;
	std::atomic<float>* snareLevel = nullptr;
	std::atomic<float>* hihatLevel = nullptr;
	std::atomic<float>* cowbellLevel = nullptr;

	std::atomic<float>* snareReverbSend = nullptr;
	std::atomic<float>* hihatReverbSend = nullptr;
	std::atomic<float>* cowbellReverbSend = nullptr;

	std::atomic<float>* snareDelaySend = nullptr;
	std::atomic<float>* hihatDelaySend = nullptr;
	std::atomic<float>* cowbellDelaySend = nullptr;

	std::atomic<float>* delayRatio = nullptr;
	std::atomic<float>* delayFeedback = nullptr;

	std::atomic<float>* compThreshold = nullptr;
	std::atomic<float>* compAttack = nullptr;

	explicit DSPParameters(juce::AudioProcessorValueTreeState& valueTreeState);

	static juce::AudioProcessorValueTreeState::ParameterLayout makeLayout();
};
