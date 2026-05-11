/*
    Program: Search For Number In Array
    Description:
    This program takes the number of elements from the user, fills an array 
    with random numbers (1-100), and searches for a specific value.

    Concept:
    - User Input: Defining array length dynamically.
    - Randomization: Populating the array with random values.
    - Sequential Search: Finding the index and order of a specific number.

    Example:
    Enter the number of elements: 
    5
    Array 1 elements: 22 45 67 12 89
    Please enter a number to search for? 67
    The number found in position: 2
    The number found its order: 3

    Problem: Search For Number In Random Array 
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

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for(int i = 0; i < arrLength; i++)
    {
        if(arr[i] == Number)
            return i;
    }
    return -1;
}

int ReadNumber()
{
    int Number;
    cout << "\nPlease enter a number to search for?\n";
    cin >> Number;
    
    return Number;
}

int main() {

    //Seeds the random number generator in c++ , called only once
    srand((unsigned)time(NULL));
    
    
    int arr[100];
    int arrLength;
    
    arrLength = ReadPositiveNumber("Enter the number of elements : ");
    FillArrayWithRandomNumbers(arr, arrLength);
    
    cout<< "\nArray 1 elements: \n";
    PrintArray(arr, arrLength);
    
    int Number = ReadNumber();
    
    short NumberPosition = FindNumberPositionInArray(Number, arr, arrLength);
    
    if(NumberPosition == -1)
    {
        cout << "the number is not found :-(\n";
    }else{
        cout << "The number found in position: " << NumberPosition << endl;
        cout << "The number found its order: " << NumberPosition + 1 << endl;
    }
    return 0;
}
