#include <iostream>
using namespace std;
#include "data/data.cpp"

///! book an available space
void bookAnAvailableSpace()
{
    if (length < 5)
    {
        cout << endl
             << "Enter ";
        cin >> bookingsOld[length];
        length++;
        cout << "Booking successful." << endl
             << endl;
    }
    else
    {
        cout << "No available booking space." << endl;
    }
}