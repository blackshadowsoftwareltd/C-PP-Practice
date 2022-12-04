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
void removeBookingById(int id);

///! global variables
int length = 0;
int bookings[5];
char initInput, charInput;
int i, intInput;

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
        cout << "No available booking space." << endl;
    }
}

///! view All Bookings
void viewAllBookings()
{
    cout << endl
         << "All bookings: " << endl;
    if (length == 0)
    {
        cout << "No bookings." << endl;
        return;
    }

    for (i = 0; i < length; i++)
    {
        cout << bookings[i] << endl;
    }
}

///! remove booking
void removeBooking()
{
    if (length == 0)
    {
        cout << "No bookings found to remove !!." << endl;
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
        bookings[i - 1] = bookings[i];
    cout << "Booking removed successfully." << endl;
    length = length - 1;
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