#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    int arr[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 60;
    cout << "Randomly Generated Array elements are: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << '\n';
    for (int step = 0; step < size; step++)
        for (int compare = 0; compare < size - step - 1; compare++)
            if (arr[compare] > arr[compare + 1])
                swap(arr[compare], arr[compare + 1]);
    cout << "Sorted Array elements are: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
