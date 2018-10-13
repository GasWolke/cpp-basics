#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a, z1, z2;
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите значение: " << endl;
	cin >> a;
	z1 = cos(a) + sin(a) + cos(3 * a) + sin(3 * a);
	z2 = 2 * sqrt(2) * cos(a) * sin(M_PI_4 + 2 * a );
	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;
	return 0;
}