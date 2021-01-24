#include <iostream>
using namespace std;

//��ΪS����������
//����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S
//����ж�����ֵĺ͵���S�����������һ�Լ���

//�������������飬���Կ��Զ�������ָ�����ǰ����ӶԱ�
//����ָ��֮�ʹ���S���ǿ��Խ�����ϴ��ָ����ǰ��һλ�ٽ�����ͶԱ�
//����ָ��֮��С��S���ǿ��Խ�ǰ���С��ָ��������һλ�ٽ�����ͱȽ�

bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2)
{
	bool found = false;
	if (length < 1 || num1 == nullptr || num2 == nullptr)
	{
		return found;
	}

	//�����С���ֵ��±�
	int ahead = 0;
	//����ϴ����ֵ��±�
	int behind = length - 1;

	while (ahead < behind)
	{
		long long curSum = data[ahead] + data[behind];

		if (curSum == sum)
		{
			*num1 = data[ahead];
			*num2 = data[behind];

			found = true;
			break;
		}
		else if (curSum > sum)
		{
			behind--;
		}
		else
		{
			ahead++;
		}
	}
	return found;
}

int main1()
{

	int data[] = { 1, 2, 4, 7, 11, 15 };
	int length = sizeof(data) / sizeof(int);
	int sum = 15;
	int num1 = 0;
	int num2 = 0;

	if (FindNumbersWithSum(data, length, sum, &num1, &num2))
	{
		cout << num1 << "  " << num2 << endl;
	}

	system("pause");
	return 0;
}