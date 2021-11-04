#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <time.h>

using namespace std;
int coinToss() {
    return 1 + rand() % 2 ;
}

void doCoinToss() {
    time_t seconds;
    time(&seconds);
    srand((unsigned int)seconds);

    int count;
    cout << "How many attempts? "; cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "Coin Toss: " << coinToss() << endl;
    }
}

int getPlayerResponse() {
    int input;
    do {
        cout << "\nPick one Rock = 1, Paper = 2, Scissor = 3, Quit = 0 : ";
        cin >> input;
        if (input < 0 || input > 3) {
            cout << "\nERROR: Invalid input. Try again.\n";
        }
    } while (input < 0 || input > 3);
    return input;
}

int getCpuSelection() {
    double rnd = rand() / static_cast<double>(RAND_MAX + 1);
    int that = 1 + static_cast<int>(rnd * 3);
    return that;
}

string whoWon(int player, int cpu) {
    string retValue;
    if (player == cpu) {
        retValue = "Tie";
    } else
    //R = 1, P = 2, S = 3
    // Player       CPU     Winner
    // R            P       CPU
    // R            S       Player
    // P            S       CPU
    // P            R       Player
    // S            R       CPU
    // S            P       Player

    if (player == 1 && cpu == 2){
        retValue = "CPU";
    }else
        if (player == 1 && cpu == 3) {
            retValue = "Player";
        }else
            if (player == 2 && cpu == 3) {
                retValue = "CPU";
            }else
                if (player == 2 && cpu == 1) {
                    retValue = "Player";
                }else
                    if (player == 3 && cpu == 1) {
                        retValue = "CPU";
                    }else
                        if (player == 3 && cpu == 2) {
                            retValue = "Player";
                        }
                        else {
                            retValue = "Check logic";
                        }

    return retValue;
}

void playRockPaperScissors() {
    int playerResponse = 0, cpuSelection = 0;
    do {
        playerResponse = getPlayerResponse();
        if (playerResponse != 0) {
            cpuSelection = getCpuSelection();
            cout << "Who won : " << whoWon(playerResponse, cpuSelection);
            cout << "\nYou selected " << playerResponse << ", CPU selected " << cpuSelection << endl;
        }
    } while (playerResponse != 0);

    cout << "\nGood bye!";
}

int main()
{
    //doCoinToss();
    playRockPaperScissors();
    return 0;
}
