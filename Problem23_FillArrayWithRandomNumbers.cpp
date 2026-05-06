/*
    Program: Random Array Generator
    Description:
    This program generates an array of random numbers (1 to 100) based on 
    a user-defined length.

    Concept:
    - Modular Programming: Dedicated function for each task (Input, Logic, Output).
    - Single Responsibility: Separation between user input and array population.
    - Clean Code: Consistent naming conventions and independent functions.

    Example:
    Input: Enter the number of elements: 5
    Output:
        Random Array Elements: 42 12 85 3 99

    Problem: Fill Array with Random Numbers (Problem #23)
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
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

int RandomNumber(int From, int To)
{
    //Seed random generator (should be called once at program start)
    
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}


void FillArrayWithRandomNumbers(int arr[100], int& arrlength)
{

    for(int i = 0; i < arrlength; i++)
    {
        
        arr[i] = RandomNumber(1, 100);
        
    }
}

void PrintArray(int arr[100], int arrlength)
{
    
    for(int i = 0; i < arrlength; i++)
        cout << arr[i] << " ";
        
    cout << "\n";
}

int main() {

    //Seeds the random number generator in c++ , called only once
    srand((unsigned)time(NULL));
    
    
    int arr[100];
    int arrlength;
    
    arrlength = ReadPositiveNumber("Enter the number of elements : ");
    FillArrayWithRandomNumbers(arr, arrlength);
    
    cout<< "\nRandom Array Elements : ";
    PrintArray(arr, arrlength);
    
    
    return 0;
}
    
