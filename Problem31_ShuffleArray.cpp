/*
    Program: Shuffle Array (Problem #31)
    
    Description:
    This program initializes an array with ordered numbers from 1 to N, 
    then performs a random shuffle by swapping elements at randomly selected indices.

    Logic:
    - Filling: Populate the array with a sequential range (1, 2, 3, ... N).
    - Shuffling: Iterate through the array and swap two randomly generated 
      positions (index1 and index2) in each step.
    
    Example:
    Input: 5 elements
    Before Shuffle: 1 2 3 4 5
    After Shuffle : 4 2 5 1 3 (Example output)
*/

Int ReadPositiveNumber(string Message)
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


void FillArrayWith1ToN(int arr[100], int size)
{

    for(int i = 0; i < size; i++)
    {
        
        arr[i] = i+1;
        
    }
}

void Swap(int& num1, int& num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
    
}

void ShuffleArray(int arr[100], int arrlength)
{
    for(int i = 0; i < arrlength; i++)
    {
        int index1 =RandomNumber(1, arrlength) - 1;
        int index2 =RandomNumber(1, arrlength) - 1;
        
        Swap(arr[index1], arr[index2]);
    }    
}

void PrintArray(int arr[100], int arrlength)
{
    
    for(int i = 0; i < arrlength; i++)
        cout << arr[i] << " ";
        
    cout << "\n";
}

int main() {

    //Seeds the random number generator in c++ , called only once
    srand((unsigned)time(NULL));
    
    int arr[100];
    int arrLength;
    
    arrLength = ReadPositiveNumber("Enter the number of elements: ");
    
    FillArrayWith1ToN(arr, arrLength);
    
    cout << "\n==============================================" << endl;
    cout<< "\nArray elements before shuffle: \n";
    PrintArray(arr, arrLength);
    
    ShuffleArray(arr, arrLength);
    
    cout<< "\nArray elements after shuffle: \n";
    PrintArray(arr, arrLength);
    
    cout << "\n==============================================" << endl;
    
    return 0;
}
