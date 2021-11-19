#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <time.h>

#include <stdio.h>
#include <vector>
#include <numeric>
#include <fstream>

using namespace std;
//int coinToss() {
//    return 1 + rand() % 2 ;
//}
//
//void doCoinToss() {
//    time_t seconds;
//    time(&seconds);
//    srand((unsigned int)seconds);
//
//    int count;
//    cout << "How many attempts? "; cin >> count;
//    for (int i = 0; i < count; i++) {
//        cout << "Coin Toss: " << coinToss() << endl;
//    }
//}
//
//int getPlayerResponse() {
//    int input;
//    do {
//        cout << "\nPick one Rock = 1, Paper = 2, Scissor = 3, Quit = 0 : ";
//        cin >> input;
//        if (input < 0 || input > 3) {
//            cout << "\nERROR: Invalid input. Try again.\n";
//        }
//    } while (input < 0 || input > 3);
//    return input;
//}
//
//int getCpuSelection() {
//    double rnd = rand() / static_cast<double>(RAND_MAX + 1);
//    int that = 1 + static_cast<int>(rnd * 3);
//    return that;
//}
//
//string whoWon(int player, int cpu) {
//    string retValue;
//    if (player == cpu) {
//        retValue = "Tie";
//    } else
//    //R = 1, P = 2, S = 3
//    // Player       CPU     Winner
//    // R            P       CPU
//    // R            S       Player
//    // P            S       CPU
//    // P            R       Player
//    // S            R       CPU
//    // S            P       Player
//
//    if (player == 1 && cpu == 2){
//        retValue = "CPU";
//    }else
//        if (player == 1 && cpu == 3) {
//            retValue = "Player";
//        }else
//            if (player == 2 && cpu == 3) {
//                retValue = "CPU";
//            }else
//                if (player == 2 && cpu == 1) {
//                    retValue = "Player";
//                }else
//                    if (player == 3 && cpu == 1) {
//                        retValue = "CPU";
//                    }else
//                        if (player == 3 && cpu == 2) {
//                            retValue = "Player";
//                        }
//                        else {
//                            retValue = "Check logic";
//                        }
//
//    return retValue;
//}
//
//void playRockPaperScissors() {
//    int playerResponse = 0, cpuSelection = 0;
//    do {
//        playerResponse = getPlayerResponse();
//        if (playerResponse != 0) {
//            cpuSelection = getCpuSelection();
//            cout << "Who won : " << whoWon(playerResponse, cpuSelection);
//            cout << "\nYou selected " << playerResponse << ", CPU selected " << cpuSelection << endl;
//        }
//    } while (playerResponse != 0);
//
//    cout << "\nGood bye!";
//}
//
//
//int randomlySelectOneofThreeDoors() {
//    int doorWithCar = 0;
//    double rnd = rand() / static_cast<double>(RAND_MAX + 1);
//    doorWithCar = static_cast<int>(rnd * 3);
//    return doorWithCar;
//}
//
//void playMontyHallGame() {
//
//    time_t seconds;
//    time(&seconds);
//    srand((unsigned int)seconds);
//
//    cout << "How many times do you want the simulation to run ? ";
//    int count;
//    cin >> count;
//
//    // d1, d2, d3
//    string doors[3] = {};
//
//    //setup the cars and goats
//    for (int i=0; i <= count; i++) {
//        int randomDoor = randomlySelectOneofThreeDoors();
//        doors[randomDoor] = "Car";
//        if (randomDoor == 0) {
//            //place goats in the other two
//            doors[1] = "Goat";
//            doors[2] = "Goat";
//        }
//        else if (randomDoor == 1) {
//            //place goats in the other two
//            doors[0] = "Goat";
//            doors[2] = "Goat";
//        }
//        else if (randomDoor == 2) {
//            //place goats in the other two
//            doors[0] = "Goat";
//            doors[1] = "Goat";
//        }
//    }
//
//    int countOriginalDoorWins = 0;
//    int countOtherUnopenedDoorWins = 0;
//
//
//    for (int j=0; j < count; j++) {
//        //pick a door
//        int selectedDoor = randomlySelectOneofThreeDoors();
//        //reveal whats behind the selected door 
//        cout << "Whats behind the original door? " << doors[selectedDoor] << endl;
//        //stick to the original door
//        if (doors[selectedDoor] == "Car") {
//            countOriginalDoorWins += 1;
//        }
//        int newSelection = -1;
//        //now select a door other than the original
//        do {
//            newSelection = randomlySelectOneofThreeDoors();
//        } while (newSelection == selectedDoor);
//        // the above loop will exit when the newSelection is either of the other two doors (other than the originalSelection)
//
//        //now see if the new selection has the car
//        cout << "Whats behin one of the unopened doors? " << doors[newSelection] << endl;
//        if (doors[newSelection] == "Car") {
//            countOtherUnopenedDoorWins += 1;
//        }
//
//    }
//
//    cout << "Percentage won if sticking to original door = " << (static_cast<double>(countOriginalDoorWins) / count) * 100 << "%\n";
//    cout << "Percentage won if other unopened door is selected = " << (static_cast<double>(countOtherUnopenedDoorWins) / count) * 100 << "%\n";
//}
//
//bool isLeapYear(int year) {
//    bool isLeapYear;
//    if (year % 4 == 0) {
//        if (year % 100 == 0) {
//            if (year % 400 == 0)
//                isLeapYear = true;
//            else
//                isLeapYear = false;
//        }
//        else
//            isLeapYear = true;
//    }
//    else
//        isLeapYear = false;
//    return isLeapYear;
//}
//
//int getMaxDaysInMonth(int month, bool isLeapYear) {
//    int maxDayOfTheMonth;
//    switch (month) {
//    case 4:
//    case 6:
//    case 9:
//    case 11:
//        maxDayOfTheMonth = 30;
//        break;
//    case 2:
//        if (isLeapYear) {
//            maxDayOfTheMonth = 29;
//        }
//        else {
//            maxDayOfTheMonth = 28;
//        }
//        break;
//    default:
//        maxDayOfTheMonth = 30;
//    }
//    return maxDayOfTheMonth;
//}
//
//void validateDate() {
//    int day = 0, month = 0, year = 0;
//    do {
//        cout << "\nYear? (4 digits) ";
//        cin >> year;
//    } while (year < 1000 && year > 9999);
//
//    do {
//        cout << "\nDay? (1 - 31) ";
//        cin >> day;
//    } while (day < 1 && day > 31);
//
//    do {
//        cout << "\nMonth? (1 - 12) ";
//        cin >> month;
//    } while (month < 1 && month > 12);
//
//    bool isLeapYr = isLeapYear(year);
//
//    int maxDays = getMaxDaysInMonth(month, isLeapYr);
//
//    cout << month << "/" << day << "/" << year;
//    if (day > maxDays) {
//        cout << " is not a valid calendar date!";
//    }
//    else {
//        cout << " is a valid calendar date!";
//    }
//}
//
//void readWriteFile() {
//
//}


void isPalindromic(string input) {
    int last = input.length();
    bool isPalin = true;
    for (int i = 0; i < last - 1; i++, last--) {
        if (input[i] != input[last]) {
            isPalin = false;
        }
    }
    cout << input << (isPalin ? " IS " : " IS NOT ") << "PALINDROME \n";
}


string TTTGrid[3][3] = {
    {" "," "," "},
    {" "," "," "},
    {" "," "," "}
};

void showTTTGrid() {
    cout << "\n\t_____________\n";
    for (int row = 0; row < 3; row++) {
        cout << "\n\t| ";
        for (int col = 0; col < 3; col++) {
            cout << TTTGrid[row][col] << " | ";
        }
        cout << "\n\t_____________\n";
    }
}


void initRandomizer() {
    time_t seconds;
    time(&seconds);
    srand((unsigned int)seconds);
}

int generateRandomNumber(int max) {
    double rnd = rand() / static_cast<double>(RAND_MAX + 1);
    return static_cast<int>(rnd * max);
}

bool placeMarker(string marker, int row, int col) {
    if (TTTGrid[row][col] == " ") {
        TTTGrid[row][col] = marker;
        return true;
    }
    else
        return false;
}

void randomlyPlace(string marker) {
    bool placed = false;
    while (!placed) {
        int row = generateRandomNumber(3);
        int col = generateRandomNumber(3);
        placed = placeMarker(marker, row, col);
    }
}

bool didSpecifiedMarkerWin(string marker) {
    if (TTTGrid[0][0] == marker && TTTGrid[0][1] == marker && TTTGrid[0][2] == marker ||
        TTTGrid[1][0] == marker && TTTGrid[1][1] == marker && TTTGrid[1][2] == marker ||
        TTTGrid[2][0] == marker && TTTGrid[2][1] == marker && TTTGrid[2][2] == marker ||

        TTTGrid[0][0] == marker && TTTGrid[1][0] == marker && TTTGrid[2][0] == marker ||
        TTTGrid[0][1] == marker && TTTGrid[1][1] == marker && TTTGrid[2][1] == marker ||
        TTTGrid[0][2] == marker && TTTGrid[1][2] == marker && TTTGrid[2][2] == marker ||

        TTTGrid[0][0] == marker && TTTGrid[1][1] == marker && TTTGrid[2][2] == marker ||
        TTTGrid[2][0] == marker && TTTGrid[1][1] == marker && TTTGrid[0][2] == marker
        )
        return true;
    else
        return false;
}

int whoIsTheWinner() {
    //CPU is "O"
    if (didSpecifiedMarkerWin("O"))
        return 1; 
    else if (didSpecifiedMarkerWin("X"))
        return 2; //YOU played "X";
    else
        return 3;
}

void acceptInput(int &row, int &col) {

    do {
        cout << "\nSelect Row Number (1-3, 0 to exit): ";
        cin >> row;
        if (row != 0) {
            cout << "Select Column Number (1-3, 0 to exit): ";
            cin >> col;
        }
    } while (row > 3 || col > 3 || row < 0 || col < 0);
}

int countFilledCells() {
    int cellsFilled = 0;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (TTTGrid[row][col] != " ") {
                cellsFilled += 1;
            }
        }
    }
    return cellsFilled;
}
bool isEndOfGame() {
    int cellsFilled = countFilledCells();
    // game is over if all cells are filled or either the CPU or the player has already won 
    return (cellsFilled > 8 || whoIsTheWinner() < 3);
}

void playTTT() {

    initRandomizer();
    //fill first two cells randomly and fairly
    randomlyPlace("O");
    randomlyPlace("X");
    //notice that there is one more call to randomlyPlace("O"); inside the do loop

    int inputRow = 0;
    int inputCol = 0;

    do {
        do {
            //CPU plays its turn
            randomlyPlace("O");
            //show the game board before accepting player input
            showTTTGrid();
            //check if the game is already over as CPU may have already won
            if (!isEndOfGame()) {
                //if CPU has not already won, accept player input
                acceptInput(inputRow, inputCol);
                if (inputRow != 0) {
                    //check to see if input is valid
                    if (inputRow > 3 || inputCol > 3 || inputRow < 1 || inputCol < 1) {
                        //player entered values outside acceptable range, display error
                        cout << "ERROR: Invalid input\n";
                    }
                    else {
                        bool placed = placeMarker("X", inputRow - 1, inputCol - 1);
                    }
                }
            }
        } while (!isEndOfGame() && inputRow != 0 ); // exit if player wanted to exit by entering 0 for ROW 
    } while (!isEndOfGame() && inputRow != 0);

   // showTTTGrid();

    switch (whoIsTheWinner()) {
    case 1:
        cout << "\n\n=======\n";
        cout << "CPU Won\n";
        cout << "=======\n";
        break;
    case 2:
        cout << "\n\n==========\n";
        cout << "You Won !!\m";
        cout << "==========\n";
        break;
    case 3:
        if (countFilledCells() > 8) {
            cout << "\n\n==============\n";
            cout << "It is a DRAW!!\n";
            cout << "==============\n";
        }
        else
        {
            cout << "\n\n==============\n";
            cout << "You chose to quit\n";
            cout << "=================\n";
        }
        break;
    }
}

void calculateStdDevUsingArray() {
    int numbers[100] = {};
    int input = -99;
    int currentItem = 0;
    double sum = 0;
    do {
        cout << "Enter a value (or -99 to quit): ";
        cin >> input;
        if (input != -99)
        {
            numbers[currentItem++] = input;
            sum += input;
        }
    } while (input != -99);

    double mean = sum / currentItem;

    double accumulatedSum = 0;

    for (int x = 0; x < currentItem; x++) {
        accumulatedSum += (numbers[x] - mean) * (numbers[x] - mean); // square of each value - mean
    }

    double stdDev = sqrt(accumulatedSum / currentItem);

    cout << setprecision(2);
    cout << "The average is " << mean << " with a standard deviation of " << stdDev << endl;
    //SAMPLE INPUT: 3,5,11,14,11
    //SAMPLE OUTPUT: The average is 8.8 with a standard deviation of 4.1

}

void calculateStdDevUsingVector() {
    vector<int> numbers;
    int input = -99;
    
    do {
        cout << "Enter a value (or -99 to quit): ";
        cin >> input;
        if(input != -99)
            numbers.push_back(input);
    } while (input != -99);

    double mean = accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();

    double accumulatedSum = 0;
    
    for (int val : numbers) {
        accumulatedSum += (val - mean) * (val - mean); // square of each value - mean
    }


    double stdDev = sqrt(accumulatedSum / numbers.size());

    cout << setprecision(2);
    cout << "The average is " << mean << " with a standard deviation of " << stdDev << endl;
    //SAMPLE INPUT: 3,5,11,14,11
    //SAMPLE OUTPUT: The average is 8.8 with a standard deviation of 4.1
}

void guessTheNumber() {
    char ready;
    int max = 100;
    cout << "Think of a number between 1 and " << max << ". Ready? (Y/N) : ";
    cin >> ready;

    int guess = max / 2;

    int last_max = max;
    int last_min = 1;

    if (ready == 'Y' || ready == 'y') {
        int response = 0;
        do {
            cout << "CPU thinks it is between " << last_min << " and " << last_max << endl;

            cout << "Is the number " << guess << " ? (1 = Higher, 2 = Lower, 3 = Exact) ";
            cin >> response;

            switch (response) {
            case 1: // higher
                last_min = guess;
                guess += (last_max - guess) / 2;
               // last_max = guess;
                break;
            case 2: // lower
                last_max = guess;
                guess -= (guess - last_min) / 2;
                //last_min = guess;
                break;
            case 3: 
                break;
            }
        } while (response != 3);
    }
}

void reversingProblem() {

    string path = "C:\\Users\\Lorrettus\\source\\repos\\craps\\craps\\scores.txt";
    ifstream file(path);
    if (file.is_open()) {
        int score;
        string name;
        char coma;

        int scores[100] = {};
        string names[100] = {};

        int record_count = 0;

        while (file >> score >> coma >> name )
        {
            scores[record_count] = score;
            names[record_count] = name;
            record_count++;
        }

        //setup variable for sorting
        bool flag = true;
        //sort from highest to lowest
        for (int outerIndex = 1; outerIndex < record_count && flag; outerIndex++) {
            flag = false;
            for (int innerIndex = 0; innerIndex < record_count; innerIndex++) {
                //if the next one is bigger than the current one
                if (scores[innerIndex + 1] > scores[innerIndex]) {
                    //swap the scores
                    int tempScore = scores[innerIndex];
                    scores[innerIndex] = scores[innerIndex + 1];
                    scores[innerIndex + 1] = tempScore;

                    //also swap the name
                    string tempName = names[innerIndex];
                    names[innerIndex] = names[innerIndex + 1];
                    names[innerIndex + 1] = tempName;

                    flag = true;
                }
            }
        }

        //print output
        for (int index = 0; index < record_count; index ++) {
            cout << names[index] << " : " << scores[index] << endl;
        }

        file.close();
    }
    else {
        cout << "Unable to open file - " << path << endl;
    }
}

int main()
{
    reversingProblem();
    //guessTheNumber();
    //calculateStdDevUsingVector();
    //calculateStdDevUsingArray();
    //playTTT();

    //doCoinToss();
    //playRockPaperScissors();
    //playMontyHallGame();
    //validateDate();
    //readWriteFile();
    return 0;
}
