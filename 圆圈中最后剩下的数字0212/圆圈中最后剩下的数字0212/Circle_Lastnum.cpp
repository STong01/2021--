#include <iostream>
#include <list>
using namespace std;

//0,1,...,n - 1��n�������ų�һ��ԲȦ��������0��ʼ��ÿ�δ����ԲȦ��ɾ����m�����֡�
//�����ԲȦ��ʣ�µ����һ������

//�û�������ģ��ԲȦ
int LastRemaining1(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}

	unsigned int i = 0;

	list<int> numbers;
	for (int i = 0; i < n; i++)
	{
		numbers.push_back(i);
	}

	list<int>::iterator current = numbers.begin();

	while (numbers.size() > 1)
	{
		for (int i = 1; i < m; i++)
		{
			current++;
			if (current == numbers.end())
			{
				current = numbers.begin();
			}
		}

		list<int>::iterator next = ++current;
		if (next == numbers.end())
		{
			next = numbers.begin();
		}

		--current;
		numbers.erase(current);
		current = next;
	}

	return *(current);
}

//f(n, m) = 0 [n = 1];
//f(n, m) = [f(n - 1, m) + m] % n [n > 1];
int LastRemaining2(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}

	int last = 0;
	for (int i = 2; i <= n; i++)
	{
		last = (last + m) % i;
	}

	return last;
}

int main()
{
	unsigned int n = 5;
	unsigned int m = 3;

	cout << LastRemaining2(n, m) << endl;

	system("pause");
	return 0;
}