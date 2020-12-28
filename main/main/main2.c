#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

int main()
{
	char input;
	scanf("%c", &input);
	if (input >= '0' && input <= '9')
	{
		printf("digit\n");
	}
	else if (input >= 'a'&& input <= 'z')
	{
		printf("lower letter\n");
	}
	else if (input >= 'A' && input <= 'Z')
	{
		printf("capital letter\n");
	}
	else
	{
		printf("other charact\n");
	}
	return 0;
}