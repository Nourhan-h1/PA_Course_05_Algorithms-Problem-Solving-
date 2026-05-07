/*
    Program: Filter & Copy Prime Numbers
    Description: Populates an array and copies only prime elements to a second array.
    
    Example: 
    Original: [7, 10, 11, 15] 
    Primes:   [7, 11]
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

enum enPrimeNotPrime {Prime = 1, NotPrime = 2};

enPrimeNotPrime CheckPrime(int Number)
{
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


void FillArray(int arr[100], int arrlength)
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

void CopyOnlyPrimeNumbers(int arrSource[100],int arrDestination[100], int arrlength, int& arr2length)
{
    int counter = 0;
    for(int i = 0; i < arrlength; i++)
    {
        if(CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
        {
            arrDestination[counter] = arrSource[i];
            counter++;
        }
    }   
    
    arr2length = counter--;
}


int main() {

    //Seeds the random number generator in c++ , called only once
    srand((unsigned)time(NULL));
    
    
    int arr[100];
    int arr2[100];
    
    int arrLength;
    int arr2Length = 0;
    
    arrLength = ReadPositiveNumber("Enter the number of elements: ");
    FillArray(arr, arrLength);
    
    CopyOnlyPrimeNumbers(arr, arr2, arrLength, arr2Length);
    
    cout<< "\nArray 1 elements: ";
    PrintArray(arr, arrLength);
    
    cout << "\nPrime number in the random array: ";
    PrintArray(arr2, arr2Length);
    
    return 0;
}
    
