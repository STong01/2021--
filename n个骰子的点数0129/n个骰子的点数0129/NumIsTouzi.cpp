#include <iostream>
using namespace std;

//把n个骰子扔到地上，所有骰子朝上一面的点数之和为s。输入n，打印出s所有可能的值出现的概率

int g_maxValue = 6;

void Probability(int original, int current, int sum, int* pProbabilities)
{
	if (current == 1)
	{
		pProbabilities[sum - original]++;
	}
	else
	{
		for (int i = 1; i <= g_maxValue; ++i)
		{
			Probability(original, current - 1, i + sum, pProbabilities);
		}
	}
}

void Probability(int number, int* pProbabilities)
{
	for (int i = 1; i <= g_maxValue; i++)
	{
		Probability(number, number, i, pProbabilities);
	}
}

void PrintProbability(int number)
{
	if (number < 1)
	{
		return;
	}

	int maxSum = number*g_maxValue;
	int* pProbabilities = new int[maxSum - number + 1];
	for (int i = number; i <= maxSum; i++)
	{
		pProbabilities[i - number] = 0;
	}

	Probability(number, pProbabilities);

	int total = pow((double)g_maxValue, number);
	for (int i = number; i <= maxSum; i++)
	{
		double ratio = (double)pProbabilities[i - number] / total;
		printf("%d:%e\n", i, ratio);
	}

	delete[] pProbabilities;
}

int main()
{

	system("pause");
	return 0;
}