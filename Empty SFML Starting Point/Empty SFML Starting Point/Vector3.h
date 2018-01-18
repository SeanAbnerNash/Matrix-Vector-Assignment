#ifndef MYVECTOR3
#define MYVECTOR3
#include <iostream>
#include <SFML\Graphics.hpp>
	class Vector3
	{
	private:
		// The class has three variables x, y and z 
		double m_x;
		double m_y;
		double m_z;

	public:
		double getX();
		double getY();
		double getZ();

		// Constructor 1
		Vector3();
		// Constructor 2
		Vector3(double x1, double y1, double z1);
		double length();
		double lengthSquared();
		void normalise();
		Vector3 operator + (const Vector3 right) const; //Operator for +
		Vector3 operator- (const Vector3 right) const;//Operator for -
		Vector3 operator -(); //Operator for inverting Vectors
		Vector3 operator* (const double t_double) const;
		double operator* (const Vector3 t_vector) const;
		Vector3 operator* (const float t_float) const;
		Vector3 operator* (const int t_int) const;
		Vector3 operator^ (const Vector3 t_vector) const;
		std::string toString(); // String and operator declarations

	};
#endif