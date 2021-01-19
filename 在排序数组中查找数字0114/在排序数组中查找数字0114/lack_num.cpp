#include <iostream>
using namespace std;

//一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0~n-1之内。
//在范围0~n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字

//方法一：当0~n-1的数字之和S1 - 数组中所有的数字之和S2 = 缺失的数字
int GetMissingNumber1(const int* numbers, int length)
{
	if (numbers == nullptr || length < 0)
	{
		return -1;
	}

	int S1 = 0;
	S1 = length * (length + 1) / 2;

	int S2 = 0;
	for (int i = 0; i < length; ++i)
	{
		S2 += numbers[i];
	}

	return S1 - S2;
}

//方法二：数组为递增数组，所有的数字应该和他们的下标是相同的，当出现下标不相同的数字的时候，就是缺失的数字
int GetMissingNumber2(const int* numbers, int length)
{
	if (numbers == nullptr || length < 0)
	{
		return -1;
	}

	int left = 0;
	int right = length - 1;

	while (left <= right)
	{
		int middle = (left + right) >> 1;
		if (numbers[middle] != middle)
		{
			if (middle == 0 || numbers[middle - 1] == middle - 1)
			{
				return middle;
			}
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}

	if (left == length)
	{
		return length;
	}

	//无效的输入，比如数组不是按要求排序的
	//有数字不在0~n-1范围之内
	return -1;
}

int main2()
{
	const int numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15 };
	int length = sizeof(numbers) / sizeof(int*);
	cout << length << endl;
	cout << GetMissingNumber1(numbers, length) << endl;
	cout << GetMissingNumber2(numbers, length) << endl;
	system("pause");
	return 0;
}