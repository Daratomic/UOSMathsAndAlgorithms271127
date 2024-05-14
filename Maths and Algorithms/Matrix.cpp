#include "Matrix.h"
#include <math.h>

float Matrix::Determinate()
{
    return (Data[0][0] * Data[0][1] * Data[1][0] * Data[2][0]);
}

void Matrix::SetRotateAroundX(float Angle)
{

    xRotationData[1][1] = cos(Angle);
    xRotationData[1][2] = -sin(Angle);
    xRotationData[2][1] = sin(Angle);
    xRotationData[2][2] = cos(Angle);
}

void Matrix::SetRotateAroundY(float Angle)
{
    yRotationData[0][0] = cos(Angle);
    yRotationData[2][0] = sin(Angle);
    yRotationData[0][2] = -sin(Angle);
    yRotationData[2][2] = cos(Angle);
}

void Matrix::SetRotateAroundZ(float Angle)
{
    zRotationData[0][0] = cos(Angle);
    zRotationData[0][1] = sin(Angle);
    zRotationData[1][0] = -sin(Angle);
    zRotationData[1][1] = cos(Angle);
}

Vector Matrix::RotateAroundX(Vector Point, float Angle)
{
    float newX = (Point.x * xRotationData[0][0]) + (Point.y * xRotationData[1][0]) + (Point.z * xRotationData[2][0]);
    float newY = (Point.x * xRotationData[0][1]) + (Point.y * xRotationData[1][1]) + (Point.z * xRotationData[2][1]);
    float newZ = (Point.x * xRotationData[0][2]) + (Point.y * xRotationData[1][2]) + (Point.z * xRotationData[2][2]);
    
    Vector v;
    v.x = newX;
    v.y = newY;
    v.z = newZ;

    return v;
}

Vector Matrix::RotateAroundY(Vector Point, float Angle)
{
    float newX = (Point.x * yRotationData[0][0]) + (Point.y * yRotationData[1][0]) + (Point.z * yRotationData[2][0]);
    float newY = (Point.x * yRotationData[0][1]) + (Point.y * yRotationData[1][1]) + (Point.z * yRotationData[2][1]);
    float newZ = (Point.x * yRotationData[0][2]) + (Point.y * yRotationData[1][2]) + (Point.z * yRotationData[2][2]);

    Vector v;
    v.x = newX;
    v.y = newY;
    v.z = newZ;

    return v;
}

Vector Matrix::RotateAroundZ(Vector Point, float Angle)
{
    float newX = (Point.x * zRotationData[0][0]) + (Point.y * zRotationData[1][0]) + (Point.z * zRotationData[2][0]);
    float newY = (Point.x * zRotationData[0][1]) + (Point.y * zRotationData[1][1]) + (Point.z * zRotationData[2][1]);
    float newZ = (Point.x * zRotationData[0][2]) + (Point.y * zRotationData[1][2]) + (Point.z * zRotationData[2][2]);

    Vector v;
    v.x = newX;
    v.y = newY;
    v.z = newZ;

    return v;
}
