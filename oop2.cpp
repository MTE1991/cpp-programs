#include <iostream>
#include <cmath>

using namespace std;

class Nissan {
	private:
		string manufacturer = "Nissan";
		string model_1 = "R32 GTR";
		string info_r32_1[4] = {"BHP", "Torque", "Powertrain", "Acceleration (0-60mph)"};
		string info_r32_2[4] = {"206 kW (280 PS; 276 hp) at 6,800 rpm", "260 lbâ‹…ft (353 Nâ‹…m) of torque at 4,400 rpm",
		"AWD ATTESA E-TS", "4.7 seconds (est)"};
		
	public:
		void get_info() {
			cout << manufacturer << " " << model_1 << "\n\n";
			for (int i=0; i < 4; ++i) {
				cout << info_r32_1[i] << " : " << info_r32_2[i] << "\n";
			}
			cout << "\n";
		}	 
};

int main()
{
	Nissan my_car;
	my_car.get_info();
	return 0;
}
