/*
    Program: Sum of Two Random Arrays (Problem #30)
    
    Description:
    This program generates two separate arrays with random numbers, 
    then calculates their sum element by element into a third array.

    Logic:
    - Array 1 & Array 2: Populated using a shared random generation function.
    - Array Sum: Result[i] = Array1[i] + Array2[i].

    Example:
    Input: 3 elements
    Array 1: 10 20 30
    Array 2: 05 15 25
    -------------------
    Sum    : 15 35 55
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


void FillArrayWithRandomNum(int arr[100], int arrlength)
{

    for(int i = 0; i < arrlength; i++)
    {
        
        arr[i] = RandomNumber(1, 100);
        
    }
}

void SumOf2Array(int arr1[100],int arr2[100], int arrSum[100], int arrlength)
{
    
    for(int i = 0; i < arrlength; i++)
    {
        arrSum[i] = arr1[i] + arr2[i];
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
    
    
    int arr1[100];
    int arr2[100];
    int arrSum[100];
    int arrLength;
    
    arrLength = ReadPositiveNumber("Enter the number of elements: ");
    
    FillArrayWithRandomNum(arr1, arrLength);
    FillArrayWithRandomNum(arr2, arrLength);
    
    SumOf2Array(arr1, arr2, arrSum, arrLength);
    
    cout << "\n==============================================" << endl;
    cout<< "\nArray 1 elements: ";
    PrintArray(arr1, arrLength);
    
    cout<< "\nArray 2 elements: ";
    PrintArray(arr2, arrLength);
    
    cout << "\n==============================================" << endl;
    cout<< "Sum of array1  and array2 elements: ";
    PrintArray(arrSum, arrLength);
    
    return 0;
}
    
