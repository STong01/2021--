#include <iostream>
using namespace std;

//дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ�á�+����-����*����/�������������
//�����ߣ���1�����ǽ�λλ����͡���2�����½�λ����3��ǰ����������
int Add(int num1, int num2)
{
	int sum, carry;
	do
	{
		sum = num1^num2;
		carry = (num1 & num2) << 1;
		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return num1;
}

int main()
{
	int num1 = 5;
	int num2 = 17;

	cout << Add(num1, num2) << endl;

	system("pause");
	return 0;
}