# Drty Drums

4 voice drum machine based on FM synthesis.

The sound engine is made in faust dsl.

I'm planning to turn this into an opensource drum machine vst with JUCE and native iPad app using audiokit

## Roadmap:
- [x] Faust
  - [x] basic sound engine with macro parameters
  - [x] mixer
  - [x] fx chain
- [ ] JUCE app/vst3
  - [x] integrate faust engine
  - [ ] responsive ui
  - [ ] midi to separate channels
  - [ ] midi learn
  - [ ] preset manager
- [ ] port to iOS using SwiftUI + AudioKit 
