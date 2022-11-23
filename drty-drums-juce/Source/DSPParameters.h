/*
  ==============================================================================

    DrumEngineParameters.h
    Created: 22 Nov 2022 5:01:37pm
    Author:  ivtar

  ==============================================================================
*/

#pragma once
namespace DSPParameters {
	// gates
	const auto kick_gate = "kk_gate";
	const auto snare_gate = "snr_gate";
	const auto hihat_gate = "hh_gate";
	const auto cowbell_gate = "cwbl_gate";

	// frequencies 
	const auto kick_frequency = "kk_freq";
	const auto snare_frequency = "snr_freq";
	const auto hihat_frequency = "hh_freq";
	const auto cowbell_frequency = "cwbl_freq";

	// kick macro parameters
	const auto kick_color = "kk_color";
	const auto kick_decay = "kk_decay";
	const auto kick_noise = "kk_noiseMod";
	const auto kick_drive = "kk_drive";

	// snare macro parameters
	const auto snare_color = "snr_color";
	const auto snare_decay = "snr_dec";
	const auto snare_noise = "snr_noiseMod";
	const auto snare_drive = "snr_drive";

	// hihat macro parameters
	const auto hihat_color = "hh_color";
	const auto hihat_decay = "hh_decay";
	const auto hihat_noise = "hh_noiseMod";
	const auto hihat_drive = "hh_drive";

	// cowbell macro parameters
	const auto cowbell_color = "cwbl_color";
	const auto cowbell_decay = "cwbl_decay";
	const auto cowbell_detune = "cwbl_detune";


	// mixer levels 
	const auto kick_level = "kk_lvl";
	const auto snare_level = "snr_lvl";
	const auto hihat_level = "hh_lvl";
	const auto cowbell_level = "cwbl_lvl";

	// reverb sends
	const auto snare_reverb = "snr_rvb";
	const auto hihat_reverb = "hh_rvb";
	const auto cowbell_reverb = "cwbl_rvb";

	// delay sends
	const auto snare_delay = "snr_del";
	const auto hihat_delay = "hh_del";
	const auto cowbell_delay = "cwbl_del";

	// delay parameters
	const auto delay_period = "delay";
	const auto delay_feedback = "feedback";

	// master compressor
	const auto compressor_threshold = "cmp_thrs";
	const auto compressor_attack = "cmp_att";
}

enum DrumVoices {
	KICK,
	SNARE,
	HIHAT,
	COWBELL
};
