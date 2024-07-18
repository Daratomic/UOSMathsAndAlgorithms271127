#include "Maths.h"
#include <math.h>


constexpr float PI = 3.14f;
constexpr float HalfCircle = 180.0f;

float MathUtils::toRad(float Deg)
{
    return Deg * PI / HalfCircle;
}

float MathUtils::toDeg(float Rad)
{
    return Rad * HalfCircle / PI;
}

float MathUtils::Pythagoras(float A, float B)
{
    float cSquared = A * A + B * B;
    return sqrtf(cSquared);
}

float MathUtils::FindSinTheta(float opp, float hyp)
{
    float sinVal = opp / hyp;
    float theta = asinf(sinVal); // SOH
    return theta;
}

float MathUtils::FindCosTheta(float adj, float hyp)
{
    float cosVal = adj / hyp;
    float theta = acosf(cosVal); // CAH
    return theta;
}

float MathUtils::FindTanTheta(float opp, float adj)
{
    float tanVal = opp / adj;
    float theta = atanf(tanVal); // TOA
    return theta;
}

float MathUtils::FindHyp(float Angle, float opp)
{
    float hyp = opp / sinf(Angle);
    return hyp;
}

float MathUtils::FindOpp(float Angle, float hyp)
{
    float opp = hyp * sinf(Angle);   
    return opp;
}

float MathUtils::FindAdj(float Angle, float opp)
{
    float adj = opp / tanf(Angle);
    return adj;
}
