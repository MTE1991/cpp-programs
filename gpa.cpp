// GPA Calculator ver 1.02

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

class Student {
	int marks[7];
	vector<double> grades;

public:
	string name;
	string ins;
	int roll;
	void set_marks(void); // input marks
	double get_avg(void); // return average marks
	double get_gpa(void); // return gpa
};

int main() {
	Student s1;
	s1.name = "MT Ekleel";
	s1.roll = 116;
	s1.ins = "EUSC";

	cout << s1.name << endl;
	cout << s1.ins << endl;
	cout << s1.roll << endl << endl;

	s1.set_marks(); 
	cout << "Average : " << printf("%.1f", s1.get_avg()) << endl; 
	cout << "GPA : " << printf("%.1f", s1.get_gpa()) << endl;
	return 0;
}

void Student::set_marks(void) {
	cout << "Enter marks for 7 subjects:\n";
	try {
		for (int i=0; i < 7; i++) {
			cin >> marks[i];
			if (marks[i] < 33) {
				throw(marks[i]);
			} else if (marks[i] > 100) {
				throw(marks[i]);
			}
			// Append to vector gpa if no error encountered:
			else {
				if (marks[i] >= 33 && marks[i] <= 39)
					grades.push_back(1.00);
				else if (marks[i] >= 40 && marks[i] <= 49)
					grades.push_back(2.00);
				else if (marks[i] >= 50 && marks[i] <= 59)
					grades.push_back(3.00);
				else if (marks[i] >= 60 && marks[i] <= 69)
					grades.push_back(3.50);
				else if (marks[i] >= 70 && marks[i] <= 79)
					grades.push_back(4.00);
				else if (marks[i] >= 80)
					grades.push_back(5.00);
			}
		}
		cout << endl;
	} catch(int mark) {
		if (mark > 100){
			cout << "Error! Marks exceeded 100.\n";
			exit(1);
		}
		else if (mark < 33) {
			cout << "Error! Student has failed the exam.\n";
			exit(1);
		}
	}
}

double Student::get_avg(void) {
	double sum = 0, avg;

	for (int i=0; i < 7; i++) 
		sum += marks[i];
	avg = sum / 7;
	return avg;
}

double Student::get_gpa(void) {
	double sum_grades = 0, gpa;

	for (int i=0; i < 7; i++) 
		sum_grades += grades[i];
	gpa = sum_grades / 7;
	return gpa;
}
