#include <iostream>
#include <algorithm>
using namespace std;

//我们把只包含因数2、3、5的数称作丑数
//求按从小到大的顺序的第1500个丑数，
//例如6、8都是丑数，但是14不是，因为他包含因子7，我们将1称作为第一个丑数

//判断一个数是否为丑数
bool IsUgly(int number)
{
	while (number % 2 == 0)
	{
		number /= 2;
	}
	while (number % 3 == 0)
	{
		number /= 3;
	}
	while (number % 5 == 0)
	{
		number /= 5;
	}

	return (number == 1) ? true : false;
}

//按照顺序判断数字是否为丑数
int GetUglyNumber(int index)
{
	if (index <= 0)
	{
		return 0;
	}

	int number = 0;
	int uglyFound = 0;
	while (uglyFound < index)
	{
		++number;

		if (IsUgly(number))
		{
			++uglyFound;
		}
	}
	return number;
}

int Min(int number1, int number2, int number3)
{
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;

	return min;
}

int GetUglyNumber_Solution2(int index)
{
	if (index <= 0)
	{
		return 0;
	}

	int* pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int* pMultiply2 = pUglyNumbers;
	int* pMultiply3 = pUglyNumbers;
	int* pMultiply5 = pUglyNumbers;

	while (nextUglyIndex < index)
	{
		int min = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		pUglyNumbers[nextUglyIndex] = min;

		while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
		{
			++pMultiply2;
		}
		while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
		{
			++pMultiply3;
		}
		while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
		{
			++pMultiply5;
		}
		++nextUglyIndex;
	}

	int ugly = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return ugly;
}

int main()
{
	while (1)
	{
		int number;
		cin >> number;

		cout << GetUglyNumber_Solution2(number) << endl;
	}
	system("pause");
	return 0;
}