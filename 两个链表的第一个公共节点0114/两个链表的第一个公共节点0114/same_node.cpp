#include <iostream>
using namespace std;

//输入两个链表，找出他们的第一个公共节点
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

//方法一:将两个链表存放于两个辅助栈中，因为公共节点的后序节点都是相同的，所以我们开始从两个辅助栈中从上往下比较即可
//当两个栈的栈顶相同的时候，同时pop出两个栈顶即可，之后再次进行辅助栈的栈顶比较
//当两个栈的栈顶元素不相同的时候，我们上一个pop出的栈顶就是两个链表第一个公共的节点；时间复杂度为O(m+n)

//方法二：两个链表长度不同时候，我们将较长的链表先走m-n步，之后两个链表同时超后进行遍历，第一个相同的节点就是两个链表第一个公共的节点
//链表中之后的节点都是相同的(因为链表是单向链表，所以相同的元素后序节点必定是相同的)，不需要再进行剩余链表遍历
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
	//得到两个链表的长度
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

	//先在长链表上走几步，在同时在两个链表上遍历
	for (int i = 0; i < nLengthDif; i++)
	{
		pListHeadLong = pListHeadLong->m_pNext;
	}

	while ((pListHeadLong != nullptr) && (pListHeadSort!= nullptr) && (pListHeadLong != pListHeadSort));
	{
		pListHeadLong = pListHeadLong->m_pNext;
		pListHeadSort = pListHeadSort->m_pNext;
	}

	//得到第一个公共节点
	ListNode* pFirstCommonNode = pListHeadLong;
	return pFirstCommonNode;
}

int main()
{

	system("pause");
	return 0;
}