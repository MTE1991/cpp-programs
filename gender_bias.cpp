/*
    * Ideas are taken from the book "Brain Games" by Richard B. Fisher.
    * Created by MT Ekleel
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int NUM_TRAITS = 60;
const double FEMININE_WEIGHT = 2.322;
string userName;
void displayIntro();
void collectTraitScores(vector<int>& scores, const vector<string>& traits);
double calculateResult(const vector<int>& scores);
void displayResult(double result);

int main() {
    displayIntro();

    char prompt1;
    cout << "Press any key to proceed...\n";
    cin >> prompt1;
    
    cout << "Enter your name >> ";
    cin >> userName;

    vector<int> scores(NUM_TRAITS, 0);
    vector<string> traits = {
        "self-reliant","yielding","helpful","defends own beliefs","cheerful","moody","independent",
        "shy","conscientious","athletic","affectionate","theatrical","assertive","easily flattered","happy",
        "strong personality","loyal","unpredictable","forceful","feminine","reliable","analytical","sympathetic",
        "jealous","leadership ability","sensitive to others","truthful","willing to take risks","understanding",
        "secretive","decisive","compassionate","sincere","self-sufficient","eager to soothe hurt feelings",
        "conceited","dominant","soft-spoken","likable","masculine","warm","solemn","willing to take a stand",
        "tender","friendly","aggresive","gullible","inefficient","childlike","act as a leader","adaptative",
        "individualistic","do not use harsh language","unsystematic","competitive","love children","tactful",
        "ambitious","gentle","conventional"
    };

    collectTraitScores(scores, traits);

    double result = calculateResult(scores);

    displayResult(result);

    return 0;
}

void displayIntro() {
    cout << "\t\t --: Gender Bias: Masculine? Feminine? or Androgynous? ver 1.01:-- \n\n";
    cout << "Made by:\nMT Ekleel\nE-mail: mtahsinekleel02@gmail.com\nFacebook: MT Ekleel\nGitHub: MTE1991\n";
    cout << "There will be sixty traits below that will judge how androgynous you are. Which means how much gender bias your personality has. Indicate on a scale of 1 to 7 how well each trait describes you. A 1 means it's never true for you, a 7 means it's always true.\n";
}

void collectTraitScores(vector<int>& scores, const vector<string>& traits) {
    ofstream logFile("log.txt", ios::app);
    if (!logFile.is_open()) {
        cerr << "Error: Unable to open the log file." << endl;
        return; 
    }

    logFile << "username: " << userName << endl;
    for (int i = 0; i < NUM_TRAITS; i++) {
        cout << i + 1 << ". " << traits[i] << " >> ";
        cin >> scores[i];
        logFile << scores[i] << ", ";
        if (scores[i] < 1 || scores[i] > 7) {
            cout << "Please enter a number between 1 and 7." << endl;
            i--;
        }
    }

    logFile << endl;
    logFile.close(); 
}

double calculateResult(const vector<int>& scores) {
    double m_score = 0.0;
    double f_score = 0.0;

    for (int i = 0; i < NUM_TRAITS; i++) {
        if (i % 3 == 0) { // Male-associated traits
            m_score += scores[i];
        } else { // Female-associated traits
            f_score += scores[i];
        }
    }

    return (f_score - m_score) * FEMININE_WEIGHT;
}

void displayResult(double result) {
    cout << "Result: \n";
    
    if (result == 0) {
        cout << "You're androgynous.\n";
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
    cout << "Results may be subject to doubt, even though it's a psychological experiment. It's because many of the qualities are subject to stereotypic bias. So the results may not be fully accurate. If you want to understand how the game works, please check the source code or contact with the developer.\n\n";

    char prompt2;
    cout << "Do you want to play again? (Y/N) >> ";
    cin >> prompt2;

    if (prompt2 == 'Y' || prompt2 == 'y') {
        main();
    } else {
        cout << "Thank you for playing the game. \n";
    }
}

