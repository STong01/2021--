#include <iostream>
using namespace std;

//翻转单词顺序
//输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变，标点符号和普通字母一样处理
//输入字符串“I am a student.”输出“student. a am I”

//翻转整个句子
void Reverse(char*pBegin, char* pEnd)
{
	if (pBegin == nullptr || pEnd == nullptr)
	{
		return;
	}

	while (pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++;
		pEnd--;
	}
}

char* ReverseSentence(char* pData)
{
	if (pData == nullptr)
	{
		return nullptr;
	}

	char* pBegin = pData;

	char* pEnd = pData;
	while (*pEnd != '\0')
	{
		pEnd++;
	}

	pEnd--;

	//翻转整个句子
	Reverse(pBegin, pEnd);

	//翻转句子中的每个单词
	pBegin = pEnd = pData;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pBegin == ' ')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			*pEnd++;
		}
	}
	return pData;
}

int main1()
{
	char pData[] = "I am a student.";

	system("pause");
	return 0;
}