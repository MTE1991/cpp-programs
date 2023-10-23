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

class GenderGame {
public:
    GenderGame() {
        displayIntro();
        string prompt1;
        cout << "Press any key to proceed...\n";
        cin >> prompt1;
    }

    void play() {
        collectUserInfo();
        calculateResult();
        displayResult();
    }

private:
    string userName;
    vector<int> scores;
    const vector<string> traits = {
        "self-reliant", "yielding", "helpful", "defends own beliefs", "cheerful", "moody", "independent",
        "shy", "conscientious", "athletic", "affectionate", "theatrical", "assertive", "easily flattered", "happy",
        "strong personality", "loyal", "unpredictable", "forceful", "feminine", "reliable", "analytical", "sympathetic",
        "jealous", "leadership ability", "sensitive to others", "truthful", "willing to take risks", "understanding",
        "secretive", "decisive", "compassionate", "sincere", "self-sufficient", "eager to soothe hurt feelings",
        "conceited", "dominant", "soft-spoken", "likable", "masculine", "warm", "solemn", "willing to take a stand",
        "tender", "friendly", "aggresive", "gullible", "inefficient", "childlike", "act as a leader", "adaptative",
        "individualistic", "do not use harsh language", "unsystematic", "competitive", "love children", "tactful",
        "ambitious", "gentle", "conventional"
    };
    double result;

    void displayIntro() {
        cout << "\t\t --: Gender Bias: Masculine? Feminine? or Androgynous? ver 1.01:-- \n\n";
        cout << "Made by:\nMT Ekleel\nE-mail: mtahsinekleel02@gmail.com\nFacebook: MT Ekleel\nGitHub: MTE1991\n";
        cout << "There will be sixty traits below that will judge how androgynous you are. Which means how much gender bias your personality has. Indicate on a scale of 1 to 7 how well each trait describes you. A 1 means it's never true for you, a 7 means it's always true.\n";
    }

    void collectUserInfo() {
        cout << "Enter your name >> ";
        cin >> userName;

        ofstream logFile("log.txt", ios::app);
        if (!logFile.is_open()) {
            cerr << "Error: Unable to open the log file." << endl;
            return;
        }

        logFile << "username: " << userName << endl;
        for (int i = 0; i < NUM_TRAITS; i++) {
            cout << i + 1 << ". " << traits[i] << " >> ";
            int traitScore;
            while (true) {
                cin >> traitScore;
                if (cin.fail() || traitScore < 1 || traitScore > 7) {
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                    cout << "Please enter a valid number between 1 and 7." << endl;
                } else {
                    break; // Valid input, exit the loop
                }
            }
            logFile << traitScore << ", ";
            scores.push_back(traitScore);
        }

        logFile << endl;
        logFile.close();
    }

    void calculateResult() {
        double m_score = scores[0] + scores[3] + scores[6] + scores[9] + scores[12] + scores[15] + scores[18] +
                         scores[21] + scores[24] + scores[27] + scores[30] + scores[33] + scores[36] + scores[39] + scores[42] +
                         scores[45] + scores[49] + scores[51] + scores[54] + scores[59];

        double f_score = scores[1] + scores[4] + scores[7] + scores[10] + scores[13] + scores[16] + scores[19] + scores[22] +
                         scores[25] + scores[28] + scores[31] + scores[34] + scores[37] + scores[40] + scores[43] + scores[46] + scores[48] +
                         scores[52] + scores[55] + scores[58];

        result = (f_score - m_score) * FEMININE_WEIGHT;
    }

    void displayResult() {
        ofstream logFile("log.txt", ios::app);
        if (!logFile.is_open()) {
            cerr << "Error: Unable to open the log file." << endl;
            return;
        }

        cout << "Result: \n";
        logFile << "username: " << userName << ", ";
        if (result == 0) {
            cout << "You're androgynous.\n";
            logFile << "androgynous.\n\n";
        } else if (result > 0 && result <= 1) {
            cout << "You're near feminine.\n";
            logFile << "near feminine.\n\n";
        } else if (result >= 2.025) {
            cout << "You're feminine.\n";
            logFile << "feminine.\n\n";
        } else if (result < 0 && result >= -1) {
            cout << "You're near masculine.\n";
            logFile << "near masculine.\n\n";
        } else if (result < -1 && result <= -2.025) {
            cout << "You're masculine.\n";
            logFile << "masculine.\n\n";
        }

        char prompt2;
        cout << "Do you want to play again? (Y/N) >> ";
        cin >> prompt2;
        if (tolower(prompt2) == 'y') {
            play();
        }
        cout << "Thank you for playing the game!\n";
    }

};

int main() {
    GenderGame game;
    game.play();

    return 0;
}

