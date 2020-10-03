#include <iostream>
using namespace std;

int main()
{
	string subjects[7] = {"Bangla", "English", "Maths", "Physics",
		"Chemistry", "Biology", "ICT"};
	int marks[7], total = 0;
	
	cout << "Enter the marks: \n\n";
	
	try {
		for (int i=0; i < 7; i++) {
			cout << subjects[i] << "= ";
			cin >> marks[i];
			if (marks[i] > 100) {
				throw(marks[i]);
			}
			else if (marks[i] < 33) {
				throw(marks[i]);
			}
			total += marks[i];
		}
	}
	catch(int mark) {
		if (mark > 100) cout << "Error! Marks exceeded 100.\n";
		else if (mark < 33) cout << "Error! Student has failed the exam.\n";
	}
	
	float avg = total / 7;
	
	cout << "Total = " << total << endl;
	cout << "Average = " << avg << endl;
	return 0;
}