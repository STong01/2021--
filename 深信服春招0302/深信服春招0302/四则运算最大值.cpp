#include <iostream>
#include <vector>
using namespace std;

vector<int> sort(vector<int> num)
{
	for (int i = 0; i < num.size() - 1; i++)
	{
		for (int j = 0; j < num.size() - i - 1; j++)
		{
			if (num[j] < num[j + 1])
			{
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
	return num;
}

int main()
{
	int n;
	cin >> n;

	vector<int> num(n, 0);
	vector<char> puf(n - 1, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	int num_chen = 0;
	int num_jia = 0;
	int num_jian = 0;
	int num_chu = 0;

	for (int j = 0; j < n - 1; j++)
	{
		cin >> puf[j];
		if (puf[j] == '*')
		{
			num_chen++;
		}
		if (puf[j] == '/')
		{
			num_chu++;
		}
		if (puf[j] == '+')
		{
			num_jia++;
		}
		if (puf[j] == '-')
		{
			num_jian++;
		}
	}

	num = sort(num);

	int num_0_left = 0;
	for (int i = 0; i < n; i++)
	{
		if (num[i] == 0)
		{
			num_0_left = i;
			break;
		}
	}
	int num_last = n - 1;
	int num_first = 1;
	int num_0_right = num_0_left;

	int sum = num[0];
	while (n)
	{
		if (num[num_first] <= (num[num_last] * num[num_last - 1]) && num_chen != 0)
		{
			sum = sum * num[num_last] * num[num_last - 1];
			num_last -= 2;
			n -= 2;
			num_chen -= 2;
			continue;
		}
		else if (num[num_first] > (num[num_last] * num[num_last - 1]) && num_chen != 0)
		{
			sum = sum*num[num_first];
			num_first++;
			n--;
			num_chen -= 2;
			continue;
		}

		if (num_jia != 0)
		{
			sum += num[num_first];
			num_first++;
			num_jia--;
			n--;
			continue;
		}

		if (num_jian != 0)
		{
			if (num_0_right < num_first && num_0_left < num_last && -num[num_0_left] > num[num_0_right])
			{
				sum -= num[num_0_left];
				num_jian--;
				num_0_left++;
				n--;
				continue;
			}
			else if (num_0_right < num_first && num_0_left < num_last && -num[num_0_left] < num[num_0_right])
			{
				sum -= num[num_0_right];
				num_jian--;
				num_0_right--;
				n--;
				continue;
			}
		}

		if (num[num_first] <= (num[num_last] * num[num_last - 1]) && num_chu != 0)
		{
			sum = sum / num[num_first];
			num_first ++;
			n --;
			num_chu--;
			continue;
		}
		else if (num[num_first] > (num[num_last] * num[num_last - 1]) && num_chu != 0)
		{
			sum = sum/(num[num_last] * num[num_last - 1]);
			num_last -= 2;
			n -= 2;
			num_chu--;
			continue;
		}

	}
	cout << sum << endl;

	system("pause");
	return 0;
}