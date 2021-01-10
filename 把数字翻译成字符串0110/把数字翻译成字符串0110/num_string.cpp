#include <iostream>
#include <string>
using namespace std;

//给定一个数字，我们按照如下规则把它翻译为字符串
//0翻译成a，1翻译成b，。。。。11翻译成l
//一个数字可能有多个翻译，
//12258可以翻译成:"bccfi"，"bwfi"，"bczi"，"mcfi"，"mzi"
//编程实现一个数字的翻译方法

int GetTranslationCount(const string& number)
{
	int length = number.length();
	int* counts = new int[length];
	int count = 0;

	for (int i = length - 1; i >= 0; i--)
	{
		count = 0;
		if (i < length - 1)
		{
			count = counts[i + 1];
		}
		else
		{
			count = 1;
		}

		if (i < length - 1)
		{
			int digit1 = number[i] - '0';
			int digit2 = number[i + 1] - '0';
			int converted = digit1 * 10 + digit2;
			if (converted >= 10 && converted <= 25)
			{
				if (i < length - 2)
				{
					count += counts[i + 2];
				}
				else
				{
					count += 1;
				}
			}
		}

		counts[i] = count;
	}

	count = counts[0];
	delete[] counts;

	return count;
}

int GetTranslationCount(int number)
{
	if (number < 0)
	{
		return 0;
	}

	//将数字转换为字符串进行计算
	string numberInString = to_string(number);
	return GetTranslationCount(numberInString);

}

int main()
{

	int n;
	cin >> n;
	cout << GetTranslationCount(n) << endl;

	system("pause");
	return 0;
}