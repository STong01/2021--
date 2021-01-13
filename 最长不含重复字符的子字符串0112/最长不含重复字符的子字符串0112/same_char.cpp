#include <iostream>
#include <string>
using namespace std;

//请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
//假设字符串中只包含‘a’~‘z’的字符
//例如，在字符串“arabcacfr”中，最长的不含重复字符的子字符串是“acfr”，长度为4

int longestSubstringWithoutDuplication(const std::string& str)
{
	int curLength = 0;
	int maxLength = 0;

	int* position = new int[26];
	for (int i = 0; i < 26; i++)
	{
		position[i] = -1;
	}

	for (int i = 0; i < str.length(); i++)
	{
		int prevIndex = position[str[i] - 'a'];
		if (prevIndex<0 || i - prevIndex>curLength)
		{
			++curLength;
		}
		else
		{
			if (curLength > maxLength)
			{
				maxLength = curLength;
			}
			curLength = i - prevIndex;
		}
		position[str[i] - 'a'] = i;
	}
	if (curLength > maxLength)
	{
		maxLength = curLength;
	}

	delete[] position;
	return maxLength;
}

int main()
{

	system("pause");
	return 0;
}