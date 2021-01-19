#include <iostream>
using namespace std;

//���������������г��ֵĴ���
//ͳ��һ�����������������г��ֵĴ���
//������������{1,2,3,3,3,3,4,5}������3����������3�������г�����4�Σ��������4

//���ַ����ҵ�һ��k���ֵ�λ��
int GetFirstK(int* data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int middleIndex = (start + end) / 2;
	int minddleData = data[middleIndex];

	if (minddleData == k)
	{
		if (middleIndex > 0 && data[middleIndex - 1] != k || middleIndex == 0)
		{
			return middleIndex;
		}
		else
		{
			end = middleIndex - 1;
		}
	}
	else if (minddleData > k)
	{
		end = middleIndex - 1;
	}
	else
	{
		start = middleIndex + 1;
	}

	return GetFirstK(data, length, k, start, end);
}

//���ַ��������һ��k���ֵ�λ��
int GetLastK(int* data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int minddleIndex = (start + end) / 2;
	int minddleData = data[minddleIndex];

	if (minddleData = k)
	{
		if (minddleIndex < length - 1 && data[minddleIndex + 1] != k || minddleIndex == length - 1)
		{
			return minddleIndex;
		}
		else
		{
			start = minddleIndex + 1;
		}
	}
	else if (minddleData < k)
	{
		start = minddleIndex + 1;
	}
	else
	{
		end = minddleIndex - 1;
	}

	return GetLastK(data, length, k, start, end);
}

//����k�����ֵ��±� - ����k���ȳ��ֵ��±� + 1 = ����k�������г��ֵĴ���
int GetNumberOfK(int* data, int length, int k)
{
	int number = 0;

	if (data != nullptr && length > 0)
	{
		int first = GetFirstK(data, length, k, 0, length - 1);
		int last = GetLastK(data, length, k, 0, length - 1);

		if (first > -1 && last > -1)
		{
			number = last - first + 1;
		}
	}

	return number;
}

int main1()
{
	int data[] = { 1, 2, 3, 3, 3, 3, 4, 5 };
	int length = sizeof(data) / sizeof(int*);
	cout << length << endl;
	cout << GetNumberOfK(data, length, 3) << endl;

	system("pause");
	return 0;
}