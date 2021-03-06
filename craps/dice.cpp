#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <time.h>
#include <string>

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

bool isValidateDate(int day , int month , int year ) {
    bool isValid = true;

    isValid = year >= 1000;
    isValid = isValid && (month > 0 && month < 13);

    bool isLeapYr = isLeapYear(year);
    int maxDays = getMaxDaysInMonth(month, isLeapYr);

    isValid = isValid && (day <= maxDays);

    return isValid;
}

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


    int scores[100] = {};
    string names[100] = {};

    int record_count = 0;

    cout << "How many students took the exam ? ";

    cin >> record_count;
    cin.ignore();

    for (int n = 0; n < record_count; n++)
    {

        cout << "Student #" << n + 1 << " Name : ";
        getline(cin, names[n]);

       
        cout << "Student #" << n + 1 << " Score : ";
        cin >> scores[n];
        cin.ignore();
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

}

void wordSeparation() {
    //declare variables
    char input[100];
    int wordCounter = 0;

    char output[100];
    int i;
    //input string
    cout << "Enter a sentence: ";
    cin >> input;

    //seperate the words
    for (i = 0; input[i] != 0; i++) {
        // Check if it is an uppercase letter but not the first letter (i > 0)
        if (input[i] >= 'A' && input[i] <= 'Z' && i > 0)
        { 
            //found an uppercase letter. Add a space to the output string 
            output[i + wordCounter] = ' ';

            //increment the number of words found. Length of the output string
            //will be more than that of the input after adding spaces
            wordCounter++;

            //convert the letter to lowercase (by adding 32) 
            //and copy it to the output string 
            output[i + wordCounter] = input[i] + 32; 
        }
        else
        {
            output[i + wordCounter] = input[i];
        }
    }
    //add string terminator to the output string
    output[i + wordCounter] = 0;

    //print the output
    cout << endl << output;
}

void dateFormatting() {

    //declare variables
    string inputDate ;
    int year, month, day;
    char slash = '/';

    string month_name[] = { "January","Feb","March","April","May","June","July","August","September","October","November","December" };

    //input date
    cout << "Enter a date (mm/dd/yyyy): ";
    cin >> month >> slash >> day >> slash >> year;

    //validate date
    if (!isValidateDate(day, month, year)) {
        cout << month << "/" << day << "/" << year << " is an invalid date" << endl;
    }
    else
        //print output
        cout << month_name[month - 1 ] << " " << day << ", " << year;
}

int* reverseArray(int* numberList, int count) {
    int *output = new int[count];
    for (int i = 0; i < count; i++) {
        output[i] = numberList[count - 1 - i];
    }
    return output;
}

void pointerProblem() {
    int* numberList;
    int* revArray;
    int count;

    cout << "How many numbers do you have in your array? ";
    cin >> count;

    numberList = new int[count];

    for (int i = 0; i < count; i++) {
        cout << "Enter value: ";
        cin >> numberList[i];
    }

    revArray = reverseArray(numberList, count);

    for (int i = 0; i < count; i++) {
        cout << revArray[i] << " ";
    }

}

struct Bin {
    string Description;
    int PartsInBin;
};

bool addParts(Bin *theBin, int items) {
    bool success = true;
    if (theBin->PartsInBin + items <= 30)
    { 
        theBin->PartsInBin = theBin->PartsInBin + items;
    }
    else {
        success = false;
    }

    return success;
}

bool removeParts(Bin *theBin, int items) {
    bool success = true;
    if (theBin->PartsInBin - items > -1) {
        theBin->PartsInBin = theBin->PartsInBin - items;
    }
    else {
        success = false;
    }

    return success;
}

Bin shelf[10] = {
    {"Valve", 10},
    {"Bearing", 5},
    {"Bushing", 15},
    {"Coupling", 21},
    {"Flange", 7},
    {"Gear", 5},
    {"Gear Housing", 5},
    {"Vacuum Gripper", 25},
    {"Cable", 18},
    {"Rod", 12}
};

void showShelf() {
    cout << endl;
    cout << setw(18) << "Description" << setw(11) << "Items" << endl;
    cout << setw(18) << "============" << setw(11) << "=====" << endl;
    for (int i = 0; i < 10; i++) {
        cout << setw(2) << i + 1 << " " << setw(15) << shelf[i].Description << "\t" << shelf[i].PartsInBin << endl;
    }
}

void inventoryProblem() {
    int selection = 0;
    char input = ' ';
    int qty;

    do {
        showShelf();
        do {
            cout << "\nSelect a bin (1 - 10), 0 to Exit -> ";
            cin >> selection;
            if (selection > 0 && selection < 11) {
                do {
                    cout << "\nA to Add, R to Remove -> ";
                    cin >> input;
                } while (!(input == 'A' || input == 'R' || input == 'a' || input == 'r'));

                do {
                    cout << "\nHow many items? -> ";
                    cin >> qty;
                    if (qty < 1) {
                        cout << "Quantity must be a positive number\n";
                    }
                } while (qty < 1);

                switch (input) {
                case 'A':
                case 'a':
                    if(!addParts(&shelf[selection - 1], qty))
                        cout << "\n===> Bin cannot hold more that 30 items. <===\n";
                    break;
                case 'R':
                case 'r':
                    if (!removeParts(&shelf[selection - 1], qty))
                        cout << "Not enough items to remove in bin #" << selection;
                    break;
                }
            }
        } while (selection < 0 && selection > 10);
    } while (selection != 0);
}

struct HourlyPaid {
    int hoursWorked;
    double hourlyRate;
};

struct Salaried {
    double salary;
    double bonus;
};

struct Income {
    HourlyPaid hourly;
    Salaried salaried;
};

void incomeProblem() {
    
    //declare variables
    int incomeType;
    Income income;

    do {
        //prompt for type of income
        do {
            cout << "1. Hourly Worker" << endl;
            cout << "2. Salaried Worker" << endl;
            cout << "0. Exit" << endl;
            cout << endl << "Select worker type -> ";
            cin >> incomeType;
        } while (incomeType < 0 || incomeType > 2);

        //Accept the income details based on the selected income type
        switch (incomeType)
        {
        case 1: //Hourly
            cout << "\nEnter the hourly rate: ";
            cin >> income.hourly.hourlyRate;

            cout << "Enter the number of hours worked: ";
            cin >> income.hourly.hoursWorked;

            //calculate total income
            cout << "\nTotal Income: $" << fixed << setprecision(2) << income.hourly.hoursWorked * income.hourly.hourlyRate << endl << endl;
            break;

        case 2: //Salaried

            cout << "\nEnter salary amount: ";
            cin >> income.salaried.salary;

            cout << "Enter bonus amount: ";
            cin >> income.salaried.bonus;

            //calculate total income
            cout << "\nTotal Income: $" << fixed << setprecision(2) << income.salaried.salary + income.salaried.bonus << endl << endl;
            break;
        }
    } while (incomeType != 0);
}

int main()
{
    //start set #6
    incomeProblem();
    //inventoryProblem();
    //pointerProblem();
    //dateFormatting();
    //wordSeparation();
    //end set #6

    //reversingProblem();
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
