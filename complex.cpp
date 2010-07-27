/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/
#include "complex.h"

#include <stdio.h>
#include <math.h>


Complex::Complex()
{
	complex<double>::complex(0.0, 0.0);
}

Complex::Complex(double _real, double _imag)
{
	complex<double>(_real, _imag);
}


//! TODO: This always fails. Complex isn't returned!
Complex Complex::createPhasor(double r, double phi)
{
	printf("R: %2.1f, Phi:%2.1f, real: %2.1f, imag: %2.1f \n", r, phi, r * cos(phi), r * sin(phi));
	return Complex(r * cos(phi), r * sin(phi));
}

void Complex::setPhasor(double r, double phi)
{
}