/*
    Program: Custom Square Root Function

    Description:
    Reads a number from the user,
    calculates the square root using a custom function
    based on the power function, then compares the result
    with the built-in C++ sqrt function.

    Example:
    Input:  25
    Output: My Sqrt Result: 5
            C++ Sqrt Result: 5
*/

#include <iostream>
#include <cmath>
using namespace std;

float MySqrt(float Number)
{    
    return pow(Number, 0.5);
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
    
    cout << "\nMy Sqrt Result: " << MySqrt(Number);
    cout << "\nC++ Sqrt Result: " << sqrt(Number);
    
    return 0;
}
    
