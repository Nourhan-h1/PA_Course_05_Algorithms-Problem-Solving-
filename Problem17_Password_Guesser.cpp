/*
    Program: 3-Letter Password Guesser
    Problem Number: 17
    
    Description:
    This program asks the user for a 3-letter password.
    Then it tries all combinations from AAA to ZZZ
    to find the correct password.

    How it works:
    It uses 3 loops to make every possible word
    and compares it with the user's password.
*/

#include <iostream>
#include <string>
using namespace std;

string readPassword()
{
    string password;
    cout << "Enter a 3-letter UPPERCASE password" << endl;
    
    cin >> password;
    return password;
}

bool guessPassord(string correctPassword) 
{
    cout << "\n";
    string word ="";
    int counter = 0;
    
    for(char ch1 = 'A'; ch1 <= 'Z'; ch1++)    
    {
        for(char ch2 = 'A'; ch2 <= 'Z'; ch2++)    
        {
            for(char ch3 = 'A'; ch3 <= 'Z'; ch3++)    
            {
                word += ch1;  
                word += ch2;  
                word += ch3;
                counter++;                
                
                cout << "Trial [" << counter << "]: " << word << endl;
                
                if(word == correctPassword)
                {
                    cout << "\n";
                    cout << "Password is " << word<< endl;
                    cout << "Found after : " << counter << " Trial(s)" << endl;
                    return true;
                }
                
                word = "";
                
            } 
        }
    }
    cout << "\nPassword not found" << endl;
    return false;
}
int main(){
    guessPassord(readPassword());
    return 0;
}
