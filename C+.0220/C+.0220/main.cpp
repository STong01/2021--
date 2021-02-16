#include <iostream>
#include <vector>
using namespace std;

//连续最大和
int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (size_t i = 0; i < nums.size(); i++)
	{
		cin >> nums[i];
	}

	int max = nums[0];
	int sum1 = 0;
	int sum2 = 0;
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (sum1 >= 0)
		{
			sum2 = sum1 + nums[i];
		}
		else
		{
			sum2 = nums[i];
		}

		if (sum2 > max)
		{
			max = sum2;
		}

		if (sum2 < 0)
		{
			sum2 = 0;
		}

		sum1 = sum2;

	}

	cout << max << endl;

	system("pause");
	return 0;
}