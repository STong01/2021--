#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	//NΪ���������������
	//FΪ���ǹ�������ʱFibonacci����
	int N, F;
	//LΪFibonacci��N��߾���
	//RΪFibonacci��N�ұ߾���
	int L = 0, R = 0;
	//F1��F2ΪFibonacci��������
	int F1 = 0, F2 = 1;
	cin >> N;

	while (1)
	{
		//Fibonacci���й���
		F = F1 + F2;
		F1 = F2;
		F2 = F;
		
		//N���������
		if (F < N)
		{
			L = N - F;
		}
		//N�����Ҿ���
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