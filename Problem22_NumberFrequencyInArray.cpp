/*
    Program: Array Frequency Counter
    Description:
    This program reads a user-defined array and calculates how many times 
    a specific number (Target) appears within the array elements.

    Concept:
    - Uses Functions to separate logic from input/output (Clean Code).
    - Uses Pass-by-reference to manage array size dynamically.
    - Optimized with zero-based indexing for standard memory access.

    Example:
    Input: Array Elements: 10 20 10 30, Target: 10
    Output:
        Original array : 10 20 10 30
        Number 10 is repeated 2 time(s)

*/

#include <iostream>
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

void ReadArray(int arr[100], int& arrlength)
{
    cout << "Enter number of elements? \n";
    cin >> arrlength;
    
    cout << "\nEnter array elements? \n\n";
    
    for(int i = 0; i < arrlength; i++)
    {
        
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
    cout << endl;
}

void PrintArray(int arr[100], int arrlength)
{
    
    for(int i = 0; i < arrlength; i++)
        cout << arr[i] << " ";
        
    cout << "\n";
}

int TimesRepeated(int Number, int arr[100], int arrlength)
{
    int count = 0;
    
    for(int i = 0; i < arrlength; i++)
    {
        if(arr[i] == Number)
        {
            count++;
        }
        
    }
    return count;
}

int main() {
    
    int arr[100], arrlength, NumberToCheck;
    
    // Step 1: Input handling
    ReadArray(arr, arrlength);
    NumberToCheck = ReadPositiveNumber("\nEnter the number you want to check : ");
    
    // Step 2: Output original state
    cout<< "\nOriginal array : ";
    PrintArray(arr, arrlength);
    
    // Step 3: Display results
    cout << "\nNumber " << NumberToCheck 
         << " is repeated "
         << TimesRepeated(NumberToCheck, arr, arrlength) 
         << " time(s)" << endl;
    
    return 0;
}

