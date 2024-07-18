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

Vector Vector::Cross(Vector& A, Vector& B)
{
	Vector product;
	
	product.x = A.y * B.z - A.z * B.y;
	product.y = A.z * B.x - A.x * B.z;
	product.z = A.x * B.y - A.y * B.x;
	
	return product;
}
