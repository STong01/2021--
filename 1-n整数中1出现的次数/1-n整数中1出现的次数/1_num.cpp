#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//����һ������n����1-n��n��������ʮ���Ʊ�ʾ��1���ֵĴ�����
int NumberOf1_1(unsigned int n)
{
	int number = 0;
	while (n)
	{
		if (n % 10 == 1)
		{
			number++;
		}
		n = n / 10;
	}
	return number;
}

int NumberOf1Between1AndN_1(unsigned int n)
{
	int number = 0;
	for (unsigned int i = 1; i <= n; i++)
	{
		number += NumberOf1_1(i);
	}
	return number;
}

int PowerBase10(unsigned int n)
{
	int result = 1;
	for (unsigned int i = 0; i < n; i++)
	{
		result *= 10;
	}

	return result;
}

int NumberOf1_2(const char* strN)
{
	if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
	{
		return 0;
	}

	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));

	if (length == 1 && first == 0)
	{
		return 0;
	}

	if (length == 1 && first > 0)
	{
		return 1;
	}

	//����strN�ǡ�21345��
	//numFirstDigit������10000-19999�ĵ�һλ�е���Ŀ
	int numFirstDigit = 0;
	if (first > 1)
	{
		numFirstDigit = PowerBase10(length - 1);
	}
	else if (first == 1)
	{
		numFirstDigit = atoi(strN + 1) + 1;
	}

	//numOtherDigits��1346-21345����һλ֮�����λ�е���Ŀ
	int numOtherDigits = first*(length - 1)*PowerBase10(length - 2);
	//numRecursive��1-1345�е���Ŀ
	int numRecursive = NumberOf1_2(strN + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}

int NumberOf1Between1AndN_2(int n)
{
	if (n <= 0)
	{
		return 0;
	}

	char strN[50];
	sprintf(strN, "%d", n);

	return NumberOf1_2(strN);
}

int main()
{
	unsigned int n;
	cin >> n;
	cout << NumberOf1Between1AndN_2(n) << endl;

	system("pause");
	return 0;
}