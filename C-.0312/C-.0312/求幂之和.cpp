#include <iostream>
#include <algorithm>
using namespace std;

int main3()
{
	int n;
	cin >> n;

	double sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += pow(2, i);
	}

	cout << sum << endl;

	system("pause");
	return 0;
}