/*
    Program: Copy Array Elements 
    
    Description:
    Generates a random array and copies its elements into a second array.

    Concept:
    - Parallel Iteration: Accessing two arrays using the same index.
    - Logic: Assignment (arr2[i] = arr1[i]) element by element.

    Example:
    Input: 3 elements
    Array 1 elements:  10 50 30
    Array 2 elements:  10 50 30
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

void CopyArray(int arrSource[100],int arrDestination[100], int arrlength)
{
    for(int i = 0; i < arrlength; i++)
    {
        arrDestination[i] = arrSource[i];
    }   
}


int main() {

    //Seeds the random number generator in c++ , called only once
    srand((unsigned)time(NULL));
    
    
    int arr[100];
    int arr2[100];
    int arrLength;
    
    arrLength = ReadPositiveNumber("Enter the number of elements: ");
    FillArrayWithRandomNumbers(arr, arrLength);
    
    CopyArray(arr, arr2, arrLength);
    
    cout<< "\nArray 1 elements: ";
    PrintArray(arr, arrLength);
    
    cout << "\nArray 2 elements: ";
    PrintArray(arr2, arrLength);
    
    return 0;
}
