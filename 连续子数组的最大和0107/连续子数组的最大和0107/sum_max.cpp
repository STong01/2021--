#include <iostream>
#include <vector>
using namespace std;

bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int* pData, int nLength)
{
	if ((pData == nullptr) || (nLength <= 0))
	{
		g_InvalidInput = true;
		return 0;
	}

	g_InvalidInput = false;

	int nCurSum = 0;
	int nGreatestSum = 0x80000000;
	for (int i = 0; i < nLength; ++i)
	{
		if (nCurSum <= 0)
		{
			nCurSum = pData[i];
		}
		else
		{
			nCurSum += pData[i];
		}

		if (nCurSum > nGreatestSum)
		{
			nGreatestSum = nCurSum;
		}
	}
	return nGreatestSum;
}

int main()
{
	int n;
	cin >> n;
	vector<int> tmp(n, 0);
	for (int i = 0; i<n; i++)
	{
		cin >> tmp[i];
	}

	if (n <= 0)
	{
		cout << 0;
	}

	int sum = 0x80000000;
	int num = 0;

	for (int i = 0; i<n; i++)
	{
		if (num <= 0)
		{
			num = tmp[i];
		}
		else
		{
			num += tmp[i];
		}

		if (sum<num)
		{
			sum = num;
		}
	}
	cout << sum;
	system("pause");
	return 0;
}