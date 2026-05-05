/*
    Program: Random Numbers Generator
    Description:
    This program generates and prints three random numbers 
    within a specific range [From, To] using the system time as a seed.

    Example:
    Input: Range (1 to 10)
    Output:
    7
    3
    5
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


int main() {
    //Seeds the random number generator in c++ , called only once
    srand((unsigned)time(NULL));

    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;
    
    return 0;
}
    
