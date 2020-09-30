#include <iostream>
#include <cmath>

using namespace std;

const float pi = 3.141592654;

// Create a class named Sphere:
class Sphere {
	public: // Access specifier
		double radius; // Attribute

	// Class methods:
	double area() {
		return 4 * pi * pow(radius, 2);
	}

	double volume() {
		return 4/3 * pi * pow(radius, 3);
	}
};

int main()
{
	Sphere s1;
	string choice;
	
	cout << "Enter the radius = ";
	cin >> s1.radius;

	cout << "Area or Volume? > ";
	cin >> choice;

	if (choice == "Area") {
		cout << "Area = " << s1.area();
	} else {
		cout << "Volume = " << s1.volume();
	}

	return 0;
}
