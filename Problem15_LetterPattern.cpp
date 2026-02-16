/*
    Program: Ascending Letter Pattern
    Description:
    This program reads a positive integer from the user
    and prints a letter pattern in ascending order.

    The pattern starts from the letter 'A', and each new line
    prints the next letter repeated more times than the previous line.

    Note:
    ASCII value of 'A' = 65

    Example:
    Input: 4

    Output:
    A
    BB
    CCC
    DDDD
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

// Prints ascending letter pattern starting from 'A'
void PrintLetterPattern(int Number)
{
    cout << "\n";

    // Outer loop controls letters (starting from 'A' upward)
    for (int i = 65; i <= 65 + Number - 1; i++)
    {
        // Inner loop controls how many times each letter is printed
        for (int j = 1; j <= i - 65 + 1; j++)
        {
            cout << char(i);   // Convert ASCII value to character
        }

        cout << endl;
    }
}

int main()
{
    PrintLetterPattern(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}
