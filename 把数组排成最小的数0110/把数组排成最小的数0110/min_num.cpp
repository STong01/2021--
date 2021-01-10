#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//����һ�����������飬�����������е�����ƴ�������ų�һ������
//��ӡ��ƴ�ӳ���������������С��һ��
//���磺��������{3,32,321}�����ӡ����3���������ųɵ���С����321323

const int g_MaxNumberLength = 10;

char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

//����ȽϹ���
int compare(const void* strNumber1, const void* strNumber2)
{
	//����һ�������ַ����Ƶ�g_StrCombine1
	strcpy(g_StrCombine1, *(const char**)strNumber1);
	//���ڶ��������ַ�ƴ�ӵ�g_StrCombine1
	strcat(g_StrCombine1, *(const char**)strNumber2);

	//���ڶ��������ַ����Ƶ�g_StrCombine2
	strcpy(g_StrCombine2, *(const char**)strNumber2);
	//����һ�������ַ�ƴ�ӵ�g_StrCombine2
	strcat(g_StrCombine2, *(const char**)strNumber1);

	//�Ƚ�g_StrCombine1��g_StrCombine2�µ������ַ��Ƚ�
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