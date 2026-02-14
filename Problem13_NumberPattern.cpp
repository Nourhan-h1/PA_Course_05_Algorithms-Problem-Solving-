/*
    Program: Number Pattern Printer
    Description:
    This program reads a positive integer from the user
    and prints a number pattern.

    Each row prints the same digit starting from 1
    up to the entered number.

    Example:
    Input: 5

    Output:
    1
    22
    333
    4444
    55555
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

// Prints number pattern in ascending order
void PrintNumberPattern(int Number)
{
    for (int i = 1; i <= Number; i++)
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
    PrintNumberPattern(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}
