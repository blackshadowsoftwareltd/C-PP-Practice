#include <iostream>
using namespace std;
#include <stdio.h>
#include "bits/stdc++.h"
#include <array>

///* ====================================================================
///* Struct =====================================================
struct Booking
{
    int id, slots, days;
    double cost;
    string name;
    bool isBooked;
};

///* ====================================================================
///* Global variables ===================================================
int length, i, flag, intInput, temp;
double doubleInput;
int bookingsOld[5];
char charInput, initInput;
string stringInput;
Booking bookings[5];

///* ====================================================================
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
void printAditionalInfoForBooking();
void removeBookingById(int id);
int checkIsItEmtyBook(int x);
///? global variables

///* ====================================================================
///* Main function ======================================================
///? Main function
int main()
{
    init();
    while (true)
    {
        project();
    }

    return 0;
}

///* ====================================================================
///* Project functions ==================================================
///? start the project
int project()
{
    char x = getUserInitInput();
    if (x == 'E')
        printAvailablebookingspace();
    else if (x == 'B')
        bookAnAvailableSpace();
    else if (x == 'P')
        viewAllbookings();
    else if (x == 'R')
        removeBooking();
    cout
        << endl;
    return 0;
}

///* ====================================================================
///* Input functions ====================================================
///? get users init input
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

///* ====================================================================
///* Print functions ====================================================
///? print init options
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
///? view All bookingsOld
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
            cout << "Slot ID : " << bookings[i].id << ", Name : " << bookings[i].name << ", Cost : " << bookings[i].cost << ", Slots : " << bookings[i].slots << ", For " << bookings[i].days << " Days," << endl;
        }
    }
    if (flag == 0)
    {
        cout << "No bookings found." << endl;
    }
    return 0;
}
///? view All Empty bookings
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
///? view all bookingsOld
void printAvailablebookingspace()
{
    flag = 0;
    flag = totalAvailableBookingSpace();
    cout << "Available booking slots : " << flag << endl;
    cout << " ";
    for (i = 0; i < length; i++)
    {
        if (!bookings[i].isBooked)
        {
            cout << "====";
        }
    }
    cout << "=" << endl;
    for (i = 0; i < length; i++)
    {
        if (!bookings[i].isBooked)
        {
            cout << " | " << bookings[i].id;
        }
    }
    cout << " |" << endl
         << " =";
    for (i = 0; i < length; i++)
    {
        if (!bookings[i].isBooked)
        {
            cout << "====";
        }
    }
    cout << endl;
}
///? print aditional info for booking
void printAditionalInfoForBooking()
{
    cout << "Slot cost per day BDT 100 TK" << endl;
}

///* ====================================================================
///* Booking functions ==================================================
///? book an available space
void bookAnAvailableSpace()
{
    i = totalAvailableBookingSpace();
    if (i == 6)
    {
        cout << "No Empty bookings space found." << endl;
        return;
    }

    printAvailablebookingspace();
    printAditionalInfoForBooking();
    int slotNumber = length + 1;
    cout << "Enter a slot number : ";
    cin >> slotNumber;
    if (slotNumber < 1 || slotNumber > length)
    {
        cout << "Invalid slot Id" << endl;
        bookAnAvailableSpace();
        return;
    }

    if (checkIsItEmtyBook(slotNumber) == 0)
    {
        cout << "There is no empty slot in this Number" << endl;
        bookAnAvailableSpace();
        return;
    }
    cout << "Enter you name : ";
    cin >> stringInput;
    if (stringInput.length() < 1)
    {
        cout << "Name can not be empty" << endl;
        bookAnAvailableSpace();
        return;
    }
    cout << "Enter the number of days you want to book : ";
    int days = 0;
    cin >> days;
    if (days < 1)
    {
        cout << "Days can not be less than 1" << endl;
        bookAnAvailableSpace();
        return;
    }
    bookings[slotNumber - 1].name = stringInput;
    bookings[slotNumber - 1].days = days;
    bookings[slotNumber - 1].cost = 100 * days;
    bookings[slotNumber - 1].isBooked = true;

    // cin>>bookings[i].name;
    // cout<<"Enter a slot number : ";
}

///* ====================================================================
///* Read functions =====================================================

///* ====================================================================
///* Remove functions ===================================================
///? remove booking
void removeBooking()
{
    if (totalAvailableBookingSpace() == 0)
    {
        cout << "No bookingsOld found to remove !!." << endl;
        return;
    }
    char inputForDelete = 'Z';
    int slID = -1;

    cout << endl
         << "Enter I to remove by item ID." << endl
         << "Enter 'X' to Exit Previous." << endl
         << "Enter : ";
    cin >> inputForDelete;
    ///? remove by Slot id
    if (inputForDelete == 'I' || inputForDelete == 'i')
    {
        cout << endl
             << "Enter the Slot ID to remove : ";
        cin >> slID;
        if (slID < 1 || slID > length)
        {
            cout << "Invalid input. Please try again." << endl;
            return removeBooking();
        }
        else
        {
            removeBookingById(slID);
        }
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
///? remove booking by id
void removeBookingById(int id)
{

    bookings[id - 1].isBooked = false;
    cout << "Booking removed successfully." << endl;
}

///* ====================================================================
///* Helper functions ===================================================
void init()
{
    length = 5;
    for (i = 0; i < 6; i++)
    {
        bookings[i].id = i + 1;
        bookings[i].isBooked = false;
        bookings[i].cost = 500.0;
        bookings[i].slots = 1;
    }
} ///! get available booking space
int totalAvailableBookingSpace()
{
    int f = 0;
    for (i = 0; i < length; i++)
    {
        if (!bookings[i].isBooked)
        {
            f++;
        }
    }
    return f;
}
int checkIsItEmtyBook(int x)
{
    if (!bookings[x - 1].isBooked)
        return x;
    else
        return 0;
}