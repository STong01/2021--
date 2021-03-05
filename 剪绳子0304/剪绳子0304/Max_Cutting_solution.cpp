#include <iostream>
#include <algorithm>
using namespace std;

//给你一根长度为n的绳子，请把绳子剪成m段（m、n都是整数，并且m > 1、n > 1），每段绳子的长度记为k[0]、k[1]、k[2]
//请问所有绳子段的可能的最大乘积为多少
int maxProductAfterCutting_solution1(int length)
{
	if (length < 2)
	{
		return 0;
	}
	if (length == 2)
	{
		return 1;
	}
	if (length == 3)
	{
		return 2;
	}

	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	for (int i = 4; i <= length; i++)
	{
		max = 0;
		for (int j = 1; j <= i / 2; j++)
		{
			int product = products[j] * products[i - j];
			if (max < product)
			{
				max = product;
			}

			products[i] = max;
		}
	}

	max = products[length];
	delete[] products;

	return max;
}

int maxProductAfterCutting_solution2(int length)
{
	if (length < 2)
	{
		return 0;
	}
	if (length == 2)
	{
		return 1;
	}
	if (length == 3)
	{
		return 2;
	}

	//尽可能多的减去长度为3的绳子段
	int timesOf3 = length / 3;

	//当绳子最后剩下的长度为4的时候，不能在减去长度为3的绳子
	//此时更好的方法是把绳子剪成长度为2的两段
	if (length - timesOf3 * 3 == 1)
	{
		timesOf3 -= 1;
	}

	int timeOf2 = (length - timesOf3 * 3) / 2;

	return (int)(pow(3, timesOf3))*(int)(pow(2, timeOf2));
}

int main()
{
	int length = 8;
	cout << maxProductAfterCutting_solution2(length) << endl;
	system("pause");
	return 0;
}