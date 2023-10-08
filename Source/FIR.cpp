/*
  ==============================================================================

    FIR.cpp
    Created: 8 Oct 2023 2:15:25pm
    Author:  Caleb

  ==============================================================================
*/

#include "FIR.h"
FIR::FIR() : a1{ 0.5 }, a2{ 0.5 } {

};

FIR::FIR(float coeffs) : a1{ coeffs }, a2{ coeffs } {

};

FIR::FIR(float a1, float a2) : a1{ a1 }, a2{ a2 } {

};

float FIR::process_sample(float z) {
    float out = a1 * z + a2 * prevSample;
    prevSample = z;
    return out;
}
