#include <iostream>
using namespace std;

int main()
{
    int size, i, item, beg = 0;
    cout << "Enter the size of an Array : ";
    cin >> size;
    int arr[size], end = size - 1, mid = (beg + end) / 2;
    cout << "Enter the elements of an Array : ";
    for (i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Enserted elements of Array is : ";
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << "\nEnserted the search Item : ";
    cin >> item;

    while (beg <= end && arr[mid] != item)
    {
        if (item > arr[mid])
            beg = mid + 1;
        else
            end = mid - 1;
        mid = (beg + end) / 2;
    }

    if (arr[mid] == item)
        cout << mid << " is the location of this item " << item;
    else
        cout << "Item does not exis in this Array";

    cout << endl;
}