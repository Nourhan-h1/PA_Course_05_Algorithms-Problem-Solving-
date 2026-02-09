// Problem 01: Multiplication Table from 1 to 10
  
#include <iostream> 
#include <string>  


using namespace std;

// Prints the header of the multiplication table (1 to 10)
void PrintTableHeader()
{
    cout << "\n\n\t\t\t Multiplication Table From 1 to 10\n\n" << endl;
    cout << "\t" ;
    for(int i = 1;i <= 10; i++)
    {
        if (i < 2)
            cout << "\t" << i << "\t";
        else 
            cout << i << "\t";
           
    }
             
    cout << "\n__________________________________________________________________________________________\n";
}

string ColumnSeparator(int i)
{
    if(i < 10)
        return "     |";
    else
        return "    |";    
}
// Prints the full multiplication table
void PrintMultiplicationTable()
{
    PrintTableHeader();
    
    for(int i = 1; i <= 10; i++)
    {
        cout << " " << i << ColumnSeparator(i) << "\t";
        
        for(int j = 1; j <= 10; j++)
        {
             cout << i * j << "\t";     
        }
        cout << endl;
    }
}

int main()
{
    
    PrintMultiplicationTable();
    
    return 0;
}
