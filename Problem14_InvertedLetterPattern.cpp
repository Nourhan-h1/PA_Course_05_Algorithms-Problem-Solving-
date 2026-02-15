/*
    Program: Inverted Letter Pattern
    Description:
    This program reads a positive integer from the user
    and prints an inverted letter pattern.

    The pattern starts from the highest letter based on
    the input number and prints characters in descending order.

    Note:
    ASCII value of 'A' = 65

    Example:
    Input: 4

    Output:
    DDDD
    CCC
    BB
    A
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

// Prints inverted letter pattern starting from highest letter
void PrintInvertedLetterPattern(int Number)
{
    cout << "\n";

    // Outer loop controls letters (starting from highest letter down to 'A')
    for (int i = 65 + Number - 1; i >= 65; i--)
    {
        // Inner loop controls how many times each letter is printed
        for (int j = 1; j <= Number - ((65 + Number - 1) - i); j++)
        {
            cout << char(i);   // Convert ASCII value to character
        }

        cout << endl;
    }
}

int main()
{
    PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a positive number?"));

    return 0;
}
