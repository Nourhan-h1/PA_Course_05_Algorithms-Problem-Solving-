/*
  Project: Array Copy Utility via AddArrayElement
  
  Description:
  This program generates a random array of a user-defined size and copies its 
  elements into a second array by adding them one-by-one. It demonstrates 
  the use of 'Pass by Reference' to manage the destination array's length.

  Example:
  - Input: Enter number of elements: 3
  - Array 1 (Randomly filled): 45 12 89
  - Copying process: Adds 45, then 12, then 89 to Array 2.
  - Output Array 2: 45 12 89

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


void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arr[arrLength] = Number;
    
    arrLength++;
}

void CopyArrayUsingAddArrayElement(int arrSource[100],int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    
    for(int i = 0; i < arrLength; i++)
    {
        AddArrayElement( arrSource[i],arrDestination,arrDestinationLength) ;
        
    }   
    
}


int main() {

    //Seeds the random number generator in c++ , called only once
    srand((unsigned)time(NULL));
    
    
    int arr[100];
    int arrLength;
    
    arrLength = ReadPositiveNumber("Enter the number of elements: ");
    FillArrayWithRandomNumbers(arr, arrLength);
    
    int arr2[100];
    int arr2Length = 0;
    
    CopyArrayUsingAddArrayElement(arr, arr2, arrLength, arr2Length);
    
    cout<< "\nArray 1 elements: ";
    PrintArray(arr, arrLength);
    
    cout << "\nArray 2 elements: ";
    PrintArray(arr2, arr2Length);
    
    return 0;
}
