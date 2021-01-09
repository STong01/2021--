#include <iostream>
using namespace std;

//������01234567891011121314...�ĸ�ʽ���л���һ���ַ������С��������У�����λ����0��ʼ��������5����13λ��1����19Ϊ��4��
//дһ���������������nλ��Ӧ������

//�õ�mλ�������ܹ��ж��ٸ���
//���磺����2���򷵻���λ����10-99���ĸ���90
//����3���򷵻���λ����100-999���ĸ���900
int countOfIntegers(int digits)
{
	if (digits == 1)
	{
		return 10;
	}
	int count = (int)std::pow(10, digits - 1);
	return 9 * count;
}

//���һ��mλ��
//���磺��һ����λ����10����һ����λ����100
int beginNumber(int digits)
{
	if (digits == 1)
	{
		return 0;
	}
	return (int)std::pow(10, digits - 1);
}

//������֪��Ҫ����һλ����λ��ĳmλ��֮�к󣬿��������溯���ҳ���һλ����
int digitAtIndex(int index, int digits)
{
	int number = beginNumber(digits) + index / digits;
	int indexFromRight = digits - index%digits;
	for (int i = 1; i < indexFromRight; i++)
	{
		number /= 10;
	}
	return number % 10;
}

int digitAtIndex(int index)
{
	if (index < 0)
	{
		return -1;
	}

	int digits = 1;
	while (true)
	{
		int numbers = countOfIntegers(digits);
		if (index < numbers*digits)
		{
			return digitAtIndex(index, digits);
		}

		index -= digits * numbers;
		digits++;
	}
	return -1;
}

int main()
{
	int index;
	cin >> index;
	cout << digitAtIndex(index) << endl;

	system("pause");
	return 0;
}