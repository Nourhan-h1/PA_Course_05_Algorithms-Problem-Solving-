/*
    Program: Add Array Elements Dynamically
    Description:
    Allows the user to add numbers to an array one by one and stops 
    when the user chooses not to add more, then prints the array and its length.

    Concept:
    - Dynamic Input: Adding elements based on user's choice (Yes/No).
    - Array Manipulation: Passing array length by reference to update it globally.
    - Modular Design: Separate functions for reading, adding, and printing.

    Example:
    Please enter a number? 10
    Do you want to add more numbers? [0]:No,[1]:yes? 1
    Please enter a number? 20
    Do you want to add more numbers? [0]:No,[1]:yes? 0

    Array Length: 2
    Array Elements: 10 20 

    Problem: Add Array Elements 
*/

#include <iostream>
using namespace std;

int ReadNumber()
{
    int Number;
    cout << "Please enter a number? " << endl;
    cin >> Number;
    return Number;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arr[arrLength] = Number;
    
    arrLength++;
}

void InputUserNumbersInArray(int arr[100], int& arrLength)
{
    bool AddMore = true;
    
    do
    {
        AddArrayElement(ReadNumber(), arr, arrLength);
        
        cout << "\nDo you want to add more numbers? [0]:No,[1]:yes?" << endl;
        cin >> AddMore;
        
    }while(AddMore);
}

void PrintArray(int arr[100], int arrLength)
{
    
    for(int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100];
    int arrLength = 0;
    
    InputUserNumbersInArray(arr, arrLength);
    
    cout << "\nArray Length: " << arrLength << endl;
    cout << "Array Elements ";
    
    PrintArray(arr, arrLength);
    return 0;
}
    
