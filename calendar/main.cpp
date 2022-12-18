#include <iostream>
#include "calendar.h"
using namespace std;

int main() {
	int e = -1;
	while (true) {
		try {
			int yr;
			char prompt;
			cout << "Enter Year: ";
			cin >> yr;
			Calendar cal = Calendar(yr); // create new calendar object
			cal.today(); // shows current date time
			cal.show();	// shows the calendar
			cout << "Do you want to quit? (Y/N) >> ";
			cin >> prompt;
			if (prompt == 'n' or prompt == 'N') {
				continue;
			} else if (prompt == 'Y' or prompt == 'y') {
				cout << "Thank you!" << endl;
				break;
			} else {
				throw e;
			}
		}
		catch (int e) {
			cout << "\nAn exception occured. Please enter a valid input.\n";
			break;
		}
		catch (...) {
			cout << "\nAn unknown exception occured.\n";
			break;
		}
	}
	return 0;
}
