/*
    Program: Perfect Number Checker
    Description:
    This program reads a positive number from the user
    and checks whether it is a Perfect Number or not
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

// Checks if a number is a Perfect Number
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

// Prints whether the number is perfect or not
void PrintResults(int Number)
{
    if (IsPerfectNumber(Number))
        cout << Number << " is a Perfect Number\n";
    
    else
        cout << Number << " is NOT a Perfect Number\n";
        
}

int main()
{
    
    PrintResults(ReadPositiveNumber("Please enter a positive number?"));

    return 0;  
}
