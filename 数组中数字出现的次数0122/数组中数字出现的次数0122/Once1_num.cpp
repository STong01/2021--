#include <iostream>
using namespace std;

//������Ψһֻ����һ�ε�����
//��һ�������г�һ������ֻ����һ��֮�⣬�������ֶ����������Σ����ҳ��Ǹ�ֻ����һ��������

//�������е��������ֵĶ�����λ��Ӧ���
//�����������ֳ��ֵĴ����������Σ�����λ����ӿ϶��ܱ�������
//���õ�������ÿһλ���������������õ�������(����1����0)���ɵ�������ֻ����һ�ε�����

int FindNumberAppearingOnce(int numbers[], int length)
{
	if (numbers == nullptr || length <= 0)
	{
		throw new std::exception("Invalid input.");
	}

	int bitSum[32] = { 0 };

	for (int i = 0; i < length; ++i)
	{
		int bitMask = 1;
		for (int j = 31; j >= 0; --j)
		{
			int bit = numbers[i] & bitMask;
			if (bit != 0)
			{
				bitSum[j] += 1;
			}
			bitMask = bitMask << 1;
		}
	}

	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		result = result << 1;
		result += bitSum[i] % 3;
	}

	return result;
}

int main()
{
	int numbers[] = { 3, 3, 3, 2, 2, 2, 5, 5, 5, 1, 6, 6, 6, 4, 4, 4 };
	int length = sizeof(numbers) / sizeof(int);

	cout << FindNumberAppearingOnce(numbers, length) << endl;

	system("pause");
	return 0;
}