#include "write.h"
#include <iostream>
using namespace std;
#include "data.h"
#include "data.cpp"

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