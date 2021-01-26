#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//�������ڵ����ֵ
//����һ������ͻ������ڵĴ�С�����ҳ����л�������������ֵ
//��������{2,3,4,2,6,2,5,1}�Լ��������ڵĴ�С3����ôһ������6���������ڣ����ǵ����ֵ�ֱ���{4,4,6,6,6,5}��

vector<int>maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> maxInWindows;
	if (num.size() >= size && size >= 1)
	{
		deque<int> index;

		for (unsigned int i = 0; i < size; i++)
		{
			while (!index.empty() && num[i] >= num[index.back()])
			{
				index.pop_back();
			}

			index.push_back(i);
		}

		for (unsigned int i = size; i < num.size(); i++)
		{
			maxInWindows.push_back(num[index.front()]);
			
			while (!index.empty() && num[i] >= num[index.back()])
			{
				index.pop_back();
			}

			if (!index.empty() && index.front() <= (int)(i - size))
			{
				index.pop_front();
			}

			index.push_back(i);
		}
		maxInWindows.push_back(num[index.front()]);
	}
	return maxInWindows;
}

int main()
{

	vector<int> num = { 2, 3, 4, 2, 6, 2, 5, 1 };
	vector<int> maxInWindow(8, 0);
	maxInWindow = maxInWindows(num, 3);

	system("pause");
	return 0;
}