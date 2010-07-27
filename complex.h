/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/
//! Expands complex<double> to provide phasor handling. 
#ifndef COMPLEX_H
#define COMPLEX_H

#include <complex>
using namespace std;

class Complex : public complex<double>
{/* TODO: Either remove or add test. 
public:
	void createPhasor(double r, double phi);*/
	
public:
	Complex();
	Complex(double _real, double _imag);
	
	//! Returns a Complex-number as specified by the phasor-coordinates. 
	//! @param r Absolute value
	//! @param phi Argument
	Complex createPhasor(double r, double phi);
	
	void setPhasor(double r, double phi);
};

#endif // COMPLEX_H
