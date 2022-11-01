#include <iostream>
using namespace std;

int main()
{
    int size, position, item, i;
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
        cout << "\nEnter the position of new item : ";
        cin >> position;
        cout << "Enter the new item : ";
        cin >> item;

        for (i = size - 1; i >= position; i--)
            arr[i + 1] = arr[i];

        arr[position] = item;
        size = size + 1;

        cout << "Array size is " << size;
        cout << "\nFinal array elements is :";

        for (i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
}