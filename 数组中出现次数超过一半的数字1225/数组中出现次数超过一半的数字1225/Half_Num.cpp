#include <iostream>
using namespace std;

//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//���磺����һ������Ϊ9������{1��2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2

//�ⷨһ������Partition������ʱ�临�Ӷ�ΪO(n)���㷨
//�������
int Partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
	{
		throw new std::exception("Invalid Parameters");
	}

	int index = data[length / 2];

	int temp1 = data[index];
	data[index] = data[end];
	data[end] = temp1;

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
			{
				int temp2 = data[index];
				data[index] = data[small];
				data[small] = temp2;
			}
		}
	}
	++small;
	int temp3 = data[small];
	data[small] = data[end];
	data[end] = temp3;

	return small;
}

//�ж�����������Ƿ���Ч
//������������Ƿ����ĳһ�����ֳ��ֵĴ����������鳤��һ������
bool g_bInputInvalid = false;
bool CheckInvalidArray(int* numbers, int length)
{
	g_bInputInvalid = false;
	if (numbers == nullptr || length <= 0)
	{
		g_bInputInvalid = true;
	}

	return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] == number)
		{
			times++;
		}
	}

	bool isMoreThanHalf = true;
	if (times * 2 <= length)
	{
		g_bInputInvalid = true;
		isMoreThanHalf = false;
	}

	return isMoreThanHalf;
}

int MoreThanHalfNum1(int* numbers, int length)
{
	if (CheckInvalidArray(numbers, length))
	{
		return 0;
	}

	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(numbers, length, start, end);
	while (index != middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = Partition(numbers, length, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(numbers, length, start, end);
		}
	}

	int result = numbers[middle];
	if (!CheckMoreThanHalf(numbers, length, result))
	{
		result = 0;
	}
	return result;
}

//�ⷨ�������������ص��ҳ�ʱ�临�Ӷ�ΪO(n)���㷨
int MoreThanHalfNum2(int* numbers, int length)
{
	//�ж������Ƿ�������ĿҪ�󣨼������Ƿ���ڳ��ִ����������鳤��һ������֣�
	if (CheckInvalidArray(numbers, length))
	{
		return 0;
	}

	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < length; ++i)
	{
		
		if (times == 0)
		{
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result)
		{
			times++;
		}
		else
		{
			times--;
		}
	}

	if (!CheckMoreThanHalf(numbers, length, result))
	{
		result = 0;
	}

	return result;
}

int main()
{

	system("pause");
	return 0;
}