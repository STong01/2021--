#include <iostream>
using namespace std;

//�ַ����е�һ��ֻ����һ�ε��ַ�
//���ַ������ҵ���һ��ֻ����һ�ε��ַ��������롰abaccdeff���������b

//��hash�������м��㣬�������ַ���Ϊhash�ļ�ֵ�����ַ����ֵĴ�����Ϊhash��value
//���ַ���ɨ�����Σ���һ�ν���ͳ�ƣ�ͳ��ÿ���ַ����ַ����г����˼���
//�ڶ���ɨ���ַ�����ʱ�򣬿��ַ���Ӧ��valueֵ�Ƿ�Ϊ1����Ϊ1��ʱ��ֱ������ַ�����ʱ����ַ����ǵ�һ��û���ظ����ַ�
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