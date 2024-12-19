#include <iostream>

// Function for measuring array length
int a_length(char array[])
{
    int count = 0;
    // Count until null terminator '\0'
    for (int i = 0; array[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    char data[100];

    std::cout << "This is a program for even parity checking." << std::endl;
    std::cout << "Enter the data: " << std::endl;

    // Taking user input
    std::cin >> data;

    // Finding the user data length
    int length = a_length(data);
    int count = 0;

    // Counting the number of '1's in the data
    for (int i = 0; i < length; i++)
    {
        if (data[i] == '1')
        {
            count++;
        }
    }

    // Even parity check:
    // If count of '1's is even, parity bit = '0' (to keep total even)
    // If count of '1's is odd, parity bit = '1' (to make total even)
    char parityBit = (count % 2 == 0) ? '0' : '1';

    // Increase length by 1 for the parity bit
    int newLength = length + 1;

    // Shift the original data to the right by one position
    // to make room for the parity bit at the front
    for (int i = length; i >= 0; i--)
    {
        data[i + 1] = data[i];
    }

    // Insert the parity bit at the front
    data[0] = parityBit;

    // data[newLength] should still be '\0' after shifting
    data[newLength] = '\0';

    // Displaying the new array with parity bit
    std::cout << "After adding parity bit '" << parityBit << "' at the front of the data: " << std::endl;
    std::cout << data << std::endl;

    return 0;
}