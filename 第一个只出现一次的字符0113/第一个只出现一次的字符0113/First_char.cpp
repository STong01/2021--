#include <iostream>
using namespace std;

//字符串中第一个只出现一次的字符
//在字符串中找到第一个只出现一次的字符，若输入“abaccdeff”，则输出b

//用hash方法进行计算，其中用字符作为hash的键值，用字符出现的次数作为hash的value
//将字符串扫描两次，第一次进行统计，统计每个字符在字符串中出现了几次
//第二次扫描字符串的时候，看字符对应的value值是否为1，当为1的时候，直接输出字符，此时这个字符就是第一次没有重复的字符
char FirstNotRepeatingChar(char* pString)
{
	if (pString == nullptr)
	{
		return '\0';
	}

	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (unsigned int i = 0; i < tableSize; i++)
	{
		hashTable[i] = 0;
	}

	char* pHashKey = pString;
	while (*(pHashKey) != '\0')
	{
		hashTable[*(pHashKey++)]++;
	}

	pHashKey = pString;
	while (*pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1)
		{
			return *pHashKey;
		}
		pHashKey++;
	}

	return '\0';
}

int main1()
{
	char* string = "abaccbff";

	cout << FirstNotRepeatingChar(string) << endl;
	system("pause");
	return 0;
}