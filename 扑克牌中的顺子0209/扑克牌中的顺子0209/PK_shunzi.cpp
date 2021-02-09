#include <iostream>
#include <algorithm>
using namespace std;

//���˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ���������
//2~10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С�����Կ����������֡�

int compare(const void* arg1, const void* arg2)
{
	return *(int*) arg1 - *(int*) arg2;
}

bool IsContinuous(int* numbers, int length)
{
	if (numbers == nullptr || length < 1)
	{
		return false;
	}

	qsort(numbers, length, sizeof(int), compare);

	int numberOfZero = 0;
	int numberOfGap = 0;

	//ͳ��������0�ĸ���
	for (int i = 0; i < length && numbers[i] == 0; i++)
	{
		++numberOfZero;
	}

	//ͳ�������еļ����Ŀ
	int small = numberOfZero;
	int big = small + 1;
	while (big < length)
	{
		//������ȣ��ж��ӣ���������˳��
		if (numbers[small] == numbers[big])
		{
			return false;
		}

		numberOfGap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}

	return (numberOfGap > numberOfZero) ? false : true;
}

int main()
{
	int numbers[] = { 0, 2, 6, 4, 5 };
	cout << IsContinuous(numbers, 5) << endl;

	system("pause");
	return 0;
}