#include <iostream>
using namespace std;

//假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
//一只股票在某些时间节点的价格为{9,11,8,5,7,12,16,14}。如果我们能在价格为5的时候买进并在价格为16时卖出，则能获得最大的利润11

int MaxDiff(const int* numbers, unsigned length)
{
	if (numbers == nullptr && length < 2)
	{
		return 0;
	}

	int min = numbers[0];
	int maxDiff = numbers[1] - min;

	for (int i = 2; i < length; i++)
	{
		if (numbers[i - 1] < min)
		{
			min = numbers[i - 1];
		}

		int currendDiff = numbers[i] - min;
		if (currendDiff > maxDiff)
		{
			maxDiff = currendDiff;
		}
	}
	return maxDiff;
}

int main()
{
	int numbers[] = { 9, 11, 8, 5, 7, 12, 16, 14 };

	cout << MaxDiff(numbers, 8) << endl;

	system("pause");
	return 0;
}