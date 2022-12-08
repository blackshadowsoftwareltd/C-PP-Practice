#include <iostream>
using namespace std;
#include "data/data.h"
#include "data/data.cpp"
#include "write/write.h"

///! book an available space
void bookAnAvailableSpace()
{
    if (length < 5)
    {
        cout << endl
             << "Enter the booking number: ";
        cin >> bookings[length];
        length++;
        cout << "Booking successful." << endl
             << endl;
    }
    else
    {
        cout << "No available booking space." << endl;
    }
}