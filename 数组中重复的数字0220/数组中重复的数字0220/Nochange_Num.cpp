#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//���޸������ҳ��ظ�������
//��һ������Ϊn+1����������������ֶ���1~n�ķ�Χ�ڣ�����������������һ���������ظ���
//���ҳ�����������һ���ظ������֣��������޸����������
int countRange(const int* numbers, int length, int start, int end)
{
	if (numbers == nullptr)
	{
		return 0;
	}

	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= start && numbers[i] <= end)
		{
			++count;
		}
	}
	return count;
}

int getDuplication(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		return -1;
	}

	int start = 1;
	int end = length - 1;

	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;
		int count = countRange(numbers, length, start, middle);
		if (start == end)
		{
			if (count > 1)
			{
				return start;
			}
			else
			{
				break;
			}
		}

		if (count > (middle - start + 1))
		{
			end = middle;
		}
		else
		{
			start = middle + 1;
		}
	}
	return -1;
}

int main()
{
	int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int length = sizeof(numbers) / sizeof(int);
	cout << getDuplication(numbers, length) << endl;

	system("pause");
	return 0;
}