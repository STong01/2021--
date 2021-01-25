#include <iostream>
#include <string>
using namespace std;

//左旋转字符串
//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部
//定义函数实现字符串左旋转操作的功能
//输入字符串“abcdefg”和数字2，输出左旋两位得到的结果“cdefgab”

void Reverse2(char*pBegin, char* pEnd)
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

char* LeftRotataString(char* pStr, int n)
{
	if (pStr != nullptr)
	{
		int nLength = static_cast<int>(strlen(pStr));
		if (nLength > 0 && n > 0 && n < nLength)
		{
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondStart = pStr + n;
			char* pSecondEnd = pStr + nLength - 1;

			//翻转字符串的前面n个字符
			Reverse2(pFirstStart, pFirstEnd);
			//翻转字符串的后面部分
			Reverse2(pSecondStart, pSecondEnd);
			//翻转整个字符串
			Reverse2(pFirstStart, pSecondEnd);
		}
	}
	return pStr;
}

int main()
{

	system("pause");
	return 0;
}