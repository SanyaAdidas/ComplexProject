#include <iostream>
#include "../Include/ComplexClass.h"

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

using namespace std;

int main() {
	Complex FirstComplex;
	Complex SecondComplex(-4);
	Complex ThirdComplex(23.0, 45.9);
	Complex FourthComplex = SecondComplex - ThirdComplex;
	Complex FifthComplex;

	cout << FirstComplex << ", " << SecondComplex << ", " << ThirdComplex << endl;

	FirstComplex = SecondComplex + ThirdComplex;

	cout << "FirstComplex = SecondComplex + ThirdComplex, FirstComplex = " << FirstComplex << endl;

	cout << "FourthComplex = SecondComplex - ThirdComplex, FourthComplex = " << FourthComplex << endl;
	cout << "FourthComplex * FirstComplex = " << (FourthComplex * FirstComplex) << endl;
	cout << "FourthComplex / 4.45 = " << (FourthComplex / 4.45) << endl;

	cout << "Enter complex number FifthComplex = ";
	cin >> FifthComplex;

	FirstComplex += ThirdComplex + FifthComplex;

	cout << "FifthComplex = " << FifthComplex << "\nFirstComplex = " << FirstComplex << endl;
	
	return EXIT_SUCCESS;
}
