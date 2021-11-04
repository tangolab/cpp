#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <time.h>

using namespace std;
int coinToss() {
    return 1 + rand() % 2 ;
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