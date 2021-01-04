#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//如何得到一个数据流中的中位数？
//如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
//如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值

//将中位数的两侧分别存放入大根堆和小根堆
//大根堆里面的数据总是比小根堆里面的数据小
template<typename T>class  DynamicArray
{
public:
	void Insert(T num)
	{
		//判断数据流中是否为偶数个
		if (((min.size() + max.size()) & 1) == 0)
		{
			//若数据小于大根堆的堆顶，则需要将数据插入大根堆中
			if (max.size() > 0 && num < max[0])
			{
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<T>());

				//更新num值
				num = max[0];

				pop_heap(max.begin(), max.end(), less<T>());
				max.pop_back();
			}
			//若数据小于大根堆的堆顶，则需要将数据插入小根堆中
			min.push_back(num);
			push_heap(min.begin(), min.end(), great<T>());
		}
		//判断是数据流中为奇数个
		else
		{
			//若数据大于小根堆的堆顶，则需要将数据插入小根堆中
			if (min.size() > 0 && min[0] < num)
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<T>());

				num = min[0];

				pop_heap(min.begin(), min.end(), greater<T>());
				min.pop_back();
			}
			//若数据大于小根堆的堆顶，则需要将数据插入大根堆中
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>());
		}
	}

	T GetMedian()
	{
		int size = min.size() + max.size();
		if (size() == 0)
		{
			throw exception("No numbers are available");
		}

		T median = 0;

		//数据为奇数，则中位数为小根堆堆顶
		if ((size & 1) == 1)
		{
			median = min[0];
		}
		//数据为偶数，则中位数为大根堆和小根堆堆顶之和的一半
		else
		{
			median = (min[0] + max[0]) / 2;
		}

		return median;
	}
private:
	vector<T>max;
	vector<T>min;
};


int main()
{

	system("pause");
	return 0;
}