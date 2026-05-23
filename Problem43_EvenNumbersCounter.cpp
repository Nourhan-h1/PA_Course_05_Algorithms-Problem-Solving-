/*
    Program: Even Numbers Counter in Random Array

    Description:
    Generates an array with random numbers from 1 to 100,
    prints the array elements, then counts and displays
    the number of even elements in the array.

    Example:
    Input:  Size = 5
    Output: Array Elements = 12 45 77 20 8
            Even Numbers Count = 3
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
        arr[i] = RandomNumber(1, 100);
    }
}

int EvenCount(int arr[100], int arrLength)
{
    int evenCount = 0;
    
    for(int i = 0; i < arrLength; i++) 
    {
        if(arr[i] % 2 == 0)
        {
            evenCount++;
        }
    }
    return evenCount;
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
    
    cout << "\nEven Numbers count is: ";
    cout << EvenCount(arr, arrLength) << endl;
    
    return 0;
}
    
