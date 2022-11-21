/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "DrumEngine.h"

//==============================================================================
DrtydrumsAudioProcessor::DrtydrumsAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

DrtydrumsAudioProcessor::~DrtydrumsAudioProcessor()
{
}

//==============================================================================
const juce::String DrtydrumsAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DrtydrumsAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DrtydrumsAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool DrtydrumsAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double DrtydrumsAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DrtydrumsAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DrtydrumsAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DrtydrumsAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String DrtydrumsAudioProcessor::getProgramName (int index)
{
    return {};
}

void DrtydrumsAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void DrtydrumsAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
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

void DrtydrumsAudioProcessor::releaseResources()
{
    delete fDSP;
    delete fUI;
    for (int ch = 0; ch < 2; ++ch) {
        delete[] outputs[ch];
    }
    delete[] outputs;
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DrtydrumsAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void DrtydrumsAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    fDSP->compute(buffer.getNumSamples(), NULL, outputs);

    for (int channel = 0; channel < totalNumOutputChannels; ++channel) {
        for (int i = 0; i < buffer.getNumSamples(); i++) {
            *buffer.getWritePointer(channel, i) = outputs[channel][i];
        }
    }

    for (auto msg : midiMessages) {
        auto midiMsg = msg.getMessage();
        if (midiMsg.isNoteOn())
        {
            const int noteNum = midiMsg.getNoteNumber();

            switch (noteNum) {
            case 60:
                fUI->setParamValue("kk_gate", 1);
                break;
            case 61:
                fUI->setParamValue("snr_gate", 1);
                break;
            case 62:
                fUI->setParamValue("hh_gate", 1);
                break;
            case 63:
                fUI->setParamValue("cwbl_gate", 1);
                break;
            }
        }
        else if (midiMsg.isNoteOff()) {
            const int noteNum = midiMsg.getNoteNumber();

            switch (noteNum) {
            case 60:
                fUI->setParamValue("kk_gate", 0);
                break;
            case 61:
                fUI->setParamValue("snr_gate", 0);
                break;
            case 62:
                fUI->setParamValue("hh_gate", 0);
                break;
            case 63:
                fUI->setParamValue("cwbl_gate", 0);
                break;
            }
        }
    }
}

//==============================================================================
bool DrtydrumsAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* DrtydrumsAudioProcessor::createEditor()
{
    return new DrtydrumsAudioProcessorEditor (*this);
}

//==============================================================================
void DrtydrumsAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void DrtydrumsAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DrtydrumsAudioProcessor();
}
