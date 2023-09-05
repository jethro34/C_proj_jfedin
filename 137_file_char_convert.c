#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SOURCE_FILE "source.txt"
#define DEST_FILE "dest.txt"

int main()
{
    FILE* sourcef_Ptr = NULL;
    FILE* destf_Ptr = NULL;
    char ch;

    // open source file in read mode
    sourcef_Ptr = fopen(SOURCE_FILE, "r");
    if (sourcef_Ptr == NULL) {
        printf("Error opening the file!");
        return -1;
    }

    // open destination file in write mode
    destf_Ptr = fopen(DEST_FILE, "w");
    if (destf_Ptr == NULL) {
        printf("Error opening the file!");
        return -1;
    }

    // read characters from source file
    while ((ch = fgetc(sourcef_Ptr)) != EOF) {
        if (islower(ch))
            ch = toupper(ch);               // change ch to uppercase
        fputc(ch, destf_Ptr);               // write ch to destination file
    }
    
    // close source file
    fclose(sourcef_Ptr);
    sourcef_Ptr = NULL;

    if (remove(SOURCE_FILE) != 0)               // delete source file
        printf("Error deleting source file!");

    // close destination file
    fclose(destf_Ptr);
    destf_Ptr = NULL;

    if (rename(DEST_FILE, SOURCE_FILE) != 0)    // rename destination file to source file
        printf("Error renaming destination file!");

    // open new source file in read mode
    sourcef_Ptr = fopen(SOURCE_FILE, "r");
    if (sourcef_Ptr == NULL) {
        printf("Error opening the file!");
        return -1;
    }
    
    printf("The contents of the source file are: \n\n");
    while ((ch = fgetc(sourcef_Ptr)) != EOF)
        printf("%c", ch);
    printf("\n\n");

    // close source file
    fclose(sourcef_Ptr);
    sourcef_Ptr = NULL;

    return 0;
}
