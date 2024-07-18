#include "Matrix.h"
#include <math.h>

float Matrix::Determinate() // Determinant
{
	float a = Data[0][0];
	float b = Data[0][1];
	float c = Data[0][2];
	float d = Data[1][0];
	float e = Data[1][1];
	float f = Data[1][2];
	float g = Data[2][0];
	float h = Data[2][1];
	float i = Data[2][2];

	return (a * e * i
		+ b * f * g
		+ c * d * h
		- c * e * g
		- b * d * i
		- a * f * h);
}

void Matrix::SetRotateAroundX(float Angle)
{	
	// [row][col]
	Data[0][0] = 1;
	Data[0][1] = 0;
	Data[0][2] = 0;
	Data[1][0] = 0;
	Data[2][0] = 0;

	Data[1][1] = cosf(Angle);
	Data[1][2] = -sinf(Angle);
	Data[2][1] = sinf(Angle);
	Data[2][2] = cosf(Angle);
}

void Matrix::SetRotateAroundY(float Angle)
{
	// [row][col]
	Data[1][1] = 1;
	Data[0][1] = 0;
	Data[2][1] = 0;
	Data[1][0] = 0;
	Data[1][2] = 0;

	Data[0][0] = cosf(Angle);
	Data[0][2] = sinf(Angle);
	Data[2][0] = -sinf(Angle);
	Data[2][2] = cosf(Angle);
}

void Matrix::SetRotateAroundZ(float Angle)
{
	// [row][col]
	Data[2][2] = 1;
	Data[2][0] = 0;
	Data[2][1] = 0;
	Data[0][2] = 0;
	Data[1][2] = 0;

	Data[0][0] = cosf(Angle);
	Data[0][1] = -sinf(Angle);
	Data[1][0] = sinf(Angle);
	Data[1][1] = cosf(Angle);
}

Vector Matrix::RotateAroundX(Vector Point, float Angle)
{
	Matrix m;
	m.SetRotateAroundX(Angle);
	return m * Point;
}

Vector Matrix::RotateAroundY(Vector Point, float Angle)
{
	Matrix m;
	m.SetRotateAroundY(Angle);
	return m * Point;
}

Vector Matrix::RotateAroundZ(Vector Point, float Angle)
{
	Matrix m;
	m.SetRotateAroundZ(Angle);
	return m * Point;
}

Matrix Matrix::operator*(Matrix& RHS)
{
	Matrix& LHS = *this;
	Matrix ResultMat;

	for (int row = 0; row < 3; ++row) // row goes 0 to 2 (inclusive)
	{
		for (int col = 0; col < 3; ++col) // col goes 0 to 2 (inclusive)
		{
			ResultMat.Data[row][col] = 0; // init element to 0
			for (int i = 0; i < 3; i++) // step through row and col
			{
				ResultMat.Data[row][col] += LHS.Data[row][i] * RHS.Data[i][col]; // add product
			}
		}
	}

	return ResultMat;
}

Vector Matrix::operator*(Vector& RHS)
{
	Matrix& LHS = *this;
	Vector ResultVec;

	float vecArr[3];
	float rhsArr[3]{ RHS.x, RHS.y, RHS.z };

	for (int row = 0; row < 3; ++row) // row goes 0 to 2 (inclusive)
	{
		// only one column in Vector, no need for loop
		vecArr[row] = 0; // init element to 0
		for (int i = 0; i < 1; i++) // step through row
		{
			vecArr[row] += LHS.Data[row][i] * rhsArr[i]; // add product
		}
	}

	ResultVec.x = vecArr[0];
	ResultVec.x = vecArr[1];
	ResultVec.x = vecArr[2];

	return ResultVec;
}
