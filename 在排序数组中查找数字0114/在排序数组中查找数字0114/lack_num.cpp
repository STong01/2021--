#include <iostream>
using namespace std;

//һ������Ϊn-1�ĵ������������е��������ֶ���Ψһ�ģ�����ÿ�����ֶ��ڷ�Χ0~n-1֮�ڡ�
//�ڷ�Χ0~n-1�ڵ�n������������ֻ��һ�����ֲ��ڸ������У����ҳ��������

//����һ����0~n-1������֮��S1 - ���������е�����֮��S2 = ȱʧ������
int GetMissingNumber1(const int* numbers, int length)
{
	if (numbers == nullptr || length < 0)
	{
		return -1;
	}

	int S1 = 0;
	S1 = length * (length + 1) / 2;

	int S2 = 0;
	for (int i = 0; i < length; ++i)
	{
		S2 += numbers[i];
	}

	return S1 - S2;
}

//������������Ϊ�������飬���е�����Ӧ�ú����ǵ��±�����ͬ�ģ��������±겻��ͬ�����ֵ�ʱ�򣬾���ȱʧ������
int GetMissingNumber2(const int* numbers, int length)
{
	if (numbers == nullptr || length < 0)
	{
		return -1;
	}

	int left = 0;
	int right = length - 1;

	while (left <= right)
	{
		int middle = (left + right) >> 1;
		if (numbers[middle] != middle)
		{
			if (middle == 0 || numbers[middle - 1] == middle - 1)
			{
				return middle;
			}
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}

	if (left == length)
	{
		return length;
	}

	//��Ч�����룬�������鲻�ǰ�Ҫ�������
	//�����ֲ���0~n-1��Χ֮��
	return -1;
}

int main2()
{
	const int numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15 };
	int length = sizeof(numbers) / sizeof(int*);
	cout << length << endl;
	cout << GetMissingNumber1(numbers, length) << endl;
	cout << GetMissingNumber2(numbers, length) << endl;
	system("pause");
	return 0;
}