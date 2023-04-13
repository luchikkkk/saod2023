#include <ostream>
#include <iostream>
#include <cmath>
#include "Complex.h"

using namespace std;

int main()
{
	Complex c;
	cout << c;

	Complex a(1, 2), b = 3;
	cout << a << ", " << b << endl;

	Complex array[4];
	int n = *(&array + 1) - array;
	int* pn = &n;
	for (int i = 0; i < *pn; i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "_________" << endl;

	Complex v[4]{ 1,2, Complex(2,3) };
	int m = *(&v + 1) - v;
	int* pm = &m;
	for (int i = 0; i < *pm; i++)
		cout << v[i] << " ";
	cout << endl;
	cout << "_________" << endl;

	Complex* pc = new Complex(1);
	cout << *pc << endl;
	delete pc;

	pc = new Complex;
	cout << *pc << endl;
	delete pc;

	pc = new Complex(1, 2);
	cout << *pc << endl;

	int re = pc->Re;
	cout << re << endl;
	re = pc->Im;
	cout << re << endl;
	
	
	cout << c;
	delete pc;
}

