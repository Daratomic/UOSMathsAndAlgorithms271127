#include "Maths.h"
#include <math.h>


constexpr float PI = 3.1415926536f;
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

float MathUtils::FindSinTheta(float opp, float adj)
{
    float hyp = Pythagoras(opp, adj);
    return opp / hyp;
}

float MathUtils::FindCosTheta(float opp, float adj)
{
    float hyp = Pythagoras(adj, opp);
    return adj / hyp;
}

float MathUtils::FindTanTheta(float opp, float adj)
{
    return opp / adj;
}

float MathUtils::FindHyp(float AngleDeg, float opp)
{
    float hyp = opp / sinf(toRad(AngleDeg));
    return hyp;
}

float MathUtils::FindOpp(float AngleDeg, float adj)
{
    float opp = adj * tanf(toRad(AngleDeg));
    return opp;
}

float MathUtils::FindAdj(float AngleDeg, float opp)
{
    float adj = opp / tanf(toRad(AngleDeg));
    return adj;
}
