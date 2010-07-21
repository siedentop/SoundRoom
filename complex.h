/*
(c) 2010 Christoph Siedentop, <christophsiedentop@gmail.com
*/

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
	Complex(double _real, double _imag);
	Complex();
		
	
	virtual ~Complex();
	
	double real;
	double imag;
	
	Complex operator+(const Complex &arg);
	void operator+=(const Complex &arg);
};

#endif // COMPLEX_H
