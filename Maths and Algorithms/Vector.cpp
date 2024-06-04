#include "Vector.h"
#include <math.h>

float Vector::Magnitude()
{
	float mag;

	mag = sqrt(x * x + y * y + z * z);
	
	return mag;
}

void Vector::Normalise()
{
	float mag;
	float normx;
	float normy;
	float normz;
	
	mag = Magnitude();
	normx = x / mag;
	normy = y / mag;
	normz = z / mag;

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
	float newX = x * B.x;
	float newY = y * B.y;
	float newZ = z * B.z;

	float topline = newX + newY + newZ;

	float magA = Magnitude();
	float magB = B.Magnitude();

	float costheta = topline / (magA * magB);
	
	return cosf(costheta);
}

Vector Vector::Cross(Vector& B, Vector& A)
{
	float cx = A.y * B.z - A.z * B.y;
	float cy = A.z * B.x - A.x * B.z;
	float cz = A.x * B.y - A.y * B.x;

	Vector product;
	product.x = cx;
	product.y = cy;
	product.z = cz;
	
	return product;
}
