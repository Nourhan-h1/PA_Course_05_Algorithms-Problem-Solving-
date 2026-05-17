/*
    Program: Distinct Numbers Copier
    Description:
    This program initializes an array with a set of numbers (some duplicated),
    checks each number to ensure it doesn't already exist in a destination array,
    and then copies only the distinct (unique) numbers into the second array.
*/

#include <iostream>
using namespace std;

void FillArray(int arr[100], int &arrlength)
{
    arrlength = 10;
    
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;    
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
    
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

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arr[arrLength] = Number;
    
    arrLength++;
}

void CopyDistinctNumbersToArray(int arrSource[100],int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    
    for(int i = 0; i < arrLength; i++)
    {
        if(!IsNumberInArray(arrSource[i], arrDestination, arrDestinationLength))
        {
            AddArrayElement( arrSource[i],arrDestination,arrDestinationLength) ;
        }
    }   
    
}


int main() {
    
    int arrSource[100], SourceLength = 0, arrDestination[100], DestinationLength = 0;
    FillArray(arrSource, SourceLength);
    
    
    cout<< "\nArray 1 elements: ";
    PrintArray(arrSource, SourceLength);
    
    CopyDistinctNumbersToArray(arrSource, arrDestination, SourceLength, DestinationLength);
    
    cout << "\nArray 2 distinct elements: ";
    PrintArray(arrDestination, DestinationLength);
    
    return 0;
}
