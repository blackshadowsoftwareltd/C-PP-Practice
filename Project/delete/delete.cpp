#include <iostream>
using namespace std;
#include "data/data.h"
#include "data/data.cpp"
#include "delete/delete.h"

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