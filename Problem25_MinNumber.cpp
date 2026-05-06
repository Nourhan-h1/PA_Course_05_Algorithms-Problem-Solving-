/*
    Program: Min Number in Random Array
    Description:
    This program generates an array of random numbers (1 to 100) based on 
    a user-defined length and finds the minimum element.

    Concept:
    - Modular Programming: Dedicated function for each task (Input, Logic, Output).
    - Optimized Logic: Starting Min comparison from the second element (i=1).
    - Clean Code: Consistent naming conventions and independent functions.

    Example:
    Input: Enter the number of elements: 5
    Output:
        Random Array Elements: 88 12 45 3 19
        The min number is: 3

    Problem: Find Min Number in Array (Problem #25)
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
    //Function to generate a random number 
    
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}


void FillArrayWithRandomNumbers(int arr[100], int arrlength)
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

int FindTheMinNumber(int arr[100], int arrlength)
{
    int minNumber = arr[0];
    for(int i = 1; i < arrlength; i++)
    {
        
        if(arr[i] < minNumber)
        {
            minNumber = arr[i];
        }
        
    }    
    return minNumber;
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
    
    cout << "\nMin number is: " 
         << FindTheMinNumber(arr, arrlength) 
         << "\n";
    
    return 0;
}
    
