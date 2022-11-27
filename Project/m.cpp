#include <iostream>
#include <stdio.h>
#include "bits/stdc++.h"
using namespace std;
char input;
void printOptions()
{
    cout << "Choose what you want." << endl
         << "Enter 'R' to show the list of bookings. ";
}
void getUserFirstInput()
{
    printOptions();
    cin >> input;
    cout << "You entered " << input << endl;
}
int main()
{
    getUserFirstInput();

    cout
        << endl;
    return 0;
}
