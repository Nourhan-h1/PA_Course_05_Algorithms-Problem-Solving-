/*
    Program: Perfect Number Finder
    Description:
    This program reads a positive number (N) from the user
    and prints all "Perfect Numbers" from 1 to N.
    A perfect number is a positive integer that is equal to the sum of its proper divisors.
*/

#include <iostream>
#include <string>  
  

using namespace std;

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

// Function to check if a single number is Perfect
bool IsPerfectNumber(int Number)
{
    int sum = 0;
    
    for (int index = 1; index <= Number / 2; index++)
    {
        if (Number % index == 0)  
            sum += index;
    }
    
    return Number == sum;
}

void PrintPerfectNumbersFrom1ToN(int Number)
{

    cout << "\nPerfect Numbers from 1 to " << Number << " are:\n\n";
    
    for(int index = 1; index <= Number; index++)
    {
        if(IsPerfectNumber(index))
        {
            cout << index << "\n";
        }
    }
}

int main()
{
    
    PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number?"));

    return 0;  
}
