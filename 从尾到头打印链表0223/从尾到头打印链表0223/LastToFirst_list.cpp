#include <iostream>
#include <stack>
using namespace std;

//输入一个链表的头节点，从尾到头反过来打印出每个节点的值
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

//栈实现
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

//递归实现
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