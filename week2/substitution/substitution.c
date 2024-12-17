#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void substitution(string text, string key);
bool validate_key(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    else if (!validate_key(argv[1]))
    {
        printf("Key is invalid!\n");
        return 1;
    }

    string plain = get_string("plaintext: ");
    substitution(plain, argv[1]);
    return 0;
}

void substitution(string text, string key)
{
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (!isalpha(text[i]))
        {
            continue;
        }
        if (isupper(text[i]))
        {
            text[i] = text[i] - 'A';               // change the range of letters to 0-25
            text[i] = toupper(key[(int) text[i]]); // swap to letter on key
        }
        else
        {
            text[i] = text[i] - 'a';               // change the range of letters to 0-25
            text[i] = tolower(key[(int) text[i]]); // swap to letter on key
        }
    }

    printf("ciphertext: %s\n", text);
}

/* Determine whether the key is valid or not*/
bool validate_key(string key)
{
    char unique[strlen(key) + 1];
    bool flag = true;
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            flag = false;
            break;
        }
        if (flag)
        {
            int counter = 0;
            while (counter < strlen(key))
            {
                if (counter == i) // ignore the same index.
                {
                    counter++;
                    continue;
                }

                if (toupper(key[i]) ==
                    toupper(key[counter])) // compare each letter with the rest for duplicates.
                {
                    flag = false;
                    break;
                }
                else
                {
                    counter++;
                }
            }
        }
        else
        {
            break;
        }
    }

    return flag;

    printf("%s\n", key);
}
