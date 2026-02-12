/*
    Program: Print Digits in Original Order
    Description:
    This program reads a positive integer from the user
    and prints its digits in the correct (original) order.

    Idea:
    - First, reverse the number.
    - Then, extract and print each digit from the reversed number.
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

// Reverses a given number and returns the reversed value
int ReverseNumber(int Number)
{
    int Remainder = 0;
    int ReversedNumber = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;                          // Extract last digit
        ReversedNumber = ReversedNumber * 10 + Remainder; // Build reversed number
        Number /= 10;                                     // Remove last digit
    }

    return ReversedNumber;
}

// Prints each digit of the number separately
void PrintDigits(int Number)
{
    int Remainder = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;  // Extract last digit
        cout << Remainder << "\n";
        Number /= 10;             // Remove last digit
    }
}

int main()
{
    PrintDigits(
        ReverseNumber(ReadPositiveNumber("Please enter a positive number?"))
    );

    return 0;
}
