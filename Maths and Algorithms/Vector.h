#pragma once
class Vector
{
public:
	Vector() = default;

	Vector(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	float x, y, z;
	float Magnitude();

	void Normalise();

	void Scale(float Scaler);

	float Dot(Vector& B);
	Vector Cross(Vector& B);

};

