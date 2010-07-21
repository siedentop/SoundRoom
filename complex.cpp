/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/
#include <stdio.h>
#include "complex.h"

Complex::Complex(double _real, double _imag)
	 : real(_real), imag(_imag) 
{
	printf("Created\n");
}


Complex::Complex()
 : real(0.0), imag(0.0)
{
	printf("Foo\n");
}

Complex::~Complex()
{}


Complex Complex::operator+(const Complex &a)
{
	return Complex(a.real + real, a.imag + imag);
}

void Complex::operator+=(const Complex &rhs)
{
	real += rhs.real;
	imag += rhs.imag;
}
