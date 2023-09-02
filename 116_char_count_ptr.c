#include <stdio.h>

/*  Calculate length of string 
    Parameter: address to a string
    Return: Integer (length)    */
int char_count(const char *first_charPtr)
{
    // define pointer to last char, initialize it to first
    const char *last_charPtr = first_charPtr;
    
    // inc pointer to last char if not last char
    while (*last_charPtr++);

    // lenght is last - first pointer - 1
    return (int)(last_charPtr - first_charPtr - 1);
}

int main()
{   
    char str[] = "Hi";
    printf("The length of '%s' is %d\n", str, char_count(str));

    return 0;
}
