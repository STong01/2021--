#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��εõ�һ���������е���λ����
//������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
//������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ

//����λ��������ֱ��������Ѻ�С����
//�����������������Ǳ�С�������������С
template<typename T>class  DynamicArray
{
public:
	void Insert(T num)
	{
		//�ж����������Ƿ�Ϊż����
		if (((min.size() + max.size()) & 1) == 0)
		{
			//������С�ڴ���ѵĶѶ�������Ҫ�����ݲ���������
			if (max.size() > 0 && num < max[0])
			{
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<T>());

				//����numֵ
				num = max[0];

				pop_heap(max.begin(), max.end(), less<T>());
				max.pop_back();
			}
			//������С�ڴ���ѵĶѶ�������Ҫ�����ݲ���С������
			min.push_back(num);
			push_heap(min.begin(), min.end(), great<T>());
		}
		//�ж�����������Ϊ������
		else
		{
			//�����ݴ���С���ѵĶѶ�������Ҫ�����ݲ���С������
			if (min.size() > 0 && min[0] < num)
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<T>());

				num = min[0];

				pop_heap(min.begin(), min.end(), greater<T>());
				min.pop_back();
			}
			//�����ݴ���С���ѵĶѶ�������Ҫ�����ݲ���������
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

		//����Ϊ����������λ��ΪС���ѶѶ�
		if ((size & 1) == 1)
		{
			median = min[0];
		}
		//����Ϊż��������λ��Ϊ����Ѻ�С���ѶѶ�֮�͵�һ��
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