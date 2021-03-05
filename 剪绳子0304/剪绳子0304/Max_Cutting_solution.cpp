#include <iostream>
#include <algorithm>
using namespace std;

//����һ������Ϊn�����ӣ�������Ӽ���m�Σ�m��n��������������m > 1��n > 1����ÿ�����ӵĳ��ȼ�Ϊk[0]��k[1]��k[2]
//�����������ӶεĿ��ܵ����˻�Ϊ����
int maxProductAfterCutting_solution1(int length)
{
	if (length < 2)
	{
		return 0;
	}
	if (length == 2)
	{
		return 1;
	}
	if (length == 3)
	{
		return 2;
	}

	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	for (int i = 4; i <= length; i++)
	{
		max = 0;
		for (int j = 1; j <= i / 2; j++)
		{
			int product = products[j] * products[i - j];
			if (max < product)
			{
				max = product;
			}

			products[i] = max;
		}
	}

	max = products[length];
	delete[] products;

	return max;
}

int maxProductAfterCutting_solution2(int length)
{
	if (length < 2)
	{
		return 0;
	}
	if (length == 2)
	{
		return 1;
	}
	if (length == 3)
	{
		return 2;
	}

	//�����ܶ�ļ�ȥ����Ϊ3�����Ӷ�
	int timesOf3 = length / 3;

	//���������ʣ�µĳ���Ϊ4��ʱ�򣬲����ڼ�ȥ����Ϊ3������
	//��ʱ���õķ����ǰ����Ӽ��ɳ���Ϊ2������
	if (length - timesOf3 * 3 == 1)
	{
		timesOf3 -= 1;
	}

	int timeOf2 = (length - timesOf3 * 3) / 2;

	return (int)(pow(3, timesOf3))*(int)(pow(2, timeOf2));
}

int main()
{
	int length = 8;
	cout << maxProductAfterCutting_solution2(length) << endl;
	system("pause");
	return 0;
}