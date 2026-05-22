/*
    Program: Palindrome Array Checker 
    Description: Checks if a user-input array reads the same forward and backward.

    Example:
    Input:  Size = 5 | Elements = 10 20 30 20 10
    Output: Yes, array is Palindrome
*/

#include <iostream>
using namespace std;

void FillArray(int arr[100], int &arrLength)
{
    cout << "\nArray elements" << endl;
    for(int i = 0; i < arrLength; i++)
    {
        cin >> arr[i];
    }
}


bool IsPalindromeArray(int arr[100], int arrLength)
{
    for(int i = 0; i < arrLength / 2; i++) 
    {
        if(arr[i] != arr[arrLength - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main() {
    int arrSource[100], arrLength = 0;
    
    cout << "Enter the number of elements: " << endl;
    cin >> arrLength;
    
    FillArray(arrSource, arrLength);
    
    if(IsPalindromeArray(arrSource, arrLength))
        cout << "\nYes, array is Palindrome\n";
    else
        cout << "\nNo, array is Not Palindrome\n";    
        
    return 0;
}
