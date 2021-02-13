#include <iostream>
using namespace std;

//�����ĳ��Ʊ�ļ۸���ʱ���Ⱥ�˳��洢�������У����������ù�Ʊһ�ο��ܻ�õ���������Ƕ��٣�
//һֻ��Ʊ��ĳЩʱ��ڵ�ļ۸�Ϊ{9,11,8,5,7,12,16,14}������������ڼ۸�Ϊ5��ʱ��������ڼ۸�Ϊ16ʱ���������ܻ����������11

int MaxDiff(const int* numbers, unsigned length)
{
	if (numbers == nullptr && length < 2)
	{
		return 0;
	}

	int min = numbers[0];
	int maxDiff = numbers[1] - min;

	for (int i = 2; i < length; i++)
	{
		if (numbers[i - 1] < min)
		{
			min = numbers[i - 1];
		}

		int currendDiff = numbers[i] - min;
		if (currendDiff > maxDiff)
		{
			maxDiff = currendDiff;
		}
	}
	return maxDiff;
}

int main()
{
	int numbers[] = { 9, 11, 8, 5, 7, 12, 16, 14 };

	cout << MaxDiff(numbers, 8) << endl;

	system("pause");
	return 0;
}