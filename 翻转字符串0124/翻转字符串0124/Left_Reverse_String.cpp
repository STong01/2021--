#include <iostream>
#include <string>
using namespace std;

//����ת�ַ���
//�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β��
//���庯��ʵ���ַ�������ת�����Ĺ���
//�����ַ�����abcdefg��������2�����������λ�õ��Ľ����cdefgab��

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

			//��ת�ַ�����ǰ��n���ַ�
			Reverse2(pFirstStart, pFirstEnd);
			//��ת�ַ����ĺ��沿��
			Reverse2(pSecondStart, pSecondEnd);
			//��ת�����ַ���
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