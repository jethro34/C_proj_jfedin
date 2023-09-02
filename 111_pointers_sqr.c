#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sqr(int *pNum)
{
    *pNum *= *pNum;
}

int main()
{
    int num, sqr_num;

    printf("Enter a number: ");
    if (scanf("%d", &num) != 1)
        printf("Input Error!");
    printf("\n");

    sqr_num = num;

    sqr(&sqr_num);

    printf("The square of %d is %d.\n", num, sqr_num);

    return 0;
}
