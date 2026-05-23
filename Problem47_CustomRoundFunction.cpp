/*
    Program: Custom Round Function

    Description:
    Reads a floating-point number from the user,
    rounds it using a custom round function,
    then compares the result with the built-in C++ round function.

    Example:
    Input:  5.7
    Output: My Round Result: 6
            C++ Round Result: 6
*/

#include <iostream>
#include <cmath>
using namespace std;

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

float MyRound(float Number)
{
    int intPart;
    intPart  = int(Number);
    
    float fractionPart = GetFractionPart(Number);
    
    if(abs(fractionPart) >= 0.5)
    {
        if(Number > 0)
        {
            return ++intPart;
        }else{
            return --intPart;
        }
    }else{
        return intPart;
    }
    
}

float ReadNumber()
{
    float Number;   
        
    cout << "Please enter the number?\n";
    cin >> Number;
    
    return Number;
}

int main() {
    float Number = ReadNumber();
    
    cout << "\nMy Round Result: " << MyRound(Number);
    cout << "\nC++ Round Result: " << round(Number);
    
    return 0;
}
    
