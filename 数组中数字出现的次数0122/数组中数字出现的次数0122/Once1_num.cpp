#include <iostream>
using namespace std;

//数组中唯一只出现一次的数字
//在一个数组中除一个数组只出现一次之外，其他数字都出现了三次，请找出那个只出现一个的数字

//将数组中的所有数字的二进制位对应相加
//由于其他数字出现的次数都是三次，所有位数相加肯定能被三整除
//最后得到的数字每一位都与三整除，最后得到的余数(不是1就是0)构成的数就是只出现一次的数字

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