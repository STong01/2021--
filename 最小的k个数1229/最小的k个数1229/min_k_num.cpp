#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

//输入n个整数，找出其中最小的k个数，例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4

//解法一：时间复杂度为O(n)的算法，只有当我们可以修改输入的数组时可用
int Partition(int data[], int length, int start, int end)
{
	if (data == nullptr || length <= 0 || start < 0 || end >= length)
	{
		throw new std::exception("Invalid Parameters");
	}

	int index = data[length / 2];

	int temp1 = data[index];
	data[index] = data[end];
	data[end] = temp1;

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
			{
				int temp2 = data[index];
				data[index] = data[small];
				data[small] = temp2;
			}
		}
	}
	++small;
	int temp3 = data[small];
	data[small] = data[end];
	data[end] = temp3;

	return small;
}

void GetLeastNumbers1(int* input, int n, int* output, int k)
{
	if (input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0)
	{
		return;
	}

	//n为数组的长度
	int start = 0;
	int end = n - 1;
	int index = Partition(input, n, start, end);


	while (index != k - 1)
	{
		if (index > k - 1)
		{
			end = index - 1;
			index = Partition(input, n, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(input, n, start, end);
		}
	}

	for (int i = 0; i < k; i++)
	{
		output[i] = input[i];
	}
}

//解法二：时间复杂度为O(nlog k)的算法，特别适合处理海量数据
//基于红黑树的算法
//确定一个大小为k的数据容器，接下来在输入的n个整数中读入数据。
//保存数据容器中最大的数据，每次读入的数据都与最大的数据进行比较，若数据大于最大的数据
//则不进行新数据的保存，若读入的数据小于最大的数据，则删除最大的数据，更新最大的数据，然后读入新的数据
typedef multiset<int, std::greater<int>> intSet;
typedef multiset<int, std::greater<int>>::iterator setIterator;

void GetLeastNumbers2(const vector<int>& data, intSet& leastNumbers, int k)
{
	leastNumbers.clear();
	if (k < 1 || data.size() < k)
	{
		return;
	}

	vector<int>::const_iterator iter = data.begin();
	for (; iter != data.end(); ++iter)
	{
		if ((leastNumbers.size()) < k)
		{
			leastNumbers.insert(*iter);
		}
		else
		{
			setIterator iterGreatest = leastNumbers.begin();

			if (*iter < *(leastNumbers.begin()))
			{
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	vector<int> ret;
	if (k == 0 || k > input.size())
	{
		return ret;
	}
	priority_queue<int, vector<int>> pq;
	for (const int val : input) 
	{
		if (pq.size() < k) 
		{
			pq.push(val);
		}
		else 
		{
			if (val < pq.top())
			{
				pq.pop();
				pq.push(val);
			}
		}
	}

	while (!pq.empty()) 
	{
		ret.push_back(pq.top());
		pq.pop();
	}

	return ret;
}

int main()
{

	system("pause");
	return 0;
}