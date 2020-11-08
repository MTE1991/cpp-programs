#include <iostream>
using namespace std;

bool is_prime(int n) {
	bool flag = 1; // 1 means it's prime

	for (int i=2; i <= n/2; i++) {
		if (n % i == 0) {
			flag = 0;
			break;
		}
	}
	if (n == 1) {
		return 0; // 1 is neither prime nor composite
	} else {
		if (flag) {
			return 1;
		} else {
			return 0;
		}
	}
}

int main()
{
	int n, arr[n], prime = 0;
	cout << "How many numbers? :";
	cin >> n;
	cout << "Enter the numbers: \n";

	for (int i=0; i < n; i++)
		cin >> arr[i];
	for (int j=0; j < n; j++)
		if (is_prime(arr[j])) prime++;

	cout << "There are " << prime << " primes in the array. " << endl;
	return 0;
}