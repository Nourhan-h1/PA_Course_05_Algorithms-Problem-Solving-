/*
    Program: Positive Numbers Counter in Random Array

    Description:
    Generates an array with random numbers from -100 to 100,
    prints the array elements, then counts and displays
    the number of positive elements in the array.

    Example:
    Input:  Size = 5
    Output: Array Elements = -12 45 0 20 -8
            Positive Numbers Count = 3
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
    
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillArray(int arr[100], int &arrLength)
{
    
    cout << "Enter the number of elements: \n";
    cin >> arrLength;
    
    for(int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(-100, 100);
    }
}

int PositiveCount(int arr[100], int arrLength)
{
    int positiveCount = 0;
    
    for(int i = 0; i < arrLength; i++) 
    {
        if(arr[i] >= 0)
        {
            positiveCount++;
        }
    }
    return positiveCount;
}

void PrintArray(int arr[100], int arrLength)
{
    
    for(int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
        
    cout << "\n";
}

int main() {
    //Seed random generator (should be called once at program start)
    srand((unsigned)time(NULL));
    
    int arr[100]; 
    int arrLength = 0;
    
    FillArray(arr, arrLength);
    
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);
    
    cout << "\nPositive Numbers count is: ";
    cout << PositiveCount(arr, arrLength) << endl;
    
    return 0;
}
    
