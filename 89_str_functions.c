#include <stdio.h>
#include <string.h>

const int MAX_STRING_LENGTH = 50;

void get_str_input(char in_str[])
{
	printf("Type in a word and hit 'Enter': ");
	scanf("%s", in_str);
	printf("\n");
	return;
}

void swap_char(char *ch1, char *ch2)
{
	char temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;
}

void str_reverse(char str0[])
{
	int i = 0;
	int j = strlen(str0) - 1;
	
	while (i++ < j--)
		swap_char(&str0[i-1], &str0[j+1]);
	
	return;
}

void get_str_arr_input(char strings[][MAX_STRING_LENGTH], int *strings_length)
{
	printf("Enter the size of the string array: ");
	scanf("%d", strings_length);
	printf("\n");
	
	int i;
	for (i = 0; i < *strings_length; i++)
		get_str_input(strings[i]);
}

void swap_str(char str1[], char str2[]) {
	char temp[50];
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}

void sort_str_arr(char strings[][MAX_STRING_LENGTH], int strings_length)
{
	int i, j;
	char key_str[MAX_STRING_LENGTH];
	for (i = 1; i < strings_length; i++) {
		strcpy(key_str, strings[i]);
		j = i - 1;
		
		while (j >= 0 && strcmp(strings[j], key_str) > 0) {
			strcpy(strings[j+1], strings[j]);
			j--;
		}
		strcpy(strings[j+1], key_str);
	}
}

void print_str_arr(char strings[][MAX_STRING_LENGTH], int strings_length)
{
	printf("The sorted array is: ");
	for (int i = 0; i < strings_length - 1 ; i++)
		printf("'%s', ", strings[i]);
	printf("and '%s'.\n\n", strings[strings_length - 1]);
}

int main()
{
	char in_str[50];
	get_str_input(in_str);
	
	str_reverse(in_str);
	printf("The reversed word is: %s\n\n", in_str);
	
	int strings_length = 10;
	char strings[10][MAX_STRING_LENGTH];
	get_str_arr_input(strings, &strings_length);
	sort_str_arr(strings, strings_length);
	print_str_arr(strings, strings_length);
	
	char str1[50] = "World!";
	char str2[50] = "Hello ";
	swap_str(str1, str2);
	printf("%s%s\n", str1, str2);
	
	return 0;
}