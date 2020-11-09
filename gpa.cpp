// GPA Calculator ver 1.03

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Student {
public:
	string name;
	int roll;
	string institute;
    int marks[7];
	vector<double> grades;

	Student(string n, int r, string ins) {
	name = n;
	roll = r;
	institute = ins;
	}

	void set_marks(void); // input marks
	double get_avg(void); // return average marks
	double get_gpa(void); // return gpa
};

int main() {
	Student s1("MT Ekleel", 116, "EUSC");

	// Create Log file that will contain student info
	ofstream logf; 

	// Output Student info 
	cout << s1.name << endl;
	cout << s1.institute << endl;
	cout << s1.roll << endl << endl;

	s1.set_marks();

	cout << "Average : " << s1.get_avg() << endl; 
	cout << "GPA : " << s1.get_gpa() << endl;

	/* Open log file and write student info and result into the txt file */
    logf.open("student_info.txt", ios::app);
	logf << s1.name << endl;
	logf << s1.institute << endl;
	logf << s1.roll << endl << endl;
	logf << "Average : " << s1.get_avg() << endl; 
	logf << "GPA : " << s1.get_gpa() << endl << endl;	

    logf.close();
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
	avg = (double)sum / 7;
	return avg;
}

double Student::get_gpa(void) {
	double sum_grades = 0, gpa;

	for (int i=0; i < 7; i++) 
		sum_grades += grades[i];
	gpa = (double)sum_grades / 7;
	return gpa;
}