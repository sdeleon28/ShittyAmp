/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

//==============================================================================
/**
*/
class ShittyAmpAudioProcessorEditor  : public AudioProcessorEditor,
                                       public Slider::Listener,
                                       public ComboBox::Listener
{
public:
    ShittyAmpAudioProcessorEditor (ShittyAmpAudioProcessor&);
    ~ShittyAmpAudioProcessorEditor() override;

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider* slider) override;
    void comboBoxChanged (ComboBox* comboBox) override;
private:
    Label gainLabel;
    Slider gainSlider;
    std::unique_ptr<SliderAttachment> gainValue;

    Label outLevelLabel;
    Slider outLevelSlider;
    std::unique_ptr<SliderAttachment> outLevelValue;

    Label lowShelfGainLabel;
    Slider lowShelfGainSlider;
    std::unique_ptr<SliderAttachment> lowShelfGainValue;

    Label lowShelfFreqLabel;
    Slider lowShelfFreqSlider;
    std::unique_ptr<SliderAttachment> lowShelfFreqValue;

    Label waveshaperTypeLabel;
    ComboBox waveshaperTypeComboBox;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ShittyAmpAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ShittyAmpAudioProcessorEditor)
};
