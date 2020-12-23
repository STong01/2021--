#include <iostream>
#include <list>
using namespace std;

//请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复制一个复杂链表。
//在复杂链表中，每个节点除了有一个m_pNext指针指向下一个节点，还有一个m_pSibling指针指向链表中的任意节点或者nullptr
struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

//复制原始链表的任意节点N并创建新节点N'，再把N'链接到N的后面
void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		//定义一个全新的节点来进行每一次复制节点的过程
		ComplexListNode* pCloned = new ComplexListNode();
		//复制节点的值与原节点的值相等
		pCloned->m_nValue = pNode->m_nValue;
		//复制节点的m_pNext指向下一个我们即将要复制的节点
		pCloned->m_pNext = pNode->m_pNext;
		//第一步首先把m_pSibling置空，之后在进行定向指向操作
		pCloned->m_pSibling = nullptr;

		//更新要复制的节点，即为我们复制节点的下一个节点
		pNode->m_pNext = pCloned;
		pNode = pCloned->m_pNext;
	}
}

//如果原始链表上的节点N的m_pSibling指向S，则它对应的复制节点N'的m_pSibling指向S的复制节点S'
void ConnectSiblingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		//用pCloned来保存我们的复制节点
		ComplexListNode*pCloned = pNode->m_pNext;
		if (pNode->m_pSibling != nullptr)
		{
			//复制节点的m_pSibling指向为我们原节点的m_pSibling的指向的复制节点
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		//重置我们需要找m_pSibling的节点
		pNode = pCloned->m_pNext;
	}
}

//把第二步得到的链表拆分成两个链表，奇数位置上的节点组成原始的链表，偶数位置上的节点组成复制出来的链表
ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	//定义节点用来保存复制链表的头节点
	ComplexListNode* pClonedHead = nullptr;
	//定义复制节点来进行复制链表的节点变化
	ComplexListNode* pClonedNode = nullptr;

	if (pNode != nullptr)
	{
		//更新复制链表的头节点以及接下来节点的变化
		pClonedHead = pClonedNode = pNode->m_pNext;
		//pNode用来保存原始链表的节点变换(原始链表的原始节点总在上一个节点的复制节点的next下)
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}

	while (pNode != nullptr)
	{
		//定义复制节点的next指向
		pClonedNode->m_pNext = pNode->m_pNext;
		//重置复制节点
		pClonedNode = pClonedNode->m_pNext;
		//定义原始节点的next指向(总是上一个复制节点的下一个next指向)
		pNode->m_pNext = pClonedNode->m_pNext;
		//重置原始节点
		pNode = pNode->m_pNext;
	}
	//返回复制链表的头节点即可
	return pClonedHead;
}

//三步合起来即为复制链表的完整过程
ComplexListNode* Clone(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}

int main()
{

	system("pause");
	return 0;
}