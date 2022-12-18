#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

class Calendar {
	private:
		int year;
	public:
	    // Constructor
	    Calendar(int y) {
	    	year = y;
	    };
	    //Destructor
		~Calendar() {};

		/*
		Index	 Day
		0		 Sun
		1		 Mon
		2		 Tue
		3		 Wed
		4		 Thu
		5		 Fri
		6		 Sat

		Source: https://cs.uwaterloo.ca/~alopez-o/math-faq/node73.html
		*/
		int dayNumber(int day, int month, int year) {
			static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
			year -= month < 3;
			return (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
		}

		/*
		Month 	Name
		0		January
		1		February
		2		March
		3		April
		4		May
		5		June
		6		July
		7		August
		8		September
		9		October
		10		November
		11		December
		*/
		string getMonthName(int monthNumber) {
			string months[] = {"January", "February", "March",
							"April", "May", "June",
							"July", "August", "September",
							"October", "November", "December"
							};
			return (months[monthNumber]);
		}

		/* A Function to return the number of days in
		a month

		Month Number	 Name	 Number of Days
		0			 January	 31
		1			 February 28 (non-leap) / 29 (leap)
		2			 March	 31
		3			 April	 30
		4			 May		 31
		5			 June	 30
		6			 July	 31
		7			 August	 31
		8			 September 30
		9			 October	 31
		10			 November 30
		11			 December 31

		*/
		int numberOfDays (int monthNumber, int year) {
			switch(monthNumber) {
				case 0:
		        case 2:
		        case 4:
		        case 6:
		        case 7:
		        case 9:
		        case 11:
		        	return(31); // for months of 31 days
		       		break;
		        case 1:
		            if (year % 400 == 0 || (year % 4 == 0 && year %100 != 0)) {
		                return (29);
		            } else { 
		                return (28);
		                break;
		            }
		        case 3:
		        case 5:
		        case 8:
		        case 10: 
		            return(30); // for months of 30 days
		            break;
			}
		}

		void today() {
			// get current datetime from sys
		   time_t now = time(0);
		   
		   // current datetime string
		   string dt = ctime(&now);

		   // Print local date time
		   cout << "\nToday is: " << dt << endl;
		}

		void show() {
			printf("\tCalendar - %d\n\n", year);
			int days;

			// Index of the day from 0 to 6
			int current = dayNumber (1, 1, year);

			// i --> Iterate through all the months
			// j --> Iterate through all the days of the
			//	 month - i
			for (int i = 0; i < 12; i++) {
				days = numberOfDays (i, year);

				// Print the current month name
				printf("\n %s \n",
					getMonthName (i).c_str());

				// Print the columns
				printf(" Sun Mon Tue Wed Thu Fri Sat\n");

				// Print appropriate spaces
				int k;
				for (k = 0; k < current; k++)
					printf("    ");

				for (int j = 1; j <= days; j++)
				{
					printf("%4d", j);
					if (++k > 6)
					{
						k = 0;
						printf("\n");
					}
				}
				if (k) {
					printf("\n");
				}
				current = k;
			}
			printf("\n");
		}
};