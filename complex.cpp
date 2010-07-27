/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/
#include "complex.h"

#include <stdio.h>
#include <math.h>


Complex::Complex()
 : m_real(0.0), m_imag(0.0)
{
}

Complex::Complex(double _real, double _imag)
 : m_real(_real), m_imag(_imag)
{
}

Complex* Complex::createPhasor(double r, double phi)
{
	printf("R: %2.1f, Phi:%2.1f, real: %2.1f, imag: %2.1f \n", r, phi, r * cos(phi), r * sin(phi));
	return new Complex(r * cos(phi), r * sin(phi));
}


double Complex::real()
{
	return m_real;
}

double Complex::imag()
{
	return m_imag;
}