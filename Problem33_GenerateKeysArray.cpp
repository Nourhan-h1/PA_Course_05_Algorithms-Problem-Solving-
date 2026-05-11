/*
    Program: Random Keys Generator Array
    Description:
    This program generates a set of random keys in the format (XXXX-XXXX-XXXX-XXXX)
    based on user input, stores them in a string array, and displays them.

    Concept:
    - Modular Programming: Using functions like GenerateKey and FillArray.
    - ASCII Management: Converting random integers to characters using ASCII codes.
    - Array Management: Populating and traversing a string array.
    - Randomization: Leveraging srand() and rand() for unpredictable output.

    Example:
    Input: How many keys do you want to generate? 2
    Output:
        Array [1] : ASDR-QWER-TYUI-PLKM
        Array [2] : NBVC-XSDW-ERFT-GHYU

    Problem: Fill Array with Generated Keys (Problem #33)
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enCharType{
    smallLetter = 1,
    CapitalLetter = 2,
    specialCharacter = 3,
    Digit = 4,  
};

int RandomNumber(int From, int To)
{
    // Generates a random number within a given range.
    
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

char GetRandomCharacter(enCharType CharType)
{
    switch(CharType)
    {
        case enCharType::smallLetter:
            return (char)RandomNumber(97, 122);
            
        case enCharType::CapitalLetter:
            return (char)RandomNumber(65, 90);    
            
        case enCharType::specialCharacter:
            return (char)RandomNumber(33, 47);    
        
        case enCharType::Digit:
            return RandomNumber(48, 57);    
            
    }        
    
    return '\0';
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


string GenerateWord(enCharType CharType, short length)
{
    string word;
    for(int i = 0; i < length; i++)
    {
        word += GetRandomCharacter(CharType);
    }
    
    return word;
}

string GenerateKey() 
{
    string key = "";
    for (int i = 1; i <= 4; i++)
    {
        key += GenerateWord(enCharType::CapitalLetter, 4);
        if(i < 4)
        {
            key += "-";
        }
    }
    return key;
}


void FillArrayWithKeys(string arr[100], int arrLength)
{

    for(int i = 0; i < arrLength; i++)
    {
        arr[i] = GenerateKey();
    }
    
}


void PrintStringArray(string arr[100], int arrLength)
{
    cout << "\nArray elements: \n\n";
    for(int i = 0; i < arrLength; i++)
    {
        cout << "Array [" << i + 1 << "] : " 
             << arr[i] 
             << "\n";
    }
    cout << "\n";
}

int main() {
    //Seeds the random number generator in c++ , called only once
    srand((unsigned)time(NULL));
    
    string arr[100];   
    int arrLength = 0;
    
    arrLength = ReadPositiveNumber("How many keys do you want to generate? \n ");
    
    FillArrayWithKeys(arr, arrLength);
    
    PrintStringArray(arr, arrLength);
    return 0;
}
    
