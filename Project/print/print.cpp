#include <iostream>
using namespace std;
#include "data/data.h"
#include "data/data.cpp"
#include "print/print.h"

///! print init options
int printInitOptions()
{
    cout << endl
         << "Choose what you want." << endl
         << "Enter 'E' to Check the total available booking space. " << endl
         << "Enter 'B' to book an available space. " << endl
         << "Enter 'R' to remove the booking. " << endl
         << "Enter 'P' to View all booked list. " << endl
         << "Enter : ";
    return 0;
}

///! view all bookingsOld
int printAvailablebookingsOldpace()
{
    cout << "Available booking space: " << 5 - length << endl
         << endl;
    return 0;
}

///! view All bookingsOld
int viewAllbookingsOld()
{
    cout << endl
         << "All bookingsOld: " << endl;
    if (length == 0)
    {
        cout << "No bookingsOld." << endl;
        return;
    }

    for (i = 0; i < length; i++)
    {
        cout << bookingsOld[i] << endl;
    }
    return 0;
}