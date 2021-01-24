#include <iostream>
using namespace std;

//和为S的连续正数序列
//输入一个正数S，打印所有和为S的连续正数序列(至少含有两个数)
//例如：输入15，由于1+2+3+4+5 = 4+5+6 = 7+8 = 15，所以打印出3个连续序列1~5、4~6、7~8

void PrintContinuousSequence(int small, int big)
{
	for (int i = small; i <= big; ++i)
	{
		cout << i << " ";
	}
	cout << endl;
}

void FindContinuousSequence(int sum)
{
	if (sum < 3)
	{
		return;
	}

	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + big;

	while (small < middle)
	{
		if (curSum == sum)
		{
			PrintContinuousSequence(small, big);
		}

		while (curSum > sum && small < middle)
		{
			curSum -= small;
			small++;

			if (curSum == sum)
			{
				PrintContinuousSequence(small, big);
			}
		}

		big++;
		curSum += big;
	}
}

int main()
{
	int sum;
	while (cin >> sum)
	{
		FindContinuousSequence(sum);
	}

	system("pause");
	return 0;
}