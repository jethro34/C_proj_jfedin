#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 50

struct item
{
    char *item_name;
    int quantity;
    float price;
    float amount; // = quantity * price;
};

void readItem(struct item *itemPtr)
{
    char temp_name[MAX_STR_LEN];
    printf("Enter item name: ");
    fgets(temp_name, MAX_STR_LEN, stdin);
    printf("\n");

    int i = -1;
    while (temp_name[++i] != '\n');
    temp_name[i] = '\0';

    itemPtr->item_name = (char*)malloc((i+1)*sizeof(char));  // i = strlen(temp_name) + 1
    if (itemPtr->item_name == NULL) {
        printf("Error allocating memory!");
        exit(-1);
    }

    strcpy(itemPtr->item_name, temp_name);

    printf("Enter quantity: ");
    scanf("%d", &itemPtr->quantity);
    getchar();
    printf("\n");

    printf("Enter price: ");
    scanf("%f", &itemPtr->price);
    getchar();
    printf("\n\n");

    itemPtr->amount = (float)itemPtr->quantity * itemPtr->price;
}

void printItem(struct item* itemPtr)
{
    printf("The item entered's name is: '%s'.\n", itemPtr->item_name);
    printf("The item entered's quantity is: %d\n", itemPtr->quantity);
    printf("The item entered's price is: $%.2f\n", itemPtr->price);
    printf("The item entered's amount is: $%.2f\n", itemPtr->amount);
}

int main()
{
    struct item item1;
    struct item *item1Ptr = &item1;

    readItem(item1Ptr);

    printItem(item1Ptr);

    free(item1Ptr->item_name);

    return 0;
}
