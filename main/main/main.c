#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

int main1()
{
	int res = 0;
	int tmp;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &tmp);
		if (tmp <= 0)
		{
			printf("error\n");
			return 0;
		}
		if (tmp % 2 == 0)
		{
			res += tmp;
		}
	}
	printf("%d\n", res);
	return 0;
}
