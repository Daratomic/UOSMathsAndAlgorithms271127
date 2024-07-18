#include "Vector.h"
#include <math.h>

float Vector::Magnitude()
{
	float magSqr = x * x + y * y + z * z;
	
	return sqrt(magSqr);
}

void Vector::Normalise()
{	
	float mag = Magnitude();
	float normx = x / mag;
	float normy = y / mag;
	float normz = z / mag;

	x = normx;
	y = normy;
	z = normz;
}

void Vector::Scale(float Scaler)
{
	float scaleX = x * Scaler;
	float scaleY = y * Scaler;
	float scaleZ = y * Scaler;

	x = scaleX;
	y = scaleY;
	z = scaleZ;
}

float Vector::Dot(Vector& B)
{
	float dot = x * B.x + y * B.y + z * B.z;
	return dot;
}

Vector Vector::Cross(Vector& B)
{
	Vector product;
	
	product.x = y * B.z - z * B.y;
	product.y = z * B.x - x * B.z;
	product.z = x * B.y - y * B.x;
	
	return product;
}
