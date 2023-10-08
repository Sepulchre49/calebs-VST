/*
  ==============================================================================

    Biquad.h
    Created: 8 Oct 2023 4:00:11pm
    Author:  Caleb

  ==============================================================================
*/

#pragma once
class Biquad {
public:
    Biquad();
    Biquad(double a0, double a1, double a2, double b1, double b2);
    float processSample(float z);
private:
    double a0, a1, a2, b1, b2;
    double delay[2] = { 0.0, 0.0 };
};
