#include <iostream>
using namespace std;

//数组中只出现一次的两个数字
//一个整型数组里除两个数字之外，其他数字都出现了两次。
//请程序找出这两个只出现一次的数字，要求时间复杂度为O(n)，空间复杂度为O(1)

//在整数num的二进制表示中找到最右边是1的位
unsigned int FindFirstBitls1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}

	return indexBit;
}

//判断在num的二进制表示中从右边数起的indexBit位是不是1
bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

void FindNumsApperOnce(int data[], int length, int* num1, int* num2)
{
	if (data == nullptr || length < 2)
	{
		return;
	}

	int resultExclusiveOR = 0;
	for (int i = 0; i < length; ++i)
	{
		resultExclusiveOR ^= data[i];
	}

	unsigned int indexOf1 = FindFirstBitls1(resultExclusiveOR);

	*num1 = *num2 = 0;

	for (int j = 0; j < length; ++j)
	{
		if (IsBit1(data[j], indexOf1))
		{
			*num1 ^= data[j];
		}
		else
		{
			*num2 ^= data[j];
		}
	}
}

int main()
{
	int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int length = sizeof(data) / sizeof(int);
	int num1 = 0;
	int num2 = 0;

	FindNumsApperOnce(data, length, &num1, &num2);

	cout << num1 << " " << num2 << endl;

	system("pause");
	return 0;
}