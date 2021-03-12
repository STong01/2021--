#include <iostream>
using namespace std;

double fact_4(int n)
{
	double num = 1;
	for (int i = 1; i <= n; i++)
	{
		num = num * i;
	}
	return num;
}

int main()
{
	int n;
	cin >> n;

	double sum = 1;
	for (int i = 1; i <= n; i++)
	{
		sum += 1 / fact_4(i);
	}

	double num = sum - ((int)(sum / 0.0001))*0.0001;
	if (num >= 0.00005)
	{
		sum = sum - num + 0.0001;
	}
	else
	{
		sum = sum - num;
	}

	cout << sum << endl;

	system("pause");
	return 0;
}