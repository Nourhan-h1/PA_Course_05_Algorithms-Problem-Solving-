#include <iostream>
#include <string>  
  
using namespace std;

// Enum to represent if number is Prime or Not
enum enPrimNotPrime { Prime = 1, NotPrime = 0};

// Reads a positive number from user
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

// Checks whether a number is Prime or Not
enPrimNotPrime CheckPrime(int Number)
{
    if (Number < 2)
        return enPrimNotPrime::NotPrime;


    for (int Counter = 2; Counter * Counter <= Number; Counter++)
    {
        if (Number % Counter == 0)  
            return enPrimNotPrime::NotPrime;
    }

    return enPrimNotPrime::Prime;  
}

// Prints all prime numbers from 2 to N
void PrintNumberType(int Number)
{
    
    cout << "\nPrime Numbers from 2 To " << Number << " are:\n\n";
    
    int index = 2;
    while(index <= Number)
    {
         if(CheckPrime(index) == enPrimNotPrime::Prime) 
             cout << index << "\n";
         
         index++;
    }
}

int main()
{
    
    PrintNumberType(ReadPositiveNumber("Please enter a positive number?"));

    return 0;  
}
 
