/*
    Program: Copy Array in Reverse Order (Problem #32)
    
    Description:
    This program generates an array of random numbers and copies its elements 
    into a second array in reverse order.

    Logic:
    The destination array index 'i' receives the value from the source array 
    index [length - 1 - i].

    Example:
    Source Array: 10 20 30 40 50
    Reverse Array: 50 40 30 20 10
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

void CopyArrayInReverseOrder(int arrSource[100],int arrDestination[100], int arrlength)
{
    for(int i = 0; i < arrlength; i++)
    {
        arrDestination[i] = arrSource[arrlength - 1 - i];
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
    
    CopyArrayInReverseOrder(arr, arr2, arrLength);
    
    cout << "\n==============================================" << endl;
    cout<< "\nOriginal Array: \n";
    PrintArray(arr, arrLength);
    
    cout<< "\nArray elements after reversed: \n";
    PrintArray(arr2, arrLength);
    
    cout << "\n==============================================" << endl;
    
    return 0;
}
