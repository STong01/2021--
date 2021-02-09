#include <iostream>
#include <algorithm>
using namespace std;

//从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的
//2~10为数字本身，A为1，J为11，Q为12，K为13，而大小王可以看成任意数字。

int compare(const void* arg1, const void* arg2)
{
	return *(int*) arg1 - *(int*) arg2;
}

bool IsContinuous(int* numbers, int length)
{
	if (numbers == nullptr || length < 1)
	{
		return false;
	}

	qsort(numbers, length, sizeof(int), compare);

	int numberOfZero = 0;
	int numberOfGap = 0;

	//统计数组中0的个数
	for (int i = 0; i < length && numbers[i] == 0; i++)
	{
		++numberOfZero;
	}

	//统计数组中的间隔数目
	int small = numberOfZero;
	int big = small + 1;
	while (big < length)
	{
		//两数相等，有对子，不可能是顺子
		if (numbers[small] == numbers[big])
		{
			return false;
		}

		numberOfGap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}

	return (numberOfGap > numberOfZero) ? false : true;
}

int main()
{
	int numbers[] = { 0, 2, 6, 4, 5 };
	cout << IsContinuous(numbers, 5) << endl;

	system("pause");
	return 0;
}