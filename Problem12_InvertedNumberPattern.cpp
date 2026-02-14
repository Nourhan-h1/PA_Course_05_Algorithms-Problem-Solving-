/*
    Program: Inverted Number Pattern
    Description:
    This program reads a positive integer from the user
    and prints an inverted number pattern.

    Each row prints the same digit starting from the input
    number down to 1.

    Example:
    Input: 5

    Output:
    55555
    4444
    333
    22
    1
*/

#include <iostream>
#include <string>
using namespace std;

// Reads a positive integer from the user (must be greater than 0)
int ReadPositiveNumber(string Message)
{
    int Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

// Prints inverted number pattern
void PrintInvertedNumberPattern(int Number)
{
    for (int i = Number; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

int main()
{
    PrintInvertedNumberPattern(
        ReadPositiveNumber("Please enter a positive number?")
    );

    return 0;
}
