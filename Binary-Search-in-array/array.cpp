#include <iostream>
using namespace std;

int main()
{
    int size, i, item, start = 0;
    cout << "Enter the size of an Array : ";
    cin >> size;
    int arr[size], end = size - 1, mid = (start + end) / 2;
    cout << "Enter the elements of an Array : ";
    for (i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Inserted elements of Array is : ";
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << "\ Inserte the search Item : ";
    cin >> item;

    while (start <= end && arr[mid] != item)
    {
        if (item > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
        mid = (start + end) / 2;
    }

    if (arr[mid] == item)
        cout << mid << " is the location of this item " << item;
    else
        cout << "Item does not exis in this Array";

    cout << endl;
}
