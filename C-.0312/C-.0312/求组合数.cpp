#include <iostream>
using namespace std;

double fact(int n)
{
	double num = 1;
	for (int i = 1; i <= n; i++)
	{
		num = num * i;
	}
	return num;
}

int main4()
{
	int m;
	cin >> m;

	int n;
	cin >> n;

	int t = n - m;

	double sum;
	sum = fact(n) / (fact(m) * fact(t));

	cout << sum << endl;

	system("pause");
	return 0;
}