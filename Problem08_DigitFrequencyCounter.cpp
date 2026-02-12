/*
    Program: Digit Frequency Counter
    Description:
    This program reads a positive integer from the user,
    then asks for a specific digit (0–9) and counts how many
    times that digit appears in the number.

    Example:
    Input:  122315
    Digit:  2
    Output: 2 appears 2 times
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

// Counts how many times a specific digit appears in a number
int CountDigitFrequency(int Number, short DigitToCheck)
{
    int Remainder = 0;
    int FrequencyCount = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;     // Extract last digit
        Number /= 10;                // Remove last digit

        if (DigitToCheck == Remainder)
        {
            FrequencyCount++;        // Increase counter if digit matches
        }
    }

    return FrequencyCount;
}

int main()
{
    int number = ReadPositiveNumber("Please enter the main number?");
    short DigitToCheck = ReadPositiveNumber("Please enter one digit to check?");

    cout << "\nDigit " << DigitToCheck
         << " Frequency is "
         << CountDigitFrequency(number, DigitToCheck)
         << " Time(s).\n";

    return 0;
}
