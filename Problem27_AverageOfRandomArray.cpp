/*
    Program: Average of Random Array Elements 
    
    Description:
    This program calculates the average of randomly generated array elements 
    by reusing the summation logic.

    Concept:
    - Function Reuse: Calling SumArrayNumbers inside AverageOfArrayNumbers.
    - Type Casting: Ensuring float precision for accurate average calculation.
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

int SumArrayNumbers(int arr[100], int arrlength)
{
    int sumNumber = 0;
    for(int i = 0; i < arrlength; i++)
    {
        sumNumber += arr[i];
        
    }    
    return sumNumber;
}

float AverageOfArrayNumbers(int arr[100], int arrlength)
{
    return (float)SumArrayNumbers(arr, arrlength)/arrlength;
}

int main() {

    //Seeds the random number generator in c++ , called only once
    srand((unsigned)time(NULL));
    
    
    int arr[100];
    int arrlength;
    
    arrlength = ReadPositiveNumber("Enter the number of elements: ");
    FillArrayWithRandomNumbers(arr, arrlength);
    
    cout<< "\nRandom Array Elements: ";
    PrintArray(arr, arrlength);
    
    cout << "\Average of all numbers is: " 
         << AverageOfArrayNumbers(arr, arrlength) 
         << endl;
    
    return 0;
}
    
