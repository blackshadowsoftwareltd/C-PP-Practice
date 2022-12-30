#include <iostream>
using namespace std;
#include <stdio.h>
#include "bits/stdc++.h"
#include <array>

///* ====================================================================
///* Struct =============================================================

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
void renewBookingDays();
void renewBookingById(int id);
///? global variables

///* ====================================================================
///* Main function ======================================================

////* Main function
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

////* start the project
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
    else if (x == 'H')
        renewBookingDays();
    cout
        << endl;
    return 0;
}

///* ====================================================================
///* Input functions ====================================================

////* get users init input
char getUserInitInput()
{
    try
    {
        printInitOptions();
        cin >> initInput;
    }
    catch (...)
    {
        return getUserInitInput();
    }
    if (initInput == 'E' || initInput == 'e')
        return 'E';
    else if (initInput == 'B' || initInput == 'b')
        return 'B';
    else if (initInput == 'R' || initInput == 'r')
        return 'R';
    else if (initInput == 'P' || initInput == 'p')
        return 'P';
    else if (initInput == 'H' || initInput == 'h')
        return 'H';
    else
    {
        cout << "Invalid input. Please try again." << endl;
        return getUserInitInput();
    }
}

///* ====================================================================
///* Print functions ====================================================

////* print init options
int printInitOptions()
{
    cout << endl
         << "Choose what you want." << endl
         << "Enter 'E' to check the total available booking space. " << endl
         << "Enter 'B' to book an available space. " << endl
         << "Enter 'P' to view all booked list. " << endl
         << "Enter 'H' To renew hiring days. " << endl
         << "Enter 'R' to remove the booking. " << endl
         << "Enter : ";
    return 0;
}

////* view All bookingsOld
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
            cout << "Slot ID : " << bookings[i].id << ", Name : " << bookings[i].name << ", Cost : " << bookings[i].cost << " TK, Slots : " << bookings[i].slots << ", For " << bookings[i].days << " Days," << endl;
        }
    }
    if (flag == 0)
    {
        cout << "No bookings found." << endl;
    }
    return 0;
}

////* view All Empty bookings
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

////* view all bookingsOld
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

////* print aditional info for booking
void printAditionalInfoForBooking()
{
    cout << "Slot cost per day BDT 100 TK" << endl;
}

///* ====================================================================
///* Booking functions ==================================================

////* book an available space
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
    try
    {
        cin >> slotNumber;
    }
    catch (char)
    {
        cout << "Invalid slot Id" << endl;
        return bookAnAvailableSpace();
    }
    catch (...)
    {
        cout << "Invalid slot Id" << endl;
        return bookAnAvailableSpace();
    }
    if (slotNumber < 1 || slotNumber > length)
    {
        cout << "Invalid slot Id" << endl;
        return bookAnAvailableSpace();
    }

    if (checkIsItEmtyBook(slotNumber) == 0)
    {
        cout << "There is no empty slot in this Number" << endl;
        bookAnAvailableSpace();
        return;
    }
    cout << "Enter you name : ";
    string name;
    try
    {
        // getline(cin, name);
        cin >> name;
    }
    catch (...)
    {
        cout << "Invalid name" << endl;
        bookAnAvailableSpace();
    }
    if (name.length() < 1)
    {
        name = "Name not found";
        // cout << "Name can not be empty" << endl;
        // bookAnAvailableSpace();
        // return;
    }
    cout << "Enter the number of days you want to book : ";
    int days = 0;
    try
    {
        cin >> days;
    }
    catch (...)
    {
        cout << "Invalid days" << endl;
        bookAnAvailableSpace();
    }
    if (days < 1 || days >= 10)
    {
        cout << "Days can not be less than 1 or " << endl;
        bookAnAvailableSpace();
        return;
    }
    bookings[slotNumber - 1].name = name;
    bookings[slotNumber - 1].days = days;
    bookings[slotNumber - 1].cost = 100 * days;
    bookings[slotNumber - 1].isBooked = true;
    cout << endl
         << "Booking done successfully." << endl;
    // cin>>bookings[i].name;
    // cout<<"Enter a slot number : ";
}

///* ====================================================================
///* Remove functions ===================================================

////* remove booking
void removeBooking()
{
    if (totalAvailableBookingSpace() == 0)
    {
        cout << "No bookings found to remove !!." << endl;
        return;
    }
    char inputForDelete = 'Z';
    int slID = -1;

    cout << endl
         << "Enter I to remove by item ID." << endl
         << "Enter 'X' to Exit Previous." << endl
         << "Enter : ";
    try
    {
        cin >> inputForDelete;
    }
    catch (...)
    {
        cout << endl
             << "Invalid input. Please try again." << endl;
        removeBooking();
    }
    ///? remove by Slot id
    ///? Exit from deletion
    if (inputForDelete == 'X' || inputForDelete == 'x')
    {
        return;
    }
    else if (inputForDelete == 'I' || inputForDelete == 'i')
    {
        cout << endl
             << "Enter the Slot ID to remove : ";
        try
        {
            cin >> slID;
        }
        catch (...)
        {
            cout << "Invalid input ID. Please try again." << endl;
            return removeBooking();
        }
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

    ///? Invalid input
    else
    {
        cout << endl
             << "Invalid input. Please try again." << endl;
        removeBooking();
    }
}

////* remove booking by id
void removeBookingById(int id)
{
    bookings[id - 1].isBooked = false;
    cout << "Booking removed successfully." << endl;
}

///* ====================================================================
///* update function ====================================================
void renewBookingDays()
{
    if (totalAvailableBookingSpace() == length)
    {
        cout << "No bookings found to rnew !!." << endl;
        return;
    }
    char inputForRenew = 'Z';
    int slIDFR = -1;

    cout << endl
         << "Enter I to renew by item ID." << endl
         << "Enter 'X' to Exit Previous." << endl
         << "Enter : ";
    try
    {
        cin >> inputForRenew;
    }
    catch (...)
    {
        cout << endl
             << "Invalid input. Please try again." << endl;
        renewBookingDays();
    }
    ///? Exit from deletion
    if (inputForRenew == 'X' || inputForRenew == 'x')
    {
        return;
    }
    ///? remove by Slot id
    else if (inputForRenew == 'I' || inputForRenew == 'i')
    {
        cout << endl
             << "Enter the Slot ID to remove : ";
        try
        {
            cin >> slIDFR;
        }
        catch (...)
        {
            cout << "Invalid input ID. Please try again." << endl;
            return renewBookingDays();
        }
        if (slIDFR < 1 || slIDFR > length)
        {
            cout << "Invalid input. Please try again." << endl;
            return renewBookingDays();
        }
        else
        {
            renewBookingById(slIDFR);
        }
    }

    ///? Invalid input
    else
    {
        cout << endl
             << "Invalid input. Please try again." << endl;
        renewBookingDays();
    }
}

///* renew booking by id
void renewBookingById(int id)
{
    int days = 0;
    cout << "Enter the number of days you want to renew : ";
    try
    {
        cin >> days;
    }
    catch (...)
    {
        cout << "Invalid days" << endl;
        renewBookingById(id);
    }
    if (days < 1)
    {
        cout << "Days can not be less than 1" << endl;
        renewBookingById(id);
        return;
    }
    bookings[id - 1].days = days;
    bookings[id - 1].cost = 100 * days;
    cout << "Booking renewed successfully." << endl;
}

///* ====================================================================
///* Helper functions ===================================================

////* init
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

////* total available booking space
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

////* check is it empty book
int checkIsItEmtyBook(int x)
{
    if (!bookings[x - 1].isBooked)
        return x;
    else
        return 0;
}