#include <iostream>
using namespace std;

//在数组中的两个数字，如果前面的一个数字大于后面的数字，则这两个数字组成一个逆序对
//输入一个数组，求出这个数组中的逆序对的总数
//在数组{7,5,6,4}中，一共存在5个逆序对，分别是{7,6},{7,5},{7,4},{6,4},{5,4}。

//利用归并思想将数组进行逆序对的统计
//首先将数组一分为二即为{7,5,}，{6,4}
//其次将分好的数字进行再次分组，即为7,5；6,4；
//将分好的数组进行两两组合排序即为{5,7}；{4,6}；
//再次进行归并比较排序
//数组进行归并排序的时候总是前半段的最后的数字和后半段最后的数字进行比较排序，
//若前面的最后的数字大于后半段的最后的数字，则前面的数字和后面的数字剩余的每一个都可以构成逆序对
//若后面的数字大于前半段的数字，则将后半段的数字进行辅助数组排序，将指针向前移一位，继续进行前半段与后半段最后的数字的比较排序

//归并的时间复杂度是O(nlogn)
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

	//i初始化为前半段最后一个数字的下标
	int i = start + length;
	//j初始化为后半段最后一个数字的下标
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