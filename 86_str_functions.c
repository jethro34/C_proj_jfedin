#include <stdio.h>

int str_len(const char string[])
{
	int count = 0;
	while (string[count++] != '\0');	// inc count if not end
	return count;
}

void concat(const char str1[], const char str2[], char result[])
{
	int res_index = 0;
	int index = 0;
	while (str1[index++] != '\0')
		result[res_index++] = str1[index - 1];
	
	index = 0;
	while (str2[index++] != '\0')
		result[res_index++] = str2[index - 1];
	result[res_index] = '\0';
	
	return;
}

int are_equal(const char str1[], const char str2[])
{
	int index = 0;
	while (str1[index] == str2[index]) {
		if (str1[++index-1] == '\0')
			return 1;
	}
	return 0;
}

int main(void)
{
	char str1[] = "Hi!";
	printf("The string '%s' has %d characters.\n\n", str1, str_len(str1));
	
	const char str2[] = "Hello ";
	const char str3[] = "World!";
	int result_len = str_len(str2) + str_len(str3) - 1;
	char result[result_len];
	concat(str2, str3, result);
	printf("'%s' and '%s' together are '%s'\n\n", str2, str3, result);
	
	const char str4[] = "Ann";
	const char str5[] = "Ann";
	if (are_equal(str4, str5)) {
		printf("'%s' and '%s' are the same string.\n\n", str4, str5);
	} else {
		printf("'%s' and '%s' are different strings.\n\n", str4, str5);
	}
	
	return 0;
}