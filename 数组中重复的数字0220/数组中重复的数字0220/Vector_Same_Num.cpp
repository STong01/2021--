#include <iostream>
#include <vector>
using namespace std;

int GetSize(int data[])
{
	return sizeof(data);
}

//找出数组中重复的数字
//在一个长度为n的数组里的所有数字都在0-n-1的范围内，数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了多少次
//请找出数组中任意一个重复的数字
bool duplicate(int numbers[], int length)
{
	if (numbers == nullptr || length <= 0)
	{
		return false;
	}

	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
		{
			return false;
		}
	}

	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				//*duplication = numbers[i];
				return true;
			}

			//swap numbers[i] and numbers[numbers[i]]
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}

int main1()
{
	int data1[] = { 1, 2, 3, 4, 5 };
	int size1 = sizeof(data1);

	int* data2 = data1;
	int size2 = sizeof(data2);

	int size3 = GetSize(data1);

	printf("%d,%d,%d\n", size1, size2, size3);

	int numbers[] = { 2, 3, 1, 0, 2, 5 };
	int length = sizeof(numbers) / sizeof(int);
	cout << length << endl;
	int* duplication = { 0 };
	cout << duplicate(numbers, length)<< endl;

	system("pause");
	return 0;
}