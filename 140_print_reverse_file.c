#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "file2reverse.txt"

/* Print contents of text file in reverse order */
int main()
{
    FILE* filePtr = NULL;
    int fpos;
    
    filePtr = fopen(FILENAME, "r");
    if (filePtr == NULL) {
        printf("Error opening the file!");
        return -1;
    }

    // set position to the end of the file
    fseek(filePtr, 0, SEEK_END);
    // store position in fpos
    fpos = ftell(filePtr);

    int ch;
    while (--fpos >= 0) {
        fseek(filePtr, fpos, SEEK_SET); // set position to previous byte
        ch = fgetc(filePtr);
        printf("%c", ch);
        if (ch == '\n' && --fpos);  // skip carriage return if newline
    }

    printf("\n");

    fclose(filePtr);
    filePtr = NULL;

    return 0;
}
