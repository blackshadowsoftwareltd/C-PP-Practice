#include <iostream>
#include <cstdio>
#include <cstring>

char dataArr[100], divs[100], temp[100], total[100];
int datalen, divlen, len, flag = 1;

void check_division()
{
    // Initialize remainder array with the first divlen bits of total
    for (int j = 0; j < divlen; j++)
        dataArr[j] = total[j];

    int j = divlen;
    // Perform the polynomial division (XOR operation)
    while (j <= len)
    {
        if (dataArr[0] == '1')
        {
            for (int i = 1; i < divlen; i++)
                dataArr[i] = (dataArr[i] == divs[i]) ? '0' : '1';
        }
        // Shift left by one
        for (int i = 0; i < divlen - 1; i++)
            dataArr[i] = dataArr[i + 1];

        if (j <= len)
        {
            dataArr[divlen - 1] = total[j];
            j++;
        }
    }
}

int main()
{
    std::cout << "Enter the total number of bits of data: ";
    std::cin >> datalen;

    std::cout << "Enter the total number of bits of divisor: ";
    std::cin >> divlen;

    len = datalen + divlen - 1;

    std::cout << "Enter the data: ";
    std::cin >> dataArr;

    std::cout << "Enter the divisor: ";
    std::cin >> divs;

    // Copy original data to total and temp
    for (int i = 0; i < datalen; i++)
    {
        total[i] = dataArr[i];
        temp[i] = dataArr[i];
    }

    // Append (divlen-1) zeros to the data in total
    for (int i = datalen; i < len; i++)
        total[i] = '0';
    total[len] = '\0';

    // Compute remainder for original data (to find CRC)
    check_division();

    // Append remainder to original data to form transmitted code word
    for (int i = 0; i < divlen - 1; i++)
        temp[datalen + i] = dataArr[i];
    temp[datalen + divlen - 1] = '\0';

    std::cout << "\nTransmitted Code Word: " << temp << std::endl;

    // Now verify the received code word
    std::cout << "\nEnter the received code word: ";
    std::cin >> total;

    check_division();

    // If remainder is zero (all '0's), then no error
    flag = 1;
    for (int i = 0; i < divlen - 1; i++)
    {
        if (dataArr[i] == '1')
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        std::cout << "\nNo errors detected! Successful.\n";
    else
        std::cout << "\nErrors detected in the received code word.\n";

    return 0;
}