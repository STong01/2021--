#include <iostream>
using namespace std;

//��ΪS��������������
//����һ������S����ӡ���к�ΪS��������������(���ٺ���������)
//���磺����15������1+2+3+4+5 = 4+5+6 = 7+8 = 15�����Դ�ӡ��3����������1~5��4~6��7~8

void PrintContinuousSequence(int small, int big)
{
	for (int i = small; i <= big; ++i)
	{
		cout << i << " ";
	}
	cout << endl;
}

void FindContinuousSequence(int sum)
{
	if (sum < 3)
	{
		return;
	}

	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + big;

	while (small < middle)
	{
		if (curSum == sum)
		{
			PrintContinuousSequence(small, big);
		}

		while (curSum > sum && small < middle)
		{
			curSum -= small;
			small++;

			if (curSum == sum)
			{
				PrintContinuousSequence(small, big);
			}
		}

		big++;
		curSum += big;
	}
}

int main()
{
	int sum;
	while (cin >> sum)
	{
		FindContinuousSequence(sum);
	}

	system("pause");
	return 0;
}