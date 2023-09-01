#include <stdio.h>

int main()
{
    int age = 42;
    int* pAge = NULL;
    
    pAge = &age;

    printf("variable age's address is: %p\n", &age);
    printf("variable age's value is: %i\n", age);

    printf("pointer pAge's address is: %p\n", &pAge);
    printf("pointer pAge's value is: %p\n", pAge);
    printf("pointer pAge's pointed-to value is: %i\n", *pAge);

    return 0;
}
