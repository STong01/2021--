#include <iostream>
#include <set>
#include <vector>
using namespace std;

//输入一个字符串，打印出该字符串中字符的所有排列。
//例如，输入字符串abc，则打印出由字符a，b，c所能排列出来的所有字符串abc、acb、bac、bca、cab、cba

void Permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin + 1);

			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}

void Permutation(char* pStr)
{
	if (pStr == nullptr)
	{
		return;
	}

	Permutation(pStr, pStr);
}

class Solution 
{
public:
	void perm(int pos, string s, set<string> &ret) 
	{
		if (pos + 1 == s.length()) 
		{
			ret.insert(s);
			return;
		}
		// for循环和swap的含义：对于“ABC”，
		// 第一次'A' 与 'A'交换，字符串为"ABC", pos为0， 相当于固定'A'
		// 第二次'A' 与 'B'交换，字符串为"BAC", pos为0， 相当于固定'B'
		// 第三次'A' 与 'C'交换，字符串为"CBA", pos为0， 相当于固定'C'
		for (int i = pos; i < s.length(); ++i) 
		{
			swap(s[pos], s[i]);
			perm(pos + 1, s, ret);
			swap(s[pos], s[i]);
			// 回溯的原因：比如第二次交换后是"BAC"，需要回溯到"ABC"
			// 然后进行第三次交换，才能得到"CBA"
		}
	}
	vector<string> Permutation(string s) 
	{
		if (s.empty())
		{
			return{};
		}
		set<string> ret;
		perm(0, s, ret);
		return vector<string>(ret.begin(), ret.end());
	}
};

int main()
{
	char pStr[] = "abcd";
	Permutation(pStr);

	system("pause");
	return 0;
}