#include <iostream>
#include <set>
#include <vector>
using namespace std;

//����һ���ַ�������ӡ�����ַ������ַ����������С�
//���磬�����ַ���abc�����ӡ�����ַ�a��b��c�������г����������ַ���abc��acb��bac��bca��cab��cba

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
		// forѭ����swap�ĺ��壺���ڡ�ABC����
		// ��һ��'A' �� 'A'�������ַ���Ϊ"ABC", posΪ0�� �൱�ڹ̶�'A'
		// �ڶ���'A' �� 'B'�������ַ���Ϊ"BAC", posΪ0�� �൱�ڹ̶�'B'
		// ������'A' �� 'C'�������ַ���Ϊ"CBA", posΪ0�� �൱�ڹ̶�'C'
		for (int i = pos; i < s.length(); ++i) 
		{
			swap(s[pos], s[i]);
			perm(pos + 1, s, ret);
			swap(s[pos], s[i]);
			// ���ݵ�ԭ�򣺱���ڶ��ν�������"BAC"����Ҫ���ݵ�"ABC"
			// Ȼ����е����ν��������ܵõ�"CBA"
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