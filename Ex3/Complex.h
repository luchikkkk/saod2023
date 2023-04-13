#include <ostream>
using namespace std;
#pragma once
class Complex
{
public:
	double Re, Im;
	Complex() { Re = 0; Im = 0; }
	Complex(double re) : Re(re), Im(0) {}
	Complex(double re, double im) : Re(re), Im(im) {}

	Complex operator +(const Complex& c)const
	{
		return Complex(Re + c.Re, Im + c.Im);
	}
	
	Complex operator -(const Complex& c)const
	{
		return Complex(Re - c.Re, Im - c.Im);
	}

	Complex operator *(const Complex& c)const
	{
		return Complex(Re * c.Re - Im *c.Im, Re * c.Im + c.Re * c.Im);
	}

	Complex operator /(const Complex& c)const
	{
		return Complex(Re + c.Re, Im + c.Im);
	}



};

inline ostream &operator << (ostream &o, const Complex& c)
{
	return o << '(' << c.Re << ", " << c.Im << ')';
}