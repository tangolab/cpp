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


int randomlySelectOneofThreeDoors() {
    int doorWithCar = 0;
    double rnd = rand() / static_cast<double>(RAND_MAX + 1);
    doorWithCar = static_cast<int>(rnd * 3);
    return doorWithCar;
}

void playMontyHallGame() {

    time_t seconds;
    time(&seconds);
    srand((unsigned int)seconds);

    cout << "How many times do you want the simulation to run ? ";
    int count;
    cin >> count;

    // d1, d2, d3
    string doors[3] = {};

    //setup the cars and goats
    for (int i=0; i <= count; i++) {
        int randomDoor = randomlySelectOneofThreeDoors();
        doors[randomDoor] = "Car";
        if (randomDoor == 0) {
            //place goats in the other two
            doors[1] = "Goat";
            doors[2] = "Goat";
        }
        else if (randomDoor == 1) {
            //place goats in the other two
            doors[0] = "Goat";
            doors[2] = "Goat";
        }
        else if (randomDoor == 2) {
            //place goats in the other two
            doors[0] = "Goat";
            doors[1] = "Goat";
        }
    }

    int countOriginalDoorWins = 0;
    int countOtherUnopenedDoorWins = 0;


    for (int j=0; j < count; j++) {
        //pick a door
        int selectedDoor = randomlySelectOneofThreeDoors();
        //reveal whats behind the selected door 
        cout << "Whats behind the original door? " << doors[selectedDoor] << endl;
        //stick to the original door
        if (doors[selectedDoor] == "Car") {
            countOriginalDoorWins += 1;
        }
        int newSelection = -1;
        //now select a door other than the original
        do {
            newSelection = randomlySelectOneofThreeDoors();
        } while (newSelection == selectedDoor);
        // the above loop will exit when the newSelection is either of the other two doors (other than the originalSelection)

        //now see if the new selection has the car
        cout << "Whats behin one of the unopened doors? " << doors[newSelection] << endl;
        if (doors[newSelection] == "Car") {
            countOtherUnopenedDoorWins += 1;
        }

    }

    cout << "Percentage won if sticking to original door = " << (static_cast<double>(countOriginalDoorWins) / count) * 100 << "%\n";
    cout << "Percentage won if other unopened door is selected = " << (static_cast<double>(countOtherUnopenedDoorWins) / count) * 100 << "%\n";
}

bool isLeapYear(int year) {
    bool isLeapYear;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                isLeapYear = true;
            else
                isLeapYear = false;
        }
        else
            isLeapYear = true;
    }
    else
        isLeapYear = false;
    return isLeapYear;
}

int getMaxDaysInMonth(int month, bool isLeapYear) {
    int maxDayOfTheMonth;
    switch (month) {
    case 4:
    case 6:
    case 9:
    case 11:
        maxDayOfTheMonth = 30;
        break;
    case 2:
        if (isLeapYear) {
            maxDayOfTheMonth = 29;
        }
        else {
            maxDayOfTheMonth = 28;
        }
        break;
    default:
        maxDayOfTheMonth = 30;
    }
    return maxDayOfTheMonth;
}

void validateDate() {
    int day = 0, month = 0, year = 0;
    do {
        cout << "\nYear? (4 digits) ";
        cin >> year;
    } while (year < 1000 && year > 9999);

    do {
        cout << "\Day? (1 - 31) ";
        cin >> day;
    } while (day < 1 && day > 31);

    do {
        cout << "\nMonth? (1 - 12) ";
        cin >> month;
    } while (month < 1 && month > 12);

    bool isLeapYr = isLeapYear(year);

    int maxDays = getMaxDaysInMonth(month, isLeapYr);

    cout << month << "/" << day << "/" << year;
    if (day > maxDays) {
        cout << " is not a valid calendar date!";
    }
    else {
        cout << " is a valid calendar date!";
    }
}

int main()
{
    //doCoinToss();
    //playRockPaperScissors();
    //playMontyHallGame();
    validateDate();
    return 0;
}
