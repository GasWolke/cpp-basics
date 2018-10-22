#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	const double kEps = 1e-15;

	double a, b, c, xn, xk, dx;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
	cout << "Enter xn: ";
	cin >> xn;
	cout << "Enter xk >= xn: ";
	cin >> xk;
	cout << "Enter dx > 0: ";
	cin >> dx;

	if (dx <= 0) {
		cout << "\nInvalid dx. Must be: dx > 0.\n";
	}
	else if (xn > xk) {
		cout << "\nInvalid xk. Must be: xk >= xn.\n";
	}
	else {
		cout << string(33, '-') << endl;
		cout << "|       x       |       F       |\n";
		cout << string(33, '-') << endl;

		cout << fixed;
		cout.precision(3);

		double x = xn;
		while (x <= xk) {
			cout << "|" << setw(10) << x << setw(6) << "|";

			double f;
			if ((x + 5) < 0 && abs(c) < kEps) {
				if (abs(a * x) < kEps) {
					cout << " division by 0 |\n";
					x += dx;
					continue;
				}
				else {
					f = 1 / (a * x) - b;
				}
			}
			else if ((x + 5) > 0 && abs(c) >= kEps) {
				if (abs(x) < kEps) {
					cout << " division by 0 |\n";
					x += dx;
					continue;
				}
				else {
					f = (x - a) / x;
				}
			}
			else {
				if (abs(c - 4) < kEps) {
					cout << " division by 0 |\n";
					x += dx;
					continue;
				}
				else {
					f = 10 * x / (c - 4);
				}
			}

			int ac = static_cast<int>(a);
			int bc = static_cast<int>(b);
			int cc = static_cast<int>(c);
			if ((ac & bc) | (bc & cc))
				cout << setw(10) << f << setw(7);
			else
				cout << setw(8) << static_cast<int>(f) << setw(9);
			cout << "|\n";

			x += dx;
		}
		cout << string(33, '-');
	}

	return 0;
}