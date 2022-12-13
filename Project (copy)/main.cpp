#include <iostream>
using namespace std;
#include <stdio.h>
#include "bits/stdc++.h"
#include <array>
///* Global variables ===================================================
int length, i, intInput;
int bookingsOld[5];
char charInput, initInput;
///* Struct =====================================================
struct Booking
{
    int id;
    string name;
};
Booking bookings[5];
///* functions define ===================================================

int project();
char getUserInitInput();
int availablebookingsOldpace();
int printInitOptions();
int viewAllbookingsOld();
void bookAnAvailableSpace();
void printAvailablebookingsOldpace();
void removeBooking();
void removeBookingById(int id);
///! global variables
///* Main function ======================================================
///! Main function
int main()
{

    while (true)
    {
        project();
    }

    return 0;
}
///* Project functions ==================================================
///! start the project
int project()
{
    char x = getUserInitInput();
    if (x == 'E')
        printAvailablebookingsOldpace();
    else if (x == 'B')
        bookAnAvailableSpace();
    else if (x == 'P')
        viewAllbookingsOld();
    // else if (x == 'R')
    // removeBooking();
    cout
        << endl;
    return 0;
}

///* Input functions ====================================================
///! get users init input
char getUserInitInput()
{
    printInitOptions();
    cin >> initInput;
    if (initInput == 'E' || initInput == 'e')
        return 'E';
    else if (initInput == 'B' || initInput == 'b')
        return 'B';
    else if (initInput == 'R' || initInput == 'r')
        return 'R';
    else if (initInput == 'P' || initInput == 'p')
        return 'P';
    else
    {
        cout << "Invalid input. Please try again." << endl;
        return getUserInitInput();
    }
}
///* Print functions ====================================================
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

///! view All bookingsOld
int viewAllbookingsOld()
{
    cout << endl
         << "All bookingsOld: " << endl;
    if (length == 0)
    {
        cout << "No bookingsOld." << endl;
        return 0;
    }

    for (i = 0; i < length; i++)
    {
        cout << bookingsOld[i] << endl;
    }
    return 0;
}
///! view all bookingsOld
void printAvailablebookingsOldpace()
{
    cout << "Available booking space: " << 5 - length << endl
         << endl;
}
///* Booking functions ==================================================
///! book an available space
void bookAnAvailableSpace()
{
    if (length < 5)
    {
        cout << endl
             << "Enter  : ";
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
///* Read functions =====================================================
///! get available booking space
int availablebookingsOldpace()
{
    cout << "Available booking space: " << 5 - length << endl;
    return 5 - length;
}
///* Remove functions ===================================================

///! remove booking
void removeBooking()
{
    if (length == 0)
    {
        cout << "No bookingsOld found to remove !!." << endl;
        return;
    }
    charInput = 'Z';
    intInput = -1;

    cout << endl
         << "Enter 'P' to remove by items Position." << endl
         << "Enter 'I' to remove by item ID." << endl
         << "Enter 'X' to Exit Previous." << endl
         << "Enter : ";
    cin >> charInput;
    ///? remove by position
    if (charInput == 'P' || charInput == 'p')
    {
        cout << endl
             << "Enter Position of data to remove ." << endl
             << "Enter : ";
        cin >> intInput;
        if (intInput < 1 || intInput > length)
        {
            cout << "Invalid input. Please try again." << endl;
            return removeBooking();
        }
        else
        {
            removeBookingById(intInput - 1);
        }
    }
    ///? remove by Item Id
    else if (charInput == 'I' || charInput == 'i')
    {
        // TODO: remove by item id
    }
    ///? Exit from deletion
    else if (charInput == 'X' || charInput == 'x')
    {
        return;
    }
    ///? Invalid input
    else
    {
        cout << endl
             << "Invalid input. Please try again." << endl;
        removeBooking();
    }
}
///! remove booking by id
void removeBookingById(int id)
{
    for (i = id; i < length; i++)
        bookingsOld[i - 1] = bookingsOld[i];
    cout << "Booking removed successfully." << endl;
    length = length - 1;
}

///* Helper functions ===================================================
