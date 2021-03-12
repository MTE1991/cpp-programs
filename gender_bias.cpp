#include <iostream>
#include <fstream>
using namespace std;

void game_main(void);

int main(void)
{
    char prompt1;
	cout << "\t\t --:Gender bias: Masculine? Feminine? or Androgynous? ver 1.01:-- \n\n";
	cout << "Made by:\nMT Ekleel\nE-mail: mtahsinekleel02@gmail.com\nFacebook: MT Ekleel\nGitHub: MTE1991\n";
	cout << "There will be sixty traits below that will judge how androgynous you are. Which means how much gender bias your personality has. Indicate on a scale of 1 to 7 how well each traits describe you. A 1 means it's never true for you, a 7 means it's always true.\n";
	cout << "Press any key to proceed...\n";
	cin >> prompt1;
	game_main();
	return 0;
}

void game_main(void) {
	ofstream logf;
	logf.open("log.txt", ios::out);
	int scores[60] = {};
	string traits[60] = {"self-reliant","yielding","helpful","defends own beliefs","cheerful","moody","independent",
    "shy","conscientious","athletic","affectionate","theatrical","assertive","easily flattered","happy",
    "strong personality","loyal","unpredictable","forceful","feminine","reliable","analytical","sympathetic",
    "jealous","leadership ability","sensitive to others","truthful","willing to take risks","understanding",
    "secretive","decisive","compassionate","sincere","self-sufficient","eager to soothe hurt feelings",
    "conceited","dominant","soft-spoken","likable","masculine","warm","solemn","willing to take a stand",
    "tender","friendly","aggresive","gullible","inefficient","childlike","act as a leader","adaptative",
    "individualistic","do not use harsh language","unsystematic","competitive","love children","tactful",
    "ambitious","gentle","conventional"};

    for (int i=0; i<60; i++) {
    	cout << i + 1 << ". " << traits[i] << " >> ";
    	cin >> scores[i];
    	logf << scores[i] << ", ";
    	if (scores[i] < 1 || scores[i] > 7) {
    		cout << "Please enter a number between 1 and 7.\n";
            i--;
    		continue;
    	}
    }

    logf << endl;

    double m_score = (scores[0]+scores[3]+scores[6]+scores[9]+scores[12]+scores[15]+scores[18]+
    scores[21]+scores[24]+scores[27]+scores[30]+scores[33]+scores[36]+scores[39]+scores[42]+
    scores[45]+scores[49]+scores[51]+scores[54]+scores[59]);

    double f_score = (scores[1]+scores[4]+scores[7]+scores[10]+scores[13]+scores[16]+scores[19]+scores[22]+
    scores[25]+scores[28]+scores[31]+scores[34]+scores[37]+scores[40]+scores[43]+scores[46]+scores[48]+
    scores[52]+scores[55]+scores[58]);

    double result = (f_score - m_score) * 2.322;

    logf << result << endl;

    cout << "Result: \n";

    if (result == 0) {
    	cout << "You're androgynous. \n";
    } else if (result > 0 && result <= 1) {
    	cout << "You're near feminine.\n";
    } else if (result >= 2.025) {
    	cout << "You're feminine.\n";
    } else if (result < 0 && result >= -1) {
    	cout << "You're near masculine.\n";
    } else if (result < -1 && result <= -2.025) {
    	cout << "You're masculine.\n";
    }

    cout << "Note: \n";
    cout << "Results may be subject to doubt, even though it's a psycological game. It's because many of the qualities are subject to stereotypic bias. So the results may not be fully accurate. If you want to understand how the game works, please check the source code or contact with the developer.\n\n";

    char prompt2;
    cout << "Do you want to play again? (Y/N) >> ";
    cin >> prompt2;

    if (prompt2 == 89 or prompt2 == 121) 
    	game_main();
    else
    	cout << "Thank you for playing the game. \n";
    logf.close();
}
