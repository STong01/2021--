#include <iostream>
using namespace std;

//请实现一个函数，把字符串中的每个空格替换成“%20”。
//例如：输入：“We are happy.”则输出“We%20are%20happy.”

//length为字符数组string的总容量
void ReplaceBlank(char string[], int length)
{
	if (string == nullptr || length <= 0)
	{
		return;
	}

	//originalLength为字符串string的实际长度
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		++originalLength;
		if (string[i] == ' ')
		{
			++numberOfBlank;
		}

		++i;
	}

	//newLength为把空格替换成%20之后的长度
	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > length)
	{
		return;
	}

	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
		{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}

int main()
{

	char string[] = "We are happy.";
	int length = 20;

	ReplaceBlank(string, length);

	cout << string << endl;

	system("pause");
	return 0;
}