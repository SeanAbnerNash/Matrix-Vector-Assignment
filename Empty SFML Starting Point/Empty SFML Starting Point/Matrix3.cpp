#include "Matrix3.h"

Matrix3::Matrix3()// Constructor 1 create a zero matrix
{
	
		A11 = 0.0;
		A12 = 0.0;
		A13 = 0.0;
		A21 = 0.0;
		A22 = 0.0;
		A23 = 0.0;
		A31 = 0.0;
		A32 = 0.0;
		A33 = 0.0;
	
}

Matrix3::Matrix3(Vector3 Row1, Vector3 Row2, Vector3 Row3)// To allow 3 rows of vectors to be declared as a matrix
{  
	A11 = Row1.getX();
	A12 = Row1.getY();
	A13 = Row1.getZ();

	A21 = Row2.getX();
	A22 = Row2.getY();
	A23 = Row2.getZ();

	A31 = Row3.getX();
	A32 = Row3.getY();
	A33 = Row3.getZ();
}

Matrix3::Matrix3(double t_A11, double t_A12, double t_A13, double t_A21, double t_A22, double t_A23, double t_A31, double t_A32, double t_A33)
{// to allow nine double values
	A11 = t_A11;
	A12 = t_A12;
	A13 = t_A13;

	A21 = t_A21;
	A22 = t_A22;
	A23 = t_A23;

	A31 = t_A31;
	A32 = t_A32;
	A33 = t_A33;
}

Vector3 Matrix3::operator*(Vector3 &right)// An overloaded operator * to return the  product of the matrix by a vector
{
	return Vector3(A11 * right.getX() + A12 * right.getY() + A13 * right.getZ(),
		A21 * right.getX() + A22 * right.getY() + A23 * right.getZ(),
		A31 * right.getX() + A32 * right.getY() + A33 * right.getZ());
}

Matrix3 Matrix3::Transpose(Matrix3 M1)// a method to transpose a given matrix
{
	return  Matrix3(M1.A11, M1.A21, M1.A31,
		M1.A12, M1.A22, M1.A32,
		M1.A13, M1.A23, M1.A33);
}

Matrix3 Matrix3::operator+(Matrix3 M2)// An overloaded operator + to return the  sum of two matrix 
{
	return  Matrix3(A11 + M2.A11, A12 + M2.A12, A13 + M2.A13,
		A21 + M2.A21, A22 + M2.A22, A23 + M2.A23,
		A31 + M2.A31, A32 + M2.A32, A33 + M2.A33);
}
Matrix3 Matrix3::operator -(Matrix3 M2)// An overloaded operator * to return the  difference of two matrix
{
	return  Matrix3(A11 - M2.A11, A12 - M2.A12, A13 - M2.A13,
		A21 - M2.A21, A22 - M2.A22, A23 - M2.A23,
		A31 - M2.A31, A32 - M2.A32, A33 - M2.A33);
}
Matrix3 Matrix3::operator*(double x)// An overloaded operator * to return the  product of the matrix by a scalar
{
	Matrix3 answer = Matrix3();
	A11 = A11 * x;
	A12 = A12 * x;
	A13 = A13 * x;

	A21 = A21 * x;
	A22 = A22 * x;
	A23 = A23 * x;

	A31 = A31 * x;
	A32 = A32 * x;
	A33 = A33 * x; 

	return answer;
}

Matrix3 Matrix3::operator*(Matrix3 M2)// An overloaded operator * to return the  product of two matrix
{
	Matrix3 answer = Matrix3();
	answer.A11 = Row(0) * M2.Column(0);
	answer.A12 = Row(0) * M2.Column(1);
	answer.A13 = Row(0) * M2.Column(2);

	answer.A21 = Row(1) * M2.Column(0);
	answer.A22 = Row(1) * M2.Column(1);
	answer.A23 = Row(1) * M2.Column(2);

	answer.A31 = Row(2) * M2.Column(0);
	answer.A32 = Row(2) * M2.Column(1);
	answer.A33 = Row(2) * M2.Column(2);


	return answer;
}

