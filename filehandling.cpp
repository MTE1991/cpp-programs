#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream NewFile("new_text.txt");
	
	NewFile << "Hello, world!\n";
	NewFile << "This is a new text file.";
	
	NewFile.close();
	
	string lines;
	
	ifstream ReadFile("new_text.txt");
	
	while (getline(ReadFile, lines)) {
		cout << lines << endl;
	}
	
	ReadFile.close(); 
}
