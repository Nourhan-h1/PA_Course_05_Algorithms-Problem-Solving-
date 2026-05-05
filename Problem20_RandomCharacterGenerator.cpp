/*
    Program: Random Character Generator
    Description:
    This program generates random characters including 
    small letters, capital letters, digits, and special characters
    using ASCII values and a single function.

    Example:
    Input: enCharType::smallLetter
    Output: g

    Problem: Random Character Generator (One Function for all types)
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
    //Function to generate a random number 
    
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enum enCharType{
    smallLetter = 1,
    CapitalLetter = 2,
    specialCharacter = 3,
    Digital = 4,  
};

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

int main() {
    //Seeds the random number generator in c++ , called only once
    srand((unsigned)time(NULL));

    cout << GetRandomCharacter(enCharType::smallLetter) << endl;
    cout << GetRandomCharacter(enCharType::CapitalLetter) << endl;
    cout << GetRandomCharacter(enCharType::specialCharacter) << endl;
    cout << GetRandomCharacter(enCharType::Digital) << endl;
    
    return 0;
}
    
