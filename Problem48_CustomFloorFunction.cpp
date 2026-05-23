/*
    Program: Custom Floor Function

    Description:
    Reads a floating-point number from the user,
    calculates the floor value using a custom function,
    then compares the result with the built-in C++ floor function.

    Example:
    Input:  -5.7
    Output: My Floor Result: -6
            C++ Floor Result: -6
*/

#include <iostream>
#include <cmath>
using namespace std;

float MyFloor(float Number)
{
    int intPart = int(Number);

    if(Number > 0 || Number == intPart)
    {
        return intPart;
    }

    return intPart - 1;
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
    
    cout << "\nMy Floor Result: " << MyFloor(Number);
    cout << "\nC++ Floor Result: " << floor(Number);
    
    return 0;
}

