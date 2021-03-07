#include <iostream>
using namespace std;

//请实现一个函数，输入一个整数，输出该数二进制表示中1的个数
int NumberOf1_1(int n)
{
	int count = 0;
	while (n)
	{
		if(n & 1)
		{
			count++;
		}
		n = n >> 1;
	}
	return count;
}

int NumberOf1_2(int n)
{
	int count = 1;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
		{
			count++;
		}

		flag = flag >> 1;
	}

	return count;
}

int NumberOf1_3(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1)&n;
	}

	return count;
}

int main()
{
	cout << NumberOf1_1(9) << endl;
	cout << NumberOf1_2(9) << endl;
	cout << NumberOf1_3(9) << endl;

	system("pause");
	return 0;
}