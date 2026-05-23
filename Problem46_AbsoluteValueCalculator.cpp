/*
    Program: Absolute Value Calculator

    Description:
    Reads a number from the user, calculates its absolute value
    using a custom function, then compares the result with
    the built-in C++ absolute function.

    Example:
    Input:  -15.5
    Output: My abs Result: 15.5
            C++ abs Result: 15.5
*/

#include <iostream>
using namespace std;

float MyABS(float Number)
{
    if(Number >= 0)
    {
        return Number;
    }else{
        return (-1*Number);
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
    
    cout << "\nMy abs Result: " << MyABS(Number);
    cout << "\nC++ abs Result: " << abs(Number);
    
    return 0;
}

