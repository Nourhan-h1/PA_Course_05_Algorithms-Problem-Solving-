/*
    Program: Digit Printer
    Description:
    This program reads a positive number from the user
    and prints its digits in reverse order.
    The digits are extracted using modulus (%) and division (/).
*/

#include <iostream>
using namespace std;

// Reads a positive number from the user (greater than 0)
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

// Prints the digits of the number in reverse order
void PrintDigits(int Number)
{
    cout << "\nDigits of the number in reverse order:\n\n";

    while (Number > 0)
    {
        int digit = Number % 10;  // Extract last digit
        cout << digit << "\n";
        Number /= 10;             // Remove last digit
    }
}

int main()
{
    PrintDigits(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}
