/*
    Program: Prime Numbers Copier
    Description:
    This program reads a positive number as array length,
    fills the array with random numbers from 1 to 100,
    and then copies only the prime numbers into a second array.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

enum enPrimeNotPrime {Prime = 1, NotPrime = 2};

enPrimeNotPrime CheckPrime(int Number)
{
    if (Number <= 1) 
        return enPrimeNotPrime::NotPrime;  

    for(int i = 2; i <= sqrt(Number); i++)
    {
        if(Number % i == 0)
        {
            return enPrimeNotPrime::NotPrime;
        }
    }
    return enPrimeNotPrime::Prime;
}

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

void CopyPrimeNumbers(int arrSource[100],int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    
    for(int i = 0; i < arrLength; i++)
    {
        if(CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
        {
            AddArrayElement( arrSource[i],arrDestination,arrDestinationLength) ;
        }
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
    
    CopyPrimeNumbers(arr, arr2, arrLength, arr2Length);
    
    cout<< "\nArray 1 elements: ";
    PrintArray(arr, arrLength);
    
    cout << "\nArray 2 prime elements: ";
    PrintArray(arr2, arr2Length);
    
    return 0;
}
