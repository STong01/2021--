#include <iostream>
using namespace std;

//数字在排序数组中出现的次数
//统计一个数字在排序数组中出现的次数
//输入排序数组{1,2,3,3,3,3,4,5}和数字3，由于数字3在数组中出现了4次，所以输出4

//二分法查找第一个k出现的位置
int GetFirstK(int* data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int middleIndex = (start + end) / 2;
	int minddleData = data[middleIndex];

	if (minddleData == k)
	{
		if (middleIndex > 0 && data[middleIndex - 1] != k || middleIndex == 0)
		{
			return middleIndex;
		}
		else
		{
			end = middleIndex - 1;
		}
	}
	else if (minddleData > k)
	{
		end = middleIndex - 1;
	}
	else
	{
		start = middleIndex + 1;
	}

	return GetFirstK(data, length, k, start, end);
}

//二分法查找最后一个k出现的位置
int GetLastK(int* data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int minddleIndex = (start + end) / 2;
	int minddleData = data[minddleIndex];

	if (minddleData = k)
	{
		if (minddleIndex < length - 1 && data[minddleIndex + 1] != k || minddleIndex == length - 1)
		{
			return minddleIndex;
		}
		else
		{
			start = minddleIndex + 1;
		}
	}
	else if (minddleData < k)
	{
		start = minddleIndex + 1;
	}
	else
	{
		end = minddleIndex - 1;
	}

	return GetLastK(data, length, k, start, end);
}

//数字k最后出现的下标 - 数字k最先出现的下标 + 1 = 数字k在数组中出现的次数
int GetNumberOfK(int* data, int length, int k)
{
	int number = 0;

	if (data != nullptr && length > 0)
	{
		int first = GetFirstK(data, length, k, 0, length - 1);
		int last = GetLastK(data, length, k, 0, length - 1);

		if (first > -1 && last > -1)
		{
			number = last - first + 1;
		}
	}

	return number;
}

int main1()
{
	int data[] = { 1, 2, 3, 3, 3, 3, 4, 5 };
	int length = sizeof(data) / sizeof(int*);
	cout << length << endl;
	cout << GetNumberOfK(data, length, 3) << endl;

	system("pause");
	return 0;
}