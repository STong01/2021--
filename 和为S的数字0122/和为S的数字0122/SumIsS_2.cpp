#include <iostream>
using namespace std;

//和为S的两个数字
//输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S
//如果有多对数字的和等于S，则输出任意一对即可

//由于是排序数组，所以可以定义两个指针进行前后相加对比
//若两指针之和大于S我们可以将后面较大的指针往前移一位再进行求和对比
//若两指针之和小于S我们可以将前面较小的指针往后移一位再进行求和比较

bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2)
{
	bool found = false;
	if (length < 1 || num1 == nullptr || num2 == nullptr)
	{
		return found;
	}

	//定义较小数字的下标
	int ahead = 0;
	//定义较大数字的下标
	int behind = length - 1;

	while (ahead < behind)
	{
		long long curSum = data[ahead] + data[behind];

		if (curSum == sum)
		{
			*num1 = data[ahead];
			*num2 = data[behind];

			found = true;
			break;
		}
		else if (curSum > sum)
		{
			behind--;
		}
		else
		{
			ahead++;
		}
	}
	return found;
}

int main1()
{

	int data[] = { 1, 2, 4, 7, 11, 15 };
	int length = sizeof(data) / sizeof(int);
	int sum = 15;
	int num1 = 0;
	int num2 = 0;

	if (FindNumbersWithSum(data, length, sum, &num1, &num2))
	{
		cout << num1 << "  " << num2 << endl;
	}

	system("pause");
	return 0;
}