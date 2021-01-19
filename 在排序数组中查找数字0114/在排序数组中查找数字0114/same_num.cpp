#include <iostream>
using namespace std;

//����һ�������������������ÿ��Ԫ�ض����������Ҷ���Ψһ�ġ�
//��̺������ҳ�����������һ����ֵ�������±��Ԫ��
//���磺������{-3,-1,1,3,5}�У�����3�������±����

int GetNumberSameAsIndex(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		return -1;
	}

	int left = 0;
	int right = length - 1;

	while (left <= right)
	{
		//int middle = left + ((right - left) >> 1);
		//int middle = (right + left) >> 1;
		int middle = right - ((right - left) >> 1);
		if (numbers[middle] == middle)
		{
			return middle;
		}

		if (numbers[middle] > middle)
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	return -1;
}

int main()
{
	const int numbers[] = { -3, 1, 3, 4, 5 };
	int length = sizeof(numbers) / sizeof(int*);
	cout << length << endl;
	cout << GetNumberSameAsIndex(numbers, length) << endl;
	system("pause");
	return 0;
}