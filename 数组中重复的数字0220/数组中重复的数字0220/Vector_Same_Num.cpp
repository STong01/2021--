#include <iostream>
#include <vector>
using namespace std;

int GetSize(int data[])
{
	return sizeof(data);
}

//�ҳ��������ظ�������
//��һ������Ϊn����������������ֶ���0-n-1�ķ�Χ�ڣ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˶��ٴ�
//���ҳ�����������һ���ظ�������
bool duplicate(int numbers[], int length)
{
	if (numbers == nullptr || length <= 0)
	{
		return false;
	}

	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
		{
			return false;
		}
	}

	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				//*duplication = numbers[i];
				return true;
			}

			//swap numbers[i] and numbers[numbers[i]]
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}

int main1()
{
	int data1[] = { 1, 2, 3, 4, 5 };
	int size1 = sizeof(data1);

	int* data2 = data1;
	int size2 = sizeof(data2);

	int size3 = GetSize(data1);

	printf("%d,%d,%d\n", size1, size2, size3);

	int numbers[] = { 2, 3, 1, 0, 2, 5 };
	int length = sizeof(numbers) / sizeof(int);
	cout << length << endl;
	int* duplication = { 0 };
	cout << duplicate(numbers, length)<< endl;

	system("pause");
	return 0;
}