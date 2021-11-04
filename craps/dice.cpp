#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <time.h>

using namespace std;
void dice() {
    int rolls;
    cout << "How many rolls? "; cin >> rolls;
    while (rolls < 1){
        cerr << "Please enter at least one roll. \nTry again: ";
        cin >> rolls;
    }
    time_t seconds;
    time(&seconds);
    srand((unsigned int)seconds);

    int roll1, roll2, result[5] = { 0,0,0,0,0 };
    string labels[5] = { "Snake eyes","Ace Deuce","Seven Out", "Yo", "Boxcars" };
    const int SNAKE_EYES = 0, ACE_DEUCE = 1, SEVEN_OUT = 2, YO = 3, BOXCARS = 4;
    int snake_eyes = 0;
    for (int i = 0; i < rolls; i++) {
        roll1 = 1 + rand() % 6;
        roll2 = 1 + rand() % 6;
        switch (roll1 + roll2){
        case 2:
            result[SNAKE_EYES] += 1; break;
        case 3:
            result[ACE_DEUCE] += 1; break;
        case 7:
            result[SEVEN_OUT] += 1; break;
        case 11:
            result[YO] += 1; break;
        case 12:
            result[BOXCARS] += 1; break;
        default:
            break;
        }
    }

    for (int i = 0; i <= BOXCARS; i++) {
        cout << setw(15) << labels[i] << setw(10) << result[i] << " (" << ((double)result[i] / rolls) * 100 << "%)" << endl;
    }
}

/*

double GetRandomBetween(double min, double max)
{
    return min + (double)rand() * (max - min) / (double)RAND_MAX;
}

void EstimatePi() {
    time_t seconds;
    time(&seconds);
    srand((unsigned int)seconds);
    double min=0, max=1;
    unsigned points;
    cout << "How many points?: ";
    cin >> points;

    // to count how many are inside the circle
    unsigned points_inside_circle=0;

    for (int i=0; i < points - 1; i++){
        double x, y, n;

        //get random x and y between 0 and 1
        x = GetRandomBetween(0, 1);
        y = GetRandomBetween(0, 1);

        n = x * x + y * y;

        //check if n is <= (x squared + y squared)
        if (n <= 1) {
            points_inside_circle += 1;
        }
    }
    // pi = 4 * M / N
    // where M is the number of points inside the circle and N is the total number of points considered
    cout << "Estimate value of Pi is - " << (4 * (double)points_inside_circle) / points;
}
*/

//double GetRandomBetween(double min, double max)
//{
//    return min + (double)rand() * (max - min) / (double)RAND_MAX;
//}

int coinToss() {
    return rand() % 2;
}

int main()
{
    time_t seconds;
    time(&seconds);
    srand((unsigned int)seconds);
    for (int i = 0; i < 10; i++) {
        cout << coinToss() << endl;
    }

   /* double min = 0, max = 1;
    unsigned points;
    cout << "How many points?: ";
    cin >> points;

    // to count how many are inside the circle
    unsigned points_inside_circle = 0;

    for (int i = 0; i < points - 1; i++) {
        double x, y, n;

        //get random x and y between 0 and 1
        x = GetRandomBetween(0, 1);
        y = GetRandomBetween(0, 1);

        n = x * x + y * y;

        //check if n is <= (x squared + y squared)
        if (n <= 1) {
            //if yes, then the point(x,y) is inside the circle
            points_inside_circle += 1;
        }
    }
    // pi = 4 * M / N
    // where M is the number of points inside the circle and N is the total number of points considered
    cout << "Estimate value of Pi is - " << (4 * (double)points_inside_circle) / points;
    */
}
