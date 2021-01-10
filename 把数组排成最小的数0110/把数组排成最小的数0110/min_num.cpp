#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//输入一个正整数数组，把数组里所有的数字拼接起来排成一个数，
//打印能拼接出的所有数字中最小的一个
//例如：输入数组{3,32,321}，则打印出这3个数字能排成的最小数字321323

const int g_MaxNumberLength = 10;

char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

//定义比较规则
int compare(const void* strNumber1, const void* strNumber2)
{
	//将第一个数字字符复制到g_StrCombine1
	strcpy(g_StrCombine1, *(const char**)strNumber1);
	//将第二个数字字符拼接到g_StrCombine1
	strcat(g_StrCombine1, *(const char**)strNumber2);

	//将第二个数字字符复制到g_StrCombine2
	strcpy(g_StrCombine2, *(const char**)strNumber2);
	//将第一个数字字符拼接到g_StrCombine2
	strcat(g_StrCombine2, *(const char**)strNumber1);

	//比较g_StrCombine1和g_StrCombine2新的数字字符比较
	return strcmp(g_StrCombine1, g_StrCombine2);
}

void PrintMinNumber(int* numbers, int length)
{
	if (numbers == nullptr || length < 0)
	{
		return;
	}

	char** strNumbers = (char**)(new int[length]);
	for (int i = 0; i < length; i++)
	{
		strNumbers[i] = new char[g_MaxNumberLength + 1];
		sprintf(strNumbers[i], "%d", numbers[i]);
	}

	qsort(strNumbers, length, sizeof(char*), compare);

	for (int i = 0; i < length; i++)
	{
		printf("%s", strNumbers[i]);
	}
	printf("\n");

	for (int i = 0; i < length; i++)
	{
		delete[] strNumbers[i];
	}
	delete[] strNumbers;
}

int main()
{

	system("pause");
	return 0;
}