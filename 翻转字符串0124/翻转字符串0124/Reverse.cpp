#include <iostream>
using namespace std;

//��ת����˳��
//����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䣬�����ź���ͨ��ĸһ������
//�����ַ�����I am a student.�������student. a am I��

//��ת��������
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

	//��ת��������
	Reverse(pBegin, pEnd);

	//��ת�����е�ÿ������
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