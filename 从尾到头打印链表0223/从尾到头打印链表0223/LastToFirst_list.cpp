#include <iostream>
#include <stack>
using namespace std;

//����һ�������ͷ�ڵ㣬��β��ͷ��������ӡ��ÿ���ڵ��ֵ
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

//ջʵ��
void PrintListReversingly_Iteratively(ListNode* pHead)
{
	std::stack<ListNode*>nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_nKey);
		nodes.pop();
	}
}

//�ݹ�ʵ��
void PrintfListReversingly_Recursively(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->m_pNext != nullptr)
		{
			PrintfListReversingly_Recursively(pHead->m_pNext);
		}
		printf("%d\t", pHead->m_nKey);
	}
}

int main()
{

	system("pause");
	return 0;
}