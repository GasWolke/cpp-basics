#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

double Body(double xn, double Eps, int n, const int MaxIter)
{
	double f = 0;
	double fp = 1;
	while (abs(fp) > Eps)
	{
		f += fp;
		fp = pow((-1), n) * pow(xn, n) / (tgamma(n + 1));
		n++;
		if (n > MaxIter)
		{
			break;
		}
	}
	return f;
}

void Conclusion(double xn, double f, int n, const int MaxIter)
{
	cout << "|" << setw(12) << xn << setw(7) << "|" << setw(15);
	if (n < MaxIter)
	{
		cout << f << setw(7) << "|";
	}
	else
	{
		cout << "    small eps  " << setw(7) << "|";
	}
	cout << setw(17) << exp(-xn) << setw(7) << "|" << setw(7) << n << setw(7) << "|" << endl;
}


int main()
{
	const int MaxIter = 500;

	double xn, xk, dx, Eps;
	int n;

	cout << "Enter a value xn, xk, dx, Eps: " << endl;
	cin >> xn >> xk >> dx >> Eps;

	if (dx <= 0)
	{
		cout << "Incorrect value dx ";
	}
	else if (Eps <= 0) {
		cout << "Incorrect value Eps ";
	}
	else if (xn > xk) {
		cout << "Incorrect value xk ";
	}
	else
	{

		cout << string(80, '-') << endl;
		cout << "|         x        |" << "         F(x)        " << "|          e^(-x)       |" << " Iterations  | " << endl;;
		cout << string(80, '-') << endl;
		cout << fixed;
		cout.precision(6);

		for (xn; xn <= xk; xn += dx)
		{
			n = 1;
			double f = Body(xn, Eps, n, MaxIter);
			Conclusion(xn, f, n, MaxIter);
		}
		cout << string(80, '-') << endl;
		return 0;
	}
}