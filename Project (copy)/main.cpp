#include <iostream>
using namespace std;
#include <stdio.h>
#include "bits/stdc++.h"
#include <array>
///* Struct =====================================================
struct Booking
{
    int id, slots, days;
    double cost;
    string name;
    bool isBooked;
};
///* Global variables ===================================================
int length, i, flag, intInput;
int bookingsOld[5];
char charInput, initInput;
Booking bookings[5];

///* functions define ===================================================
void init();
int project();
char getUserInitInput();
int totalAvailableBookingSpace();
int printInitOptions();
int viewAllbookings();
int viewAllEmtpybookings();
void bookAnAvailableSpace();
void printAvailablebookingspace();
void removeBooking();
void removeBookingById(int id);
///! global variables
///* Main function ======================================================
///! Main function
int main()
{
    init();
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
        printAvailablebookingspace();
    else if (x == 'B')
        bookAnAvailableSpace();
    else if (x == 'P')
        viewAllbookings();
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
int viewAllbookings()
{
    flag = 0;
    cout << endl
         << "All bookings : " << endl;
    for (i = 0; i < length; i++)
    {
        if (bookings[i].isBooked)
        {
            flag = 1;
            cout << "ID : " << bookings[i].id << ", Name : " << bookings[i].name << ", Cost : " << bookings[i].cost << ", Slots : " << bookings[i].slots << ", For " << bookings[i].slots << "Days," << endl;
        }
    }
    if (flag == 0)
    {
        cout << "No bookings found." << endl;
    }
    return 0;
}
int viewAllEmtpybookings()
{
    flag = 0;
    cout << endl
         << "All Empty bookings : " << endl;
    for (i = 0; i < length; i++)
    {
        if (!bookings[i].isBooked)
        {
            flag = 1;
            cout << "ID : " << bookings[i].id << ", Cost : " << bookings[i].cost << endl;
        }
    }
    if (flag == 0)
    {
        cout << "No Empty bookings found." << endl;
    }
    return 0;
}
///! view all bookingsOld
void printAvailablebookingspace()
{
    flag = 0;
    for (i = 0; i < length; i++)
    {
        if (!bookings[i].isBooked)
        {
            flag++;
        }
    }
    cout << "Available booking space: " << flag << endl
         << endl;
}
///* Booking functions ==================================================
///! book an available space
void bookAnAvailableSpace()
{
    i = totalAvailableBookingSpace();
    if (i == 0)
    {
        cout << "No Empty bookings space found." << endl;
        return;
    }
    viewAllEmtpybookings();
    // TODO : get user input
}
///* Read functions =====================================================

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
void init()
{
    length = 5;
    for (i = 0; i < 6; i++)
    {
        bookings[i].id = i + 1;
        bookings[i].isBooked = false;
        bookings[i].cost = 500.0;
    }
} ///! get available booking space
int totalAvailableBookingSpace()
{
    flag = 0;
    for (i = 0; i < length; i++)
    {
        if (!bookings[i].isBooked)
        {
            flag++;
        }
    }
    return flag;
}