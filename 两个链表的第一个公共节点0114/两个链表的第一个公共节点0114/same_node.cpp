#include <iostream>
using namespace std;

//�������������ҳ����ǵĵ�һ�������ڵ�
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

//����һ:����������������������ջ�У���Ϊ�����ڵ�ĺ���ڵ㶼����ͬ�ģ��������ǿ�ʼ����������ջ�д������±Ƚϼ���
//������ջ��ջ����ͬ��ʱ��ͬʱpop������ջ�����ɣ�֮���ٴν��и���ջ��ջ���Ƚ�
//������ջ��ջ��Ԫ�ز���ͬ��ʱ��������һ��pop����ջ���������������һ�������Ľڵ㣻ʱ�临�Ӷ�ΪO(m+n)

//�����������������Ȳ�ͬʱ�����ǽ��ϳ�����������m-n����֮����������ͬʱ������б�������һ����ͬ�Ľڵ�������������һ�������Ľڵ�
//������֮��Ľڵ㶼����ͬ��(��Ϊ�����ǵ�������������ͬ��Ԫ�غ���ڵ�ض�����ͬ��)������Ҫ�ٽ���ʣ���������
unsigned int GetListLength(ListNode* pHead)
{
	unsigned int nLength = 0;
	ListNode* pNode = pHead;

	while (pNode != nullptr)
	{
		++nLength;
		pNode = pNode->m_pNext;
	}

	return nLength;
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	//�õ���������ĳ���
	unsigned int nLength1 = GetListLength(pHead1);
	unsigned int nLength2 = GetListLength(pHead2);
	int nLengthDif = nLength1 - nLength2;

	ListNode* pListHeadLong = pHead1;
	ListNode* pListHeadSort = pHead2;
	if (nLength2 > nLength1)
	{
		pListHeadLong = pHead2;
		pListHeadSort = pHead1;
		nLengthDif = nLength2 - nLength1;
	}

	//���ڳ��������߼�������ͬʱ�����������ϱ���
	for (int i = 0; i < nLengthDif; i++)
	{
		pListHeadLong = pListHeadLong->m_pNext;
	}

	while ((pListHeadLong != nullptr) && (pListHeadSort!= nullptr) && (pListHeadLong != pListHeadSort));
	{
		pListHeadLong = pListHeadLong->m_pNext;
		pListHeadSort = pListHeadSort->m_pNext;
	}

	//�õ���һ�������ڵ�
	ListNode* pFirstCommonNode = pListHeadLong;
	return pFirstCommonNode;
}

int main()
{

	system("pause");
	return 0;
}