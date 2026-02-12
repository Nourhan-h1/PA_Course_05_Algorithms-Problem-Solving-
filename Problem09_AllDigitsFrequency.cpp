/*
    Program: All Digits Frequency Counter
    Description:
    This program reads a positive integer from the user
    and prints the frequency of each digit (0–9) that appears in the number.

    Example:
    Input: 122315
    Output:
    Digit 1 Frequency is 2 Time(s).
    Digit 2 Frequency is 2 Time(s).
    Digit 3 Frequency is 1 Time(s).
    Digit 5 Frequency is 1 Time(s).
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
    int FrequencyCounter = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;   // Extract last digit
        Number /= 10;              // Remove last digit

        if (DigitToCheck == Remainder)
        {
            FrequencyCounter++;    // Increase counter if digit matches
        }
    }

    return FrequencyCounter;
}

// Prints the frequency of all digits (0–9) in the given number
void PrintAllDigitsFrequency(int Number)
{
    cout << "\nDigit Frequencies:\n\n";

    for (int digit = 0; digit < 10; digit++)
    {
        int DigitFrequency = CountDigitFrequency(Number, digit);

        if (DigitFrequency > 0)
        {
            cout << "Digit " << digit
                 << " Frequency is "
                 << DigitFrequency
                 << " Time(s).\n";
        }
    }
}

int main()
{
    int number = ReadPositiveNumber("Please enter the number?");
    PrintAllDigitsFrequency(number);

    return 0;
}
