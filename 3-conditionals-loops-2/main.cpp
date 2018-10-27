#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	const int MaxIter = 500;

	double xn, xk, dx, Eps, f, fp;
	int n;

	cout << "Enter a value xn, xk, dx, Eps: " << endl;
	cin >> xn >> xk >> dx >> Eps;
	cout << string(80, '-') << endl;
	cout << "|         x        |" << "         F(x)        " << "|          e^(-x)       |" << " Iterations  | " << endl;;
	cout << string(80, '-') << endl;
	cout << fixed;
	cout.precision(9);

	for (xn; xn <= xk; xn += dx) 
	{
		f = 0;
		n = 1;
		fp = 1;
		while (abs(fp) > Eps) 
		{
			f += fp;
			fp = pow((-1),n) * pow(xn, n) / (tgamma(n + 1));
			n++;
			if (n > MaxIter) 
			{
				break;
			}
		}

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
	cout << string(80, '-') << endl;
	return 0;
}