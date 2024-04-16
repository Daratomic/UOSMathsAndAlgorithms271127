#include "Maths.h"
#include <math.h>


#define PI 3.14f
#define HalfCircle 180
float MathUtils::toRad(float Deg)
{
    float radian = Deg * PI / HalfCircle;

    return radian;
}

float MathUtils::toDeg(float Rad)
{
    float degrees = Rad * HalfCircle / PI;
    
    return degrees;
}

float MathUtils::Pythagoras(float A, float B)
{
    float c = (A * A) + (B * B);
    float h = sqrt(c);

    return h;
}

float MathUtils::FindSinTheta(float A, float B)
{
    float Theata = A / B;
    float SOH = asinf(Theata);
    float t = toDeg(SOH);
    return SOH;
}

float MathUtils::FindCosTheta(float A, float B)
{
    float Theata = A / B;
    float CAH = acosf(Theata);
    float t = toDeg(CAH);
    return CAH;
}

float MathUtils::FindTanTheta(float A, float B)
{
    float Theata = A / B;
    float TOA = atanf(Theata);
    float t = toDeg(TOA);
    return t;
}

float MathUtils::FindHyp(float Angle, float B)
{
    float hyp = B / sin(Angle);
    
    return hyp;
}

float MathUtils::FindOpp(float Angle, float B)
{
    float opp = B * sin(Angle);
    
    return opp;
}

float MathUtils::FindAdj(float Angle, float B)
{
    float adj = B / tan(Angle);
    
    return adj;
}
