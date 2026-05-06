/*
    Program: Max Number in Random Array
    Description:
    This program generates an array of random numbers (1 to 100) and 
    identifies the highest value among them.

    Concept:
    - Modular Programming: Separation between input, filling, and searching logic.
    - Robust Logic: Initializing Max with the first element (arr[0]) for accurate comparison.
    - Clean Code: Using descriptive function names and clear structure.

    Example:
    Input: Enter the number of elements: 5
    Output:
        Random Array Elements: 15 67 2 99 40
        The max number is: 99

    Problem: Find Max Number in Array (Problem #24)
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

int FindTheMaxNumber(int arr[100], int arrlength)
{
    int maxNumber = arr[0];
    for(int i = 1; i < arrlength; i++)
    {
        
        if(arr[i] > maxNumber)
        {
            maxNumber = arr[i];
        }
        
    }    
    return maxNumber;
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
    
    cout << "\nThe max number is : " 
         << FindTheMaxNumber(arr, arrlength) 
         << "\n";
    
    return 0;
}
    