double Matrix3::Determinant()// method to return the determinant of a 3x3 matrix
{
 //                     aei      -     ahf                  + dhc                     - gec                      +    gbh                    -     dbi   
	return A11 * A22 * A33 - A11 * A32 * A23 + A21 * A32 * A13 - A31 * A22 * A13 + A31 * A12 * A23 - A21 * A12 * A33;
}

Vector3 Matrix3::Row(int i)// a method to return as Row as vector3 0 == first row, default == first row
{
	
	switch (i)
	{
	case 0:
		return  Vector3(A11, A12, A13);
	case 1:
		return  Vector3(A21, A22, A23);
	case 2:
		return  Vector3(A31, A32, A33);
	default:
		return  Vector3(A11, A12, A13);
	}
}

Vector3 Matrix3::Column(int i)// a method to return as column as vector3 0 == first column, default == first column
{
	switch (i)
	{
	case 0:
		return  Vector3(A11, A21, A31);
	case 1:
		return  Vector3(A12, A22, A32);
	case 2:
		return  Vector3(A13, A23, A33);
	default:
		return  Vector3(A11, A21, A31);
	}
}

Matrix3 Matrix3::Inverse()// method to return the inverse of a matrix if exists else zero vector
{
	
	double det = Determinant();
	if (det == 0)
		return  Matrix3();
	else
	{
		double scale = 1 / det;
		Matrix3 answer = Matrix3();
		answer.A11 = scale * (A22 * A33 - A23 * A32); // ei-fh
		answer.A12 = scale * (A13 * A32 - A12 * A33); // ch-bi
		answer.A13 = scale * (A12 * A23 - A13 * A22); // ch-bi

		answer.A21 = scale * (A23 * A31 - A21 * A33); // fg-di
		answer.A22 = scale * (A11 * A33 - A13 * A31); // ai-cg
		answer.A23 = scale * (A13 * A21 - A11 * A23); // cd-af


		answer.A31 = scale * (A21 * A32 - A22 * A31); // dh-eg
		answer.A32 = scale * (A12 * A31 - A11 * A32); // bg-ah
		answer.A33 = scale * (A11 * A22 - A12 * A21); // ae-bd

		return answer;
	}

}

Matrix3 Matrix3::Rotation(int _angle)
{
	double radians = PI / 180 * _angle;
	Matrix3 answer = Matrix3();
	answer.A11 = cos(radians);
	answer.A12 = sin(radians);
	answer.A13 = 0;
	answer.A21 = -sin(radians);
	answer.A22 = cos(radians);
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::Translate(int dx, int dy)
{
	Matrix3 answer = Matrix3();
	answer.A11 = 1;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = 1;
	answer.A23 = 0;
	answer.A31 = dx;
	answer.A32 = dy;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::Scale(int dx, int dy)
{
	Matrix3 answer = Matrix3();
	answer.A11 = (double)dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = (double)dy / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::RotationX(int _angle)
{
	double radians = PI / 180 * _angle;
	Matrix3 answer = Matrix3();
	answer.A11 = 1;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = cos(radians);
	answer.A23 = -sin(radians);
	answer.A31 = 0;
	answer.A32 = sin(radians);
	answer.A33 = cos(radians);

	return answer;
}

Matrix3 Matrix3::RotationY(int _angle)
{
	double radians = PI / 180 * _angle;
	Matrix3 answer = Matrix3();
	answer.A11 = cos(radians);
	answer.A12 = 0;
	answer.A13 = sin(radians);
	answer.A21 = 0;
	answer.A22 = 1;
	answer.A23 = 0;
	answer.A31 = -sin(radians);
	answer.A32 = 0;
	answer.A33 = cos(radians);

	return answer;
}

Matrix3 Matrix3::RotationZ(int _angle)
{
	double radians = PI / 180 * _angle;
	Matrix3 answer = Matrix3();
	answer.A11 = cos(radians);
	answer.A12 = -sin(radians);
	answer.A13 = 0;
	answer.A21 = sin(radians);
	answer.A22 = cos(radians);
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::Scale3D(double dx)
{
	Matrix3 answer = Matrix3();
	answer.A11 = dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = dx / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = dx / 100;

	return answer;
}
