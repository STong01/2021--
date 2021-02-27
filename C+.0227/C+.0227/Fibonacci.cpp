#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	//N为我们所输入的数据
	//F为我们构建的临时Fibonacci数据
	int N, F;
	//L为Fibonacci中N左边距离
	//R为Fibonacci中N右边距离
	int L = 0, R = 0;
	//F1，F2为Fibonacci数列数据
	int F1 = 0, F2 = 1;
	cin >> N;

	while (1)
	{
		//Fibonacci数列构建
		F = F1 + F2;
		F1 = F2;
		F2 = F;
		
		//N数据左距离
		if (F < N)
		{
			L = N - F;
		}
		//N数据右距离
		else
		{
			R = F - N;
			break;
		}
	}

	cout << min(L, R) << endl;
	system("pause");
	return 0;
}