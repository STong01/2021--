#include <iostream>
using namespace std;

long long fact(int n)
{
	long long num = 1;
	for (int i = 1; i <= n; i++)
	{
		num = num * i;
	}
	return num;
}

int main2()
{
	int n;
	cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += fact(i);
	}

	cout << sum << endl;

	system("pause");
	return 0;
}