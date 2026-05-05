/*
    Program: Random Keys Generator (Formatted)
    Description:
    This program generates a specific number of random keys. Each key 
    consists of 4 blocks, each containing 4 capital letters, separated by hyphens.
    
    Key Features:
    - Modular Design: Separate functions for character, word, and key generation.
    - Scalability: Uses Enums to support different character types (Letters, Digits, Symbols).
    - Formatted Output: Automatically handles hyphen placement using loops.
    
    Example:
    Input: 2
    Output:
    Key [1] : QWXR-PLMK-NBVC-ZXSD
    Key [2] : ASDF-GHJK-LOPI-MNBV
  
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
    Digital = 4,  
};

int RandomNumber(int From, int To)
{
    //Function to generate a random number 
    
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
        
        case enCharType::Digital:
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
        word = word + GetRandomCharacter(CharType);
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

void GenerateKeys(short NumbeOfKeys)
{
    
    for(int i = 1; i <= NumbeOfKeys; i++)
    {
        cout << "Key [" << i << "] : " << GenerateKey() << endl;
    }
}

int main() {
    //Seeds the random number generator in c++ , called only once
    srand((unsigned)time(NULL));
    
    GenerateKeys(ReadPositiveNumber("Please enter how many keys to generate? \n "));
    
    return 0;
}
    
