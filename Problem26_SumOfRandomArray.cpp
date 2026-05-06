/*
    Program: Sum of Random Array Elements
       
    Description:
    This program generates an array of random numbers (1 to 100) based on 
    a user-defined length and calculates the total sum of all elements.

    Concept:
    - Modular Programming: Separation of concerns between array population and summation logic.
    - Mathematical Logic: Iterating through the array to accumulate values into a sum variable.
    - Clean Code: Consistent naming and clear user-facing messages.

    Example:
    Input: Enter the number of elements: 3
    Output:
        Random Array Elements: 10 20 30
        Sum of all numbers is: 60
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

int main() {

    //Seeds the random number generator in c++ , called only once
    srand((unsigned)time(NULL));
    
    
    int arr[100];
    int arrlength;
    
    arrlength = ReadPositiveNumber("Enter the number of elements: ");
    FillArrayWithRandomNumbers(arr, arrlength);
    
    cout<< "\nRandom Array Elements: ";
    PrintArray(arr, arrlength);
    
    cout << "\nSum Of all numbers is: " 
         << SumArrayNumbers(arr, arrlength) 
         << "\n";
    
    return 0;
}
    
