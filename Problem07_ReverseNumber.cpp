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

int ReverseNumber(int Number)
{
    int Number2 = 0, Reminder = 0;
    
    while (Number > 0)
    {
        Reminder = Number % 10;  // Extract the last digit
        Number = Number / 10;         // Remove the last digit
        Number2 = Number2 * 10 + Reminder;
    }

    return Number2;              // 12345
                                 // 54321 
}

int main()
{
    int result = ReverseNumber(
        ReadPositiveNumber("Please enter a positive number?")
    );

    cout << "\nReverse is:\n " << result << "\n";

    return 0;
}

