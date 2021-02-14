#include <iostream>
using namespace std;

//写一个函数，求两个整数之和，要求在函数体内不得使用“+”“-”“*”“/”四则运算符号
//三步走：（1）不记进位位数求和、（2）记下进位、（3）前两步结果相加
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