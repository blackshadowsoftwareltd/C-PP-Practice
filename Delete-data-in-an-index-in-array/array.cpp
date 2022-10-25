#include <iostream>
using namespace std;

int main()
{
    int size, position, i;
    cout << "Enter the array size : ";
    cin >> size;
    int arr[size];
    srand(time(0));
    for (i = 0; i < size; i++)
        arr[i] = rand() % 50;

    cout << "Generated Random number is : ";

    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    while (1)
    {
        cout << "\nEnter the position of deletion item : ";
        cin >> position;

        if (position < 0 || position > size)
        {
            cout << "\nEnter enter a valid position from 0 to " << size;
            continue;
        }

        for (i = position; i < size; i++)
            arr[i - 1] = arr[i];

        size = size - 1;

        cout << "Array size is " << size;
        cout << "\nFinal array elements is :";

        for (i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
}