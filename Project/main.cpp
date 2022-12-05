#include <iostream>
#include <stdio.h>
#include "bits/stdc++.h"
#include <array>
#include "read.h"
#include "read.cpp"
#include "write.h"
#include "write.cpp"
#include "update.h"
#include "update.cpp"
#include "delete.h"
#include "delete.cpp"
#include "data.h"
#include "data.cpp"
#include "print.h"
#include "print.cpp"
#include "input.h"
#include "input.cpp"
using namespace std;
///! methods
int project();

int availableBookingSpace();

///! global variables

///! get available booking space
int availableBookingSpace()
{
    cout << "Available booking space: " << 5 - length << endl;
    return 5 - length;
}

///! start the project
int project()
{
    char x = getUserInitInput();
    if (x == 'E')
        printAvailableBookingSpace();
    else if (x == 'B')
        bookAnAvailableSpace();
    else if (x == 'P')
        viewAllBookings();
    else if (x == 'R')
        removeBooking();
    cout
        << endl;
    return 0;
}
///! Main function
int main()
{

    while (true)
    {
        project();
    }

    return 0;
}

//   cout << "The Length of the Array is : " << end(bookings) - begin(bookings); // length