#include <iostream>
#include <stdio.h>
#include "bits/stdc++.h"
#include <array>
using namespace std;
///! methods
int project();
void printInitOptions();
char getUserInitInput();
int availableBookingSpace();
void viewAllBookings();
void printAvailableBookingSpace();

///! global variables
int length = 0;
int bookings[5];
char initInput;

///! print init options
void printInitOptions()
{
    cout << endl
         << "Choose what you want." << endl
         << "Enter 'E' to Check the total available booking space. " << endl
         << "Enter 'B' to book an available space. " << endl
         << "Enter 'R' to remove the booking. " << endl
         << "Enter 'P' to View all booked list. " << endl;
}

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

///! get available booking space
int availableBookingSpace()
{
    cout << "Available booking space: " << 5 - length << endl;
    return 5 - length;
}
void printAvailableBookingSpace()
{
    cout << "Available booking space: " << 5 - length << endl
         << endl;
    project();
}

///! book an available space
void bookAnAvailableSpace()
{
    if (length < 5)
    {
        cout << "Enter the booking number: ";
        cin >> bookings[length];
        length++;
        cout << "Booking successful." << endl
             << endl;
    }
    else
    {
        cout << "No available booking space." << endl
             << endl;
    }
    project();
}
///! start the project
void viewAllBookings()
{
    cout << endl
         << "All bookings: " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << bookings[i] << endl;
    }
    cout << endl;
    project();
}
int project()
{
    char x = getUserInitInput();
    if (x == 'E')
        printAvailableBookingSpace();
    else if (x == 'B')
        bookAnAvailableSpace();
    else if (x == 'P')
        viewAllBookings();
    cout
        << endl;

    return 0;
}
///! Main function
int main()
{
    project();
    return 0;
}

//   cout << "The Length of the Array is : " << end(bookings) - begin(bookings); // length