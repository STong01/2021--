#include <iostream>
using namespace std;

//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת
//����һ����������������һ����ת�������ת�������СԪ��

int Min1(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		throw new std::exception("Invalid parameters");
	}

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;

	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;

			break;
		}

		indexMid = (index1 + index2) / 2;
		if (numbers[indexMid] >= numbers[index1])
		{
			index1 = indexMid;
		}
		else if (numbers[indexMid] <= numbers[index2])
		{
			index2 = indexMid;
		}
	}

	return numbers[indexMid];
}

int MinInOrder(int* numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; i++)
	{
		if (result > numbers[i])
		{
			result = numbers[i];
		}
	}
	return result;
}

int Min2(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		throw new std::exception("Invalid parameters");
	}

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;

		//����±�Ϊindex1��index2��indexMidָ��������������
		//��ֻ��˳�����
		if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
		{
			return MinInOrder(numbers, index1, index2);
		}

		if (numbers[indexMid] >= numbers[index1])
		{
			index1 = indexMid;
		}
		else if (numbers[indexMid] <= numbers[index2])
		{
			index2 = indexMid;
		}
	}
	return numbers[indexMid];
}

int main()
{
	int numbers[] = { 3, 4, 5, 1, 2 };
	int length = sizeof(numbers) / sizeof(int);

	cout << Min2(numbers, length) << endl;

	system("pause");
	return 0;
}