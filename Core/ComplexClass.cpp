#include <iostream>
#include <cmath>
#include "../Include/ComplexClass.h"

using namespace std;

Complex::Complex(double RealPart, double ImaginaryPart) {
	_RealPart = RealPart;
	_ImaginaryPart = ImaginaryPart;
}

Complex::Complex(const Complex& TemporaryComplex) {
	_RealPart = TemporaryComplex._RealPart;
	_ImaginaryPart = TemporaryComplex._ImaginaryPart;
}

Complex::~Complex() {
	_RealPart = 0.;
	_ImaginaryPart = 0.;
}

void Complex::SetComplex(double RealPart, double ImaginaryPart) {
	_RealPart = RealPart;
	_ImaginaryPart = ImaginaryPart;
}

Complex::operator double() {
	return abs();
}

double Complex::abs() {
	return sqrt(_RealPart * _RealPart + _ImaginaryPart * _ImaginaryPart);
}

Complex Complex::operator+ (const Complex& TemporaryComplex) {
	Complex Result;

	Result._RealPart = _RealPart + TemporaryComplex._RealPart;
	Result._ImaginaryPart = _ImaginaryPart + TemporaryComplex._ImaginaryPart;

	return Result;
}

Complex Complex::operator- (const Complex& TemporaryComplex) {
	Complex Result;

	Result._RealPart = _RealPart - TemporaryComplex._RealPart;
	Result._ImaginaryPart = _ImaginaryPart - TemporaryComplex._ImaginaryPart;

	return Result;
}

Complex Complex::operator+ (const double& RealPart) {
	Complex result;

	result._RealPart = _RealPart + RealPart;
	result._ImaginaryPart = _ImaginaryPart;

	return result;
}

Complex Complex::operator- (const double& RealPart) {
	Complex Result(*this);

	Result._RealPart = _RealPart - RealPart;

	return Result;
}

Complex Complex::operator* (const Complex& TemporaryComplex) {
	Complex Result;

	Result._RealPart = _RealPart * TemporaryComplex._RealPart - _ImaginaryPart * TemporaryComplex._ImaginaryPart;
	Result._ImaginaryPart = _RealPart * TemporaryComplex._ImaginaryPart + _ImaginaryPart * TemporaryComplex._RealPart;

	return Result;
}

Complex Complex::operator* (const double& ImaginaryPart) {
	Complex Result;

	Result._RealPart = _RealPart * ImaginaryPart;
	Result._ImaginaryPart = _ImaginaryPart * ImaginaryPart;

	return Result;
}

Complex Complex::operator/ (const double& Value) {
	Complex Result;

	Result._RealPart = _RealPart / Value;
	Result._ImaginaryPart = _ImaginaryPart / Value;

	return Result;
}

Complex& Complex::operator+= (const Complex& TemporaryComplex) {
	_RealPart += TemporaryComplex._RealPart;
	_ImaginaryPart += TemporaryComplex._ImaginaryPart;

	return *this;
}

Complex& Complex::operator-= (const Complex& TemporaryComplex) {
	_RealPart -= TemporaryComplex._RealPart;
	_ImaginaryPart -= TemporaryComplex._ImaginaryPart;
	
	return *this;
}

Complex& Complex::operator*= (const Complex& TemporaryComplex) {
	double TemporaryRealPart = _RealPart;

	_RealPart = _RealPart * TemporaryComplex._RealPart - _ImaginaryPart * TemporaryComplex._ImaginaryPart;
	_ImaginaryPart = _ImaginaryPart * TemporaryComplex._RealPart + TemporaryRealPart * TemporaryComplex._ImaginaryPart;
	
	return *this;
}

Complex& Complex::operator+= (const double& RealPart) {
	_RealPart += RealPart;

	return *this;
}

Complex& Complex::operator-= (const double& RealPart) {
	_RealPart -= RealPart;

	return *this;
}

Complex& Complex::operator*= (const double& Value) {
	_RealPart *= Value;
	_ImaginaryPart *= Value;
	
	return *this;
}

Complex& Complex::operator/= (const double& Value) {
	_RealPart /= Value;
	_ImaginaryPart /= Value;

	return *this;
}

Complex& Complex::operator= (const Complex& TemporaryComplex) {
	_RealPart = TemporaryComplex._RealPart;
	_ImaginaryPart = TemporaryComplex._ImaginaryPart;
	
	return *this;
}
Complex& Complex::operator= (const double& RealPart) {
	_RealPart = RealPart;
	_ImaginaryPart = 0.;
	
	return *this;
}

istream& operator>> (istream& Stream, Complex& TemporaryComplex) {
	char TemporaryBuffer[256];

	Stream
		>> TemporaryComplex._RealPart
		>> TemporaryComplex._ImaginaryPart >> TemporaryBuffer;

	return Stream;
}

ostream& operator<< (ostream& Stream, Complex& TemporaryComplex) {
	Stream << TemporaryComplex._RealPart;

	if (!(TemporaryComplex._ImaginaryPart < 0)) {
		Stream << '+';
	}
	
	Stream << TemporaryComplex._ImaginaryPart << 'i';
	
	return Stream;
}

Complex operator+ (const double& RealPart, const Complex& TemporaryComplex) {
	Complex Result;
	
	Result._RealPart = RealPart + TemporaryComplex._RealPart;
	Result._ImaginaryPart = TemporaryComplex._ImaginaryPart;

	return Result;
}

Complex operator- (const double& RealPart, const Complex& TemporaryComplex) {
	Complex Result;

	Result._RealPart = RealPart - TemporaryComplex._RealPart;
	Result._ImaginaryPart = -TemporaryComplex._ImaginaryPart;

	return Result;
}

Complex operator* (const double& Value, const Complex& TemporaryComplex) {
	Complex Result;

	Result._RealPart = Value * TemporaryComplex._RealPart;
	Result._ImaginaryPart = Value * TemporaryComplex._ImaginaryPart;

	return Result;
}
