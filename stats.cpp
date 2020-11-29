#include <iostream>
#include <cmath>
using namespace std;

template <typename T1>
T1 std_dev(T1 arr[], int size) {
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];

	double avg = sum / size;
	double var = 0;

	for (int i = 0; i < size; i++)
		var += pow(abs((arr[i] - avg)), 2) / size;

	return sqrt(var);
}
template <typename T2>
T2 mean_dev(T2 arr[], int size) {
	double sum = 0;

	for (int i = 0; i < size; i++)
		sum += arr[i];

	double avg = sum / size;
	double md = 0;

	for (int i = 0; i < size; i++)
		md += abs((arr[i] - avg)) / size;

	return md;
}

int main()
{
	double a[] = {45, 49, 51, 50, 46, 41, 39, 53};
	int n = sizeof(a) / sizeof(a[0]);

	cout << "Standard Deviation = " << printf("%.2f", std_dev<double>(a, n)) << endl;
	cout << "Mean Deviation = " << mean_dev<double>(a, n) << endl;

	return 0;
}