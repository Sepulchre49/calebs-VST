/*
  ==============================================================================

    Biquad.cpp
    Created: 8 Oct 2023 4:00:11pm
    Author:  Caleb

  ==============================================================================
*/

#include "Biquad.h"
Biquad::Biquad() :
    a0{ 1.0 }, a1{ 0.5 }, a2{ 0.5 }, b1{ 0.5 }, b2{ 0.5 }
{

}

Biquad::Biquad(double a0, double a1, double a2, double b1, double b2):
    a0{a0}, a1{a1}, a2{a2}, b1{b1}, b2{b2}
{
}

float Biquad::processSample(float z) 
{
    // Implemented using transposed-canonical form 
    double y = a0 * z + delay[0];
    delay[0] = a1 * z - b1 * y + delay[1];
    delay[1] = a2 * z - b2 * y;
    return (float)y;
}
