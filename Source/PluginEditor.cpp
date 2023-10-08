/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CalebsvstAudioProcessorEditor::CalebsvstAudioProcessorEditor (CalebsvstAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    gainSlider.setSliderStyle(juce::Slider::LinearVertical);
    gainSlider.setRange(-60.0, 6.0);
    gainSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    gainSlider.setPopupDisplayEnabled(true, false, this);
    gainSlider.setTextValueSuffix(" dB");
    gainSlider.setValue(1.0);
    gainSlider.onValueChange = [this] {
        audioProcessor.gain = pow(10, gainSlider.getValue() / 20);
    };

    addAndMakeVisible(&gainSlider);

    muteButton.setButtonText("Mute");
    muteButton.onClick = [this] {
        audioProcessor.muted = muteButton.getToggleState() ? 0.0 : 1.0;
    };
    
    addAndMakeVisible(&muteButton);

    toggleLPFButton.setButtonText("LPF");
    toggleLPFButton.onClick = [this] {
        audioProcessor.toggleLPF = toggleLPFButton.getToggleState();
    };

    addAndMakeVisible(&toggleLPFButton);

    toggleBiquadButton.setButtonText("Biquad");
    toggleBiquadButton.onClick = [this] {
        audioProcessor.toggleBiquad = toggleBiquadButton.getToggleState();
    };

    addAndMakeVisible(&toggleBiquadButton);
}

CalebsvstAudioProcessorEditor::~CalebsvstAudioProcessorEditor()
{
}

//==============================================================================
void CalebsvstAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Caleb's VSTf", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void CalebsvstAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(40, 30, 50, getHeight() - 60);
    muteButton.setBounds(160, 30, 100, getHeight() - 50);
    toggleLPFButton.setBounds(160, 50, 100, getHeight() - 50);
    toggleBiquadButton.setBounds(160, 70, 100, getHeight() - 50);
}
