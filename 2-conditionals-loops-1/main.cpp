#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	double a, b, c, Xn, Xk, dX, x, F;
	cout << "Enter a value a, b, c, Xn, Xk, dX: " << endl;
	cin >> a >> b >> c >> Xn >> Xk >> dX;
	if (dX > 0) 
	{
		cout << string(45, '-') << endl;
		cout << "|" << string(10, ' ') << "X" << string(10, ' ') << "|" << string(10, ' ') << "F" << string(10, ' ') << "|" << endl;
		cout << string(45, '-') << endl;
		x = Xn;
		while (x <= Xk) 
		{
			if ((x + 5 < 0 && c == 0) and x !=0)
			{
				F = (1 / (a * x)) - b;
			}
			else
			{
				if ((x + 5 > 0 && c != 0) and x != 0)
				{
					F = (x - a) / x;
				}
				else
				{
					if (c != 4)
					{
						F = 10 * x / (c - 4);
					}
					else
					{
						cout << "|" << setw(11) << x << setw(11) << "|" << setw(11) << "-" << setw(11) << "|" << endl;
						goto err;
					}
				}
			}
			if ((((int)a & (int)b) | ((int)b & (int)c)) == 0)
			{
				cout << "|" << setw(11) << x << setw(11) << "|" << setw(11) << (int)F << setw(11) << "|" << endl;
			}
			else
			{
				cout << "|" << setw(11) << x << setw(11) << "|" << setw(11) << F << setw(11) << "|" << endl;
			}
			err:
			x += dX;
		}
		cout << string(45, '-') << endl;
	}
	else 
	{
		cout << "Inncorect value of dX.";
	}
	return 0;
}


