/*
  ==============================================================================

    FirstOrderFeedforwardFilter.cpp
    Created: 8 Oct 2023 2:15:25pm
    Author:  Caleb

  ==============================================================================
*/

#include "FirstOrderFeedbackFilter.h"
FirstOrderFeedforwardFilter::FirstOrderFeedforwardFilter() : a1{ 0.5 }, a2{ 0.5 } {

};

FirstOrderFeedforwardFilter::FirstOrderFeedforwardFilter(float coeffs) : a1{ coeffs }, a2{ coeffs } {

};

FirstOrderFeedforwardFilter::FirstOrderFeedforwardFilter(float a1, float a2) : a1{ a1 }, a2{ a2 } {

};

float FirstOrderFeedforwardFilter::processSample(float z) {
    float out = a1 * z + a2 * prevSample;
    prevSample = z;
    return out;
}
