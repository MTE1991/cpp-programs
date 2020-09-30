#include <iostream>

using namespace std;

// Overloading add() function:
int add(int x, int y);
double add(double x, double y);

int main()
{
	int a = 10, b = 12;
	double c = 2e5, d = 2.432e4;

	// Add both int and double numbers w/ same function:
	cout << a << "+" << b << "=" << add(a, b);
	cout << c << "+" << d << "=" << add(c, d);

	return 0;
}

int add(int x, int y) {
	return x + y;
}

double add(double x, double y) {
	return x + y;
}