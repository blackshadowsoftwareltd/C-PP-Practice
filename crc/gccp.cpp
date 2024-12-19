#include <iostream>
#include <cstdio>
#include <cstring>

char data[100], divs[100], total[100], temp[100];
int dataLen, divLen, len, flag = 1;

void check_div()
{
    for (int x = 0; x < divLen; x++)
        data[x] = total[x];

    int j = divLen;

    while (j <= len)
    {
        if (data[0] == '1')
        {
            for (int i = 1; i < divLen; i++)
                data[i] = (data[i] == divs[i]) ? '0' : '1';
        }
        for (int x = 0; x < divLen - 1; x++)
            data[x] = data[x + 1];

        if (j <= len)
        {
            data[divLen - 1] = total[j];
            j++;
        }
    }
}

int main()
{
    std::cout << "Enter Data Len : ";
    std::cin >> dataLen;
    std::cout << "Enter Div Len : ";
    std::cin >> divLen;
    len = dataLen + divLen - 1;

    std::cout << "Enter data : ";
    std::cin >> data;
    std::cout << "Enter Div : ";
    std::cin >> divs;

    for (int x = 0; x < dataLen; x++)
    {
        total[x] = data[x];
        temp[x] = data[x];
    }
    for (int x = dataLen; x < len; x++)
        total[x] = '0';
    total[len] = '\0';

    for (int x = 0; x < dataLen; x++)
        std::cout << data[x];

    check_div();

    for (int x = 0; x < divLen - 1; x++)
        temp[dataLen + x] = data[x];
    temp[dataLen + divLen - 1] = '\0';

    std::cout << "\nTransmited : " << temp << std::endl;

    std::cout << "Enter you Transmited data : ";
    std::cin >> total;

    check_div();

    flag = 1;
    for (int x = 0; x < divLen - 1; x++)
    {
        if (data[x] == '1')
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        std::cout << "No Error Ditected";
    else
        std::cout << "Errors Detected";
    return 0;
}
