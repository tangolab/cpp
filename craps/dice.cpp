#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <time.h>

using namespace std;
int coinToss() {
    int randNumber = rand();
    cout << "Random number " << randNumber << endl;
    // divide the random number by two and obtain the remainder; 
    int remainder = randNumber % 2;

    cout << "remainder " << remainder << endl;
    // it will either be 0 or 1; so add a 1 to it; 

    int return_value = remainder + 1;
    cout << "return value " << return_value << endl;
    // now the result will be either a 1 or 2
    return return_value;

}

int main()
{
    time_t seconds;
    time(&seconds);
    srand((unsigned int)seconds);

    int count;
    cout << "How many attempts? "; cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "Coin Toss: " << coinToss() << endl;
    }
}
