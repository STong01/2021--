#include <iostream>
#include <string>
using namespace std;

string test(string str)
{
	string str1;
	int length = str.length();

	int num = 1;
	int j = 0;

	if (length == 0)
	{
		return;
	}

	for (int i = 0; i < length; i++)
	{
		if (str[i] == str[i + 1] && i != length - 1)
		{
			num++;
			continue;
		}
		else if (str[i] == str[i + 1] && i == length - 1)
		{
			if (num == 1)
			{
				str1 += str[i];
			}
			else
			{
				str1 += num + '0';
				str1 += str[i];
			}
		}
		else
		{
			if (num == 1)
			{
				str1 += str[i];
			}
			else
			{
				str1 += num + '0';
				str1 += str[i];
			}
		}
		num = 1;
	}
	return str1;
}

int main()
{
	string str;
	cin >> str;
	string str1 = test(str);

	int n = str1.length();
	cout << str1 << endl;

	system("pause");
	return 0;
}