/*
    Program: Palindrome Number Checker
    Description:
    This program reads a positive integer from the user
    and checks whether it is a palindrome number or not.

    A palindrome number is a number that reads the same
    forward and backward.

    Example:
    Input:  121
    Output: Yes, it is a palindrome number.

    Input:  123
    Output: No, it is not a palindrome number.
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
    int remainder = 0;
    int reversedNumber = 0;

    while (Number > 0)
    {
        remainder = Number % 10;                         // Extract last digit
        reversedNumber = reversedNumber * 10 + remainder; // Build reversed number
        Number /= 10;                                    // Remove last digit
    }

    return reversedNumber;
}

// Checks if a number is palindrome
// Returns true if the number equals its reverse, otherwise false
bool IsPalindrome(int Number)
{
    return Number == ReverseNumber(Number);
}

int main()
{
    int number = ReadPositiveNumber("Please enter a positive number?");

    if (IsPalindrome(number))
        cout << "\nYes, it is a palindrome number.\n";
    else
        cout << "\nNo, it is NOT a palindrome number.\n";

    return 0;
}
