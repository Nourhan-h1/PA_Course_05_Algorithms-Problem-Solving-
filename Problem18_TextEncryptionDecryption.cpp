/*
    Program: Text Encryption and Decryption
    Description:
    This program reads text from the user,
    encrypts it by shifting each character
    using a fixed key, then decrypts it back
    to the original text.

    Logic:
    - Add the key value to each character for encryption.
    - Subtract the key value for decryption.

    Example:
    Input: Hello
    Encrypted: Jgnnq
    Decrypted: Hello
*/

#include <iostream>
#include <string>
using namespace std;

string readText()
{
    string text;
    cout << "Enter text: \n\n";
    
    getline(cin ,text);
    return text;
}

string EncryptText(string text, short EncryptionKey)
{
    
    for(int i = 0; i < text.length(); i++)
    {
        text[i] =char((int)text[i] + EncryptionKey);
    }
    
    return text;
}

string DecryptText(string text, short EncryptionKey)
{
    
    for(int i = 0; i < text.length(); i++)
    {
        text[i] =char((int)text[i] - EncryptionKey);
    }
    
    return text;
}

int main() {
    const short EncryptionKey = 2;
    
    string TextAfterEncryption, TextAfterDecryption;
    string Text =  readText();
    
    TextAfterEncryption = EncryptText(Text, EncryptionKey);
    TextAfterDecryption = DecryptText(TextAfterEncryption, EncryptionKey);
    
    cout << "\n■▪︎===========================▪︎■" << endl;
    cout << "\nText Before Encryption : " << Text << endl;
    cout << "\nText After Encryption : " << TextAfterEncryption << endl;
    cout << "\nText After Decryption : " << TextAfterDecryption << endl;
    cout << "\n■▪︎===========================▪︎■" << endl;
    return 0;
}

