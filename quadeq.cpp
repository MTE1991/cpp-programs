#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

class QuadEq {
    public:
        double a = 0; // quadratic coefficient
        double b = 0; // linear coefficient
        double c = 0; // constant

        QuadEq(double A, double B, double C) {
            a = A;
            b = B;
            c = C;
        }

        void roots() {
            double d = b*b - 4*a*c; // discriminant
            float x1 = (-b + sqrt(d)) / (2*a);
        	float x2 = (-b - sqrt(d)) / (2*a);

            if (d > 0) {
                cout << "Two roots are " << x1 << " and " << x2 << endl;
		    } else if (d == 0) {
		        cout << "The only root is " << x1 << endl;
		    } else {
		    	float r = -b/(2*a); // real part
        		float i = sqrt(-d)/(2*a); // imaginary part
        		complex<float> complex_roots(r, i);
                
                cout << "Two complex roots are: \n";
		        cout << "x1 = " << real(complex_roots) << "+" << imag(complex_roots) << "i" << endl;
		        cout << "x2 = " << real(complex_roots) << "-" << imag(complex_roots) << "i" << endl; 
		    }
        }

        void discriminant() {
            cout << "discriminant = " << b*b - 4*a*c << endl;
        }
};

int main()
{
    QuadEq eq1(1, 4, 3);
    eq1.roots();
    eq1.discriminant();
    
    return 0;
}
