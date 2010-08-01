/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/
#include "complex.h"

#include <stdio.h>
#include <math.h>


Complex::Complex()
 : m_real(0.0), m_imag(0.0), complex<double>(0, 0)
{
}

Complex::Complex(double _real, double _imag)
 : m_real(_real), m_imag(_imag), complex<double>(_real, _imag)
{
}

Complex* Complex::createPhasor(double r, double phi)
{
	return new Complex(r * cos(phi), r * sin(phi));
}

Complex Complex::complement()
{
	return Complex(m_real, -m_imag);
}

double Complex::real()
{
	return m_real;
}

double Complex::imag()
{
	return m_imag;
}

double Complex::length()
{
	return sqrt(m_real * m_real + m_imag * m_imag);
}

void Complex::operator+=(const Complex &rhs)
{
	m_real += rhs.m_real;
	m_imag += rhs.m_imag;
}