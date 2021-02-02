//substitution

#include <cs50.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

//declare modules
bool oKey_check(string key);


int main(int argc, string argv[])
{   
    // Declare varibles
    string key = argv[1];
    
    // check user uses one argument only
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    //check if key is valid
    if (oKey_check(key) == true)
    {
        printf("Key is correct\n");
    }
    
    else
    {
        printf("Key is false\n");
        return 1;
    }
    
    //get a passage of text from the user to check
    string user_input = get_string("plain text: "); 
    
    
    // declare viables
    int char_count = strlen(user_input);
    char ciphertext[char_count - 1];
    string abc = "abcdefghijklmnopqrstuvwxyz";
    int c;
    
    for (int i = 0; i < char_count; i++)
    {
        
        //check if current char is a letter & uppercase
        if ((user_input[i] >= 'A' && user_input[i] <= 'Z'))
        {

            for (int j = 0; j < 26; j++)
            {
                if (toupper(abc[j]) == user_input[i])
                {
                    ciphertext[i] = toupper(key[j]);
                    break;
                }
            }
            
        }
        
        //check if current char is a letter & lowercase
        else if ((user_input[i] >= 'a' && user_input[i] <= 'z'))
        {
            for (int j = 0; j < 26; j++)
            {
                if (abc[j] == user_input[i])
                {
                    ciphertext[i] = tolower(key[j]);
                    break;
                }
            }
        }
        
        //catch spaces numbers and punctuation
        else
        {
            ciphertext[i] = user_input[i];
        }
 
    }
    
    //add \0 to terminate ciphertext array
    ciphertext[char_count] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}



bool oKey_check(string key)
{
    //declare variables
    char c;
    
    //check key length = 26
    if (strlen(key) != 26)
    {   
        printf("not 26 chars\n");
        return false;
    }


    // loop through all characters in string
    for (int i = 0; i < 26; i++)
    {
        c = toupper(key[i]);
        
        // check c is a char
        if ((c >= 'A' && c <= 'Z'))
        {
            //printf("%c is a char\n", c);
        }
        else
        {   
            printf("%c is not a char\n", c);
            return false;
        }
        
        // loop each letter in the string after itself
        for (int j = i + 1; j < 26; j++)
        {
            //
            if ((int) c == toupper(key[j])) //|| ((int) c + 32 == key[j]) || ((int) c - 32 == key[j]))
            {
                printf("Two letters are the same: %c and %c\n", c, key[j]);
                return false;
            }
        }
    }
    
    return true;
}
