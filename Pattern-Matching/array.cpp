#include <iostream>
using namespace std;
int main()
{
    string input, pattern;
    int i, j, count = 0;
    cout << "Enter the input text : ";
    getline(cin, input);
    cout << "Enter the pattern text : ";
    getline(cin, pattern);
    int txtLen = input.length();
    int patternLen = pattern.length();
    for (i = 0; i < txtLen; i++)
    {
        for (j = 0; j < patternLen; j++)
        {
            if (input[i + j] != pattern[j])
                break;
        }
        if (patternLen == j)
        {
            cout << "Pattern found in location : " << i << endl;
            count++;
        }
    }
    if (count == 0)
        cout << "Pattern not found in this text";
    else
        cout << "Number of occurences : " << count << " times" << endl;
    return 0;
}
