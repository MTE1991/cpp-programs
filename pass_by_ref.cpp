#include <iostream>

using namespace std;

// Swap two numbers:
int swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

int main()
{
	int n1 = 9, n2 = 10;
	cout << "First number: " << n1 << " Second number: " << n2 << "\n";
	swap(n1, n2);
	cout << "First number: " << n1 << " Second number: " << n2 << "\n";
	return 0;
}
