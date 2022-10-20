#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>

using namespace std;

class Complex {
	private:
		double _RealPart;
		double _ImaginaryPart;

	public:
		Complex(double aRe = 0, double aIm = 0);
		Complex(const Complex&);
		~Complex();

		void SetComplex(double aRe, double aIm = 0);
		operator double();
		double abs();

		friend istream& operator>> (istream&, Complex&);
		friend ostream& operator<< (ostream&, Complex&);
		friend Complex operator+ (const double&, const Complex&);
		friend Complex operator- (const double&, const Complex&);
		friend Complex operator* (const double&, const Complex&);

		Complex operator+ (const Complex&);
		Complex operator- (const Complex&);
		Complex operator+ (const double&);
		Complex operator- (const double&);
		Complex operator* (const Complex&);
		Complex operator* (const double&);
		Complex operator/ (const double&);
		Complex& operator+= (const Complex&);
		Complex& operator-= (const Complex&);
		Complex& operator*= (const Complex&);
		Complex& operator+= (const double&);
		Complex& operator-= (const double&);
		Complex& operator*= (const double&);
		Complex& operator/= (const double&);
		Complex& operator= (const Complex&);
		Complex& operator= (const double&);
};
#endif
