#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   
    // declare variables
    int arr_size = 0;
    char *arrPtr = NULL;

    // get size input
    printf("Length of the string: ");
    if (scanf("%d", &arr_size) != 1) {
        printf("Input error!");
        return 1;   // send error code to indicate failure
    }

    // empty input buffer by reading '\n' char left from scanf
    if (getchar() == EOF) {
        printf("Input error!");
        return 1;   // send error code to indicate failure
    }

    printf("\n");

    // allocate memory from size
    arrPtr = (char*)malloc((arr_size + 1) * sizeof(char));
    if (!arrPtr) {
        printf("Failure allocating memory!");
        return 1;   // send error code to indicate failure
    }
    
    // get str input and store in pointer
    printf("Enter the string: ");
    fgets(arrPtr, arr_size + 1, stdin);
    printf("\n");

    // remove trailing '\n' & replace w/ NULL terminator
    int i = -1;
    while (*(arrPtr + ++i) != '\n');
    *(arrPtr + i) = '\0';

    // print str input from pointer
    printf("The string entered was: \n");
    printf("'%s'\n\n", arrPtr);
    
    // free allocated memory
    free(arrPtr);
    arrPtr = NULL;

    return 0;
}
