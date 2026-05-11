/*
    Program: Check If Number Exists In Array
    Description:
    Takes the number of elements from the user, fills an array with random 
    numbers (1-100), and checks if a specific number exists.

    Concept:
    - User Input: Defining array size and search value.
    - Randomization: Populating the array with random data.
    - Boolean Logic: Returning (Yes/No) based on search results.

    Example:
    Enter the number of elements : 5
    Array 1 elements: 10 20 30 40 50
    Please enter a number to search for? 30
    Number you are looking for is: 30
    Yes it is found :-)

    Problem: Is Number In Array 
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


int ReadNumber()
{
    int Number;
    cout << "\nPlease enter a number to search for?\n";
    cin >> Number;
    
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

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
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
    cout << "\n\nNumber you are looking for is: " << Number << endl;
    
    if(!IsNumberInArray(Number, arr, arrLength))
    {
        cout << "No, The number is not found :-(\n";
    }else{
        cout << "Yes it is found :-)\n";
    }
    return 0;
}
    
