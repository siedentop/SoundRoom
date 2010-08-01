/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/
//! Expands complex<double> to provide phasor handling. 
#ifndef COMPLEX_H
#define COMPLEX_H

#include <complex>
using namespace std;

class Complex  : public complex<double> // TODO what to do about this?
{
public:
	Complex();
	Complex(double _real, double _imag);
	
	//! Returns a Complex-number as specified by the phasor-coordinates. 
	//! @param r Absolute value
	//! @param phi Argument
	static Complex *createPhasor(double r, double phi);
	
	//! Returns real part of complex number
	double real();
	//! Returns imaginary part of complex number
	double imag();
	
	//! Returns complement
	Complex complement(); //TODO: Doesn't work. but test doesn't fail!
	
	//! Returns the length of the vector.
	double length();
	
	
	void operator+=(const Complex &arg);
	
protected: 
	double m_real;
	double m_imag;
};

#endif // COMPLEX_H
