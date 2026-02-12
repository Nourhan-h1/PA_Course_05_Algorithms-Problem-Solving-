/*
    Program: Sum of Digits Calculator
    Description:
    This program reads a positive integer from the user
    and calculates the sum of its digits.
    The digits are extracted using modulus (%) and division (/).
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

// Calculates and returns the sum of the digits of a number
int SumOfDigits(int Number)
{
    int digit = 0;
    int sum = 0;

    while (Number > 0)
    {
        digit = Number % 10;  // Extract the last digit
        sum += digit;         // Add digit to total sum
        Number /= 10;         // Remove the last digit
    }

    return sum;
}

int main()
{
    int result = SumOfDigits(
        ReadPositiveNumber("Please enter a positive number?")
    );

    cout << "\nSum Of Digits = " << result << "\n";

    return 0;
}
