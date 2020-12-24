#include <iostream>
#include <list>
using namespace std;

//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
//要求不能创建任何新的节点，只能调整树中节点指针的指向。

//二叉树节点的定义
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void CovertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
	if (pNode == nullptr)
	{
		return;
	}

	BinaryTreeNode* pCurrent = pNode;


	if (pCurrent->m_pLeft != nullptr)
	{
		CovertNode(pCurrent->m_pLeft, pLastNodeInList);
	}

	pCurrent->m_pLeft = *pLastNodeInList;
	if (*pLastNodeInList != nullptr)
	{
		(*pLastNodeInList)->m_pRight = pCurrent;
	}

	*pLastNodeInList = pCurrent;

	if (pCurrent->m_pRight != nullptr)
	{
		CovertNode(pCurrent->m_pRight, pLastNodeInList);
	}
}

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
	BinaryTreeNode* pLastNodeInList = nullptr;
	CovertNode(pRootOfTree, &pLastNodeInList);

	//pLastNodeInList指向双向链表的尾节点
	//我们需要返回头节点
	BinaryTreeNode* pHeadOfList = pLastNodeInList;
	while (pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
	{
		pHeadOfList = pHeadOfList->m_pLeft;
	}

	return pHeadOfList;
}

int main()
{

	system("pause");
	return 0;
}