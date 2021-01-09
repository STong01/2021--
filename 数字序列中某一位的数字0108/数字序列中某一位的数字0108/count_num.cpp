#include <iostream>
using namespace std;

//数字以01234567891011121314...的格式序列化到一个字符序列中。在序列中，第五位（从0开始计数）是5，第13位是1，第19为是4。
//写一个函数，求任意第n位对应的数字

//得到m位的数字总共有多少个？
//例如：输入2，则返回两位数（10-99）的个数90
//输入3，则返回三位数（100-999）的个数900
int countOfIntegers(int digits)
{
	if (digits == 1)
	{
		return 10;
	}
	int count = (int)std::pow(10, digits - 1);
	return 9 * count;
}

//求第一个m位数
//例如：第一个两位数是10，第一个三位数是100
int beginNumber(int digits)
{
	if (digits == 1)
	{
		return 0;
	}
	return (int)std::pow(10, digits - 1);
}

//当我们知道要找那一位数字位于某m位数之中后，可以用下面函数找出那一位数字
int digitAtIndex(int index, int digits)
{
	int number = beginNumber(digits) + index / digits;
	int indexFromRight = digits - index%digits;
	for (int i = 1; i < indexFromRight; i++)
	{
		number /= 10;
	}
	return number % 10;
}

int digitAtIndex(int index)
{
	if (index < 0)
	{
		return -1;
	}

	int digits = 1;
	while (true)
	{
		int numbers = countOfIntegers(digits);
		if (index < numbers*digits)
		{
			return digitAtIndex(index, digits);
		}

		index -= digits * numbers;
		digits++;
	}
	return -1;
}

int main()
{
	int index;
	cin >> index;
	cout << digitAtIndex(index) << endl;

	system("pause");
	return 0;
}