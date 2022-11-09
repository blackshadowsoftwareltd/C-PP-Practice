#include <iostream>
using namespace std;
  int main()
{
    int size, i, item, position = 0;
    cout << "Enter the size of an Array : ";

    cin >> size;
    int arr[size];

    cout << "Enter the elements of an Array : ";
    for (i = 0; i < size; i++)
        cin >> arr[i];

      cout << "Inserted elements of Array is : ";
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << "\Insert the search Item : ";
    cin >> item;

      while (arr[position] != item && position < size)
        position++;
      if (position == size)
            cout
        << "Item does not exis in this Array";
    else cout << position << " is the location of this item " << item;

      cout << endl;
}
