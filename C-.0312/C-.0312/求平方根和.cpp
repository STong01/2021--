#include <iostream>
#include "math.h"
using namespace std;

int main1()
{
	int n;
	cin >> n;
	double sum = 0;

	for (int i = 1; i <= n; i++)
	{
		sum = sum + sqrt(i);
	}

	double num = sum - ((int)(sum / 0.01))*0.01;
	if (num >= 0.005)
	{
		sum = sum - num + 0.01;
	}
	else
	{
		sum = sum - num;
	}

	cout << sum << endl;

	system("pause");
	return 0;
}