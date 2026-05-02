/*
    Program: AAA to ZZZ Generator
    Description:
    This program prints all 3-letter uppercase combinations
    in ascending alphabetical order, starting from "AAA"
    and ending with "ZZZ".

    Logic:
    The program uses three nested loops.
    Each loop iterates through the letters 'A' to 'Z',
    forming every possible combination of 3 characters.

    Total combinations:
    26 × 26 × 26 = 17576 combinations.

    Example Output (partial):
    AAA
    AAB
    AAC
    ...
    ZZY
    ZZZ
*/

#include <iostream>
#include <string>
using namespace std;
void PrintFromAAA_To_ZZZ() 
{
    cout << "\n";
    string word ="";
    
    for(char ch1 = 'A'; ch1 <= 'Z'; ch1++)    
    {
        for(char ch2 = 'A'; ch2 <= 'Z'; ch2++)    
        {
            for(char ch3 = 'A'; ch3 <= 'Z'; ch3++)    
            {
                word += ch1;  
                word += ch2;  
                word += ch3;
                cout << word << endl;
                
                word = "";
            } 
        }
    }
}
int main(){
    PrintFromAAA_To_ZZZ();
    return 0;
}


