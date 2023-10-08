/*
  ==============================================================================

    FirstOrderFeedforwardFilter.h
    Created: 8 Oct 2023 2:15:25pm
    Author:  Caleb

  ==============================================================================
*/

#pragma once
class FirstOrderFeedforwardFilter {
public:
    FirstOrderFeedforwardFilter();
    FirstOrderFeedforwardFilter(float coeffs);
    FirstOrderFeedforwardFilter(float a1, float a2);
    float processSample(float z);
private:
    float prevSample;
    float a1, a2;
};
