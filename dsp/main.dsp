import("stdfaust.lib");
drm = library("fmdrum.lib");
mx = library("fxblock.lib");

kk_freq = hslider("kk_freq[style:knob]", 60, 40, 10000, 0.001) - 220, 40 : max;
kk_gate = button("[1]kk_gate");

snr_freq = hslider("snr_freq[style:knob]", 60, 40, 10000, 0.001) - 220, 40 : max;
snr_gate = button("[1]snr_gate");

hh_freq = hslider("hh_freq[style:knob]", 1300, 40, 10000, 0.001) - 220, 40 : max;
hh_gate = button("[1]hh_gate");

cwbl_freq = hslider("cwbl_freq[style:knob]", 800, 40, 10000, 0.001) - 220, 40 : max;
cwbl_gate = button("[1]cwbl_gate");

drums = hgroup("drums", vgroup("[0]kick", (kk_freq, kk_gate : drm.kk)),
                        vgroup("[1]snare", (snr_freq, snr_gate : drm.snr)), 
                        vgroup("[2]hh", (hh_freq, hh_gate : drm.hh)),
                        vgroup("[3]cwbl", (cwbl_freq, cwbl_gate : drm.cwbl)));

process = drums : mx.soundPipe <: _,_ ;