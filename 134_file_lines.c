#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "test.txt"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // define & initialize pointer to file
    FILE *filePtr = NULL;

    // open file & store address in pointer
    filePtr = fopen(FILENAME, "r");
    if (filePtr == NULL) {
        printf("Error opening the file!\n");
        return -1;
    }

    // define variables to count
    char char_read;
    int lines_count = 1;

    while ((char_read = fgetc(filePtr)) != EOF)     // if not final character
        if (char_read == '\n' && ++lines_count);  // count if new line

    printf("Total lines in file: %d.", lines_count);

    // close file
    fclose(filePtr);
    filePtr = NULL;

    return 0;
}
