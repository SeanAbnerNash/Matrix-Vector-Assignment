#include "Vector3.h"

double Vector3::getX()
{
	return m_x;
}

double Vector3::getY()
{
	return m_y;
}

double Vector3::getZ()
{
	return m_z;
}
std::string Vector3::toString()//Handles the toString Conversion
{
	char tmpbuf[256];
	sprintf_s(tmpbuf, "[ %g, %g, %g ]", m_x, m_y, m_z);
	return tmpbuf;
}

Vector3::Vector3()// Constructor 1 - Default Zero Vector
{	
		m_x = 0.0f;
		m_y = 0.0f;
		m_z = 0.0f;
}

Vector3::Vector3(double x1, double y1, double z1)	// Constructor 2 - To allow other values for X, Y and Z to be declared
{
		m_x = x1;
		m_y = y1;
		m_z = z1;
	
}

double Vector3::length()// A method to return the length of the vector
{
	  
		return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
	
}

double Vector3::lengthSquared()// A method to return the length squared of the vector
{
	  
		return (m_x * m_x + m_y * m_y + m_z * m_z);
	
}
 
void Vector3::normalise()// A method to reduce the length of the vector to 1.0 keeping the direction the same
{
		if (length() > 0.0)
		{  // Check for divide by zero
			double magnit = length();
			m_x /= magnit;
			m_y /= magnit;
			m_z /= magnit;
		}	
}

Vector3 Vector3::operator + (const Vector3 right) const //Each component must be added to the other similar component
{
	return Vector3(m_x + right.m_x, m_y + right.m_y, m_z + right.m_z); 
}



Vector3 Vector3::operator- (const Vector3 right) const
{
	return Vector3(m_x - right.m_x, m_y - right.m_y, m_z - right.m_z);//Each component must be taken to the other similar component
}

Vector3 Vector3::operator - ()
{
	std::cout << "Invert";
	return Vector3(-m_x,-m_y,-m_z);
}

Vector3 Vector3::operator*(const double scalar) const//Each component Must be multiplied by the Scalar
{
	return Vector3(m_x * scalar, m_y * scalar, m_z * scalar); 
}

double Vector3::operator*(const Vector3 right) const// An overloaded operator * to return the scalar product of 2 vectors
{
	return (m_x * right.m_x + m_y * right.m_y + m_z * right.m_z);
}

Vector3 Vector3::operator*(const float k) const
{
	return Vector3(m_x * k, m_y * k, m_z * k);
}

Vector3 Vector3::operator*(const int k) const
{
	return Vector3(m_x * k, m_y * k, m_z * k);
}

Vector3 Vector3::operator^(const Vector3 right) const// An overloaded operator ^ to return the vector product of 2 vectors
{
	return Vector3(m_y * right.m_z - m_z * right.m_y, m_z * right.m_x - m_x * right.m_z, m_x * right.m_y - m_y * right.m_x);
}

