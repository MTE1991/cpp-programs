#include <iostream>

using namespace std;

class Person {
    public:
        string fname;
        string lname;
        int age;
        float height;
        float weight;

        Person(string f, string l, int a, float h, float w) {
            fname = f;
            lname = l;
            age = a;
            height = h;
            weight = w;
        };

        void get_info() {
            cout << "Name: " << fname << " " << lname << endl;
            cout << "Age: " << age << "yrs" << endl;
            cout << "Height: " << height << "m" << endl;
            cout << "Weight: " << weight << "kg" << endl;
        }
};

class Student : public Person {
    public:
        string institute;
        string exams[3] = {"JSC", "SSC", "HSC"};
        float gpa[3];

        Student(string f, string l, int a, float h, float w, string ins) : Person(f,l,a,h,w), institute(ins) {
        };

        void set_gpa() {
            cout << "Enter grades: \n";

            for (int i=0; i < 3; i++) {
                cin >> gpa[i];
            }
        }

        void more_info() {
            cout << "Institute: " << institute << endl;
            cout << "Educational Qualifications: \n";
            for (int i=0; i < 3; i++) {
                cout << exams[i] << ": " << "GPA " << gpa[i] << endl;
            }
        }
    };

int main(void)
{
    Person p1("MT", "Ekleel", 18, 1.61, 47);
    p1.get_info();

    Student p2("MT", "Ekleel", 18, 1.61, 47, "EUSC");
    p2.set_gpa();
    p2.more_info();
    return 0;
}
