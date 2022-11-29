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
void removeBooking();

///! global variables
int length = 0;
int bookings[5];
char initInput, charInput;

///! print init options
void printInitOptions()
{
    cout << endl
         << "Choose what you want." << endl
         << "Enter 'E' to Check the total available booking space. " << endl
         << "Enter 'B' to book an available space. " << endl
         << "Enter 'R' to remove the booking. " << endl
         << "Enter 'P' to View all booked list. " << endl
         << "Enter : ";
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

///! view all bookings
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
        cout << endl
             << "Enter the booking number: ";
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

///! view All Bookings
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

///! remove booking
void removeBooking()
{
    charInput = 'Z';
    cout << endl
         << "Enter 'P' to remove by items Position." << endl
         << "Enter 'I' to remove by item." << endl
         << "Enter : ";
    cin >> charInput;
    if (charInput == 'P' || charInput == 'p')
    {
        }
    else if (charInput == 'I' || charInput == 'i')
    {
    }
    else
    {
        cout << endl
             << "Invalid input. Please try again." << endl;
        removeBooking();
    }
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