#include <iostream>
using namespace std;
#include <stdio.h>
#include "bits/stdc++.h"
#include <array>
#include "read/read.h"
#include "read/read.cpp"
#include "write/write.h"
#include "write/write.cpp"
#include "update/update.h"
#include "update/update.cpp"
#include "delete/delete.h"
#include "delete/delete.cpp"
#include "data/data.h"
#include "data/data.cpp"
#include "print/print.h"
#include "print/print.cpp"
#include "input/input.h"
#include "input/input.cpp"

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