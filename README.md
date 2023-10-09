# calebs-vst
This is a JUCE plugin written to test implementations of various digital signal filters written while reading Will Pirkle's book "Designing Audio Plugins in C++". The plugin can be compiled as a standalone, or as a VST3, AU, and AAX and run in an appropriate DAW.

All filters have been implemented from scratch by me, Caleb Fringer

# Building
- Install the JUCE framework from https://juce.com/download/
- Clone this repository and open calebs-vst.jucer in Projucer
- Select the format you wish to support from the "Plugin Formats" setting
- Under "Exporters", add an exporter for your respective build environment
- Select desired exporter from the "Selected Exporter" dropdown
- Click button showing icon of your IDE called "Save and Open in IDE"
- Build in IDE
- Open plugin in DAW
