/*
    Program: Custom Ceil Function

    Description:
    Reads a floating-point number from the user,
    calculates the ceiling value using a custom function,
    then compares the result with the built-in C++ ceil function.

    Example:
    Input:  5.3
    Output: My Ceil Result: 6
            C++ Ceil Result: 6
*/

#include <iostream>
#include <cmath>
using namespace std;

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

float MyCeil(float Number)
{
    int intPart;
    intPart  = int(Number);
    
    float fractionPart = GetFractionPart(Number);
    if(abs(fractionPart) > 0)
    {
        if(Number > 0)
        {
            return intPart + 1;
        }else{
            return intPart;
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
    
    cout << "\nMy Ceil Result: " << MyCeil(Number);
    cout << "\nC++ Ceil Result: " << ceil(Number);
    
    return 0;
}
    
