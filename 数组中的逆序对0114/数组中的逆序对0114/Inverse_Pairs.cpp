#include <iostream>
using namespace std;

//�������е��������֣����ǰ���һ�����ִ��ں�������֣����������������һ�������
//����һ�����飬�����������е�����Ե�����
//������{7,5,6,4}�У�һ������5������ԣ��ֱ���{7,6},{7,5},{7,4},{6,4},{5,4}��

//���ù鲢˼�뽫�����������Ե�ͳ��
//���Ƚ�����һ��Ϊ����Ϊ{7,5,}��{6,4}
//��ν��ֺõ����ֽ����ٴη��飬��Ϊ7,5��6,4��
//���ֺõ�������������������Ϊ{5,7}��{4,6}��
//�ٴν��й鲢�Ƚ�����
//������й鲢�����ʱ������ǰ��ε��������ֺͺ����������ֽ��бȽ�����
//��ǰ����������ִ��ں��ε��������֣���ǰ������ֺͺ��������ʣ���ÿһ�������Թ��������
//����������ִ���ǰ��ε����֣��򽫺��ε����ֽ��и����������򣬽�ָ����ǰ��һλ����������ǰ���������������ֵıȽ�����

//�鲢��ʱ�临�Ӷ���O(nlogn)
int InversePairsCore(int *data, int* copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) / 2;

	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length + 1, end);

	//i��ʼ��Ϊǰ������һ�����ֵ��±�
	int i = start + length;
	//j��ʼ��Ϊ�������һ�����ֵ��±�
	int j = end;
	int indexCopy = end;
	int count = 0;
	while (i >= start && j >= start + length + 1)
	{
		if (data[i] > data[j])
		{
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		}
		else
		{
			copy[indexCopy--] = data[j--];
		}
	}

	for (; i >= start; --i)
	{
		copy[indexCopy--] = data[i];
	}
	for (; j >= start + length + 1; j--)
	{
		copy[indexCopy--] = data[j];
	}
	return left + right + count;
}

int InversPairs(int* data, int length)
{
	if (data == nullptr || length < 0)
	{
		return 0;
	}

	int* copy = new int[length];
	for (int i = 0; i < length; i++)
	{
		copy[i] = data[i];
	}

	int count = InversePairsCore(data, copy, 0, length - 1);
	delete[] copy;

	return count;
}

int main()
{
	int data[] = { 7, 6, 5, 4 };
	cout << InversPairs(data, 4) << endl;
	system("pause");
	return 0;
}