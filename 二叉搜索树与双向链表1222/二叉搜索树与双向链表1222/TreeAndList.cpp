#include <iostream>
#include <list>
using namespace std;

//����һ�ö��������������ö���������ת����һ�������˫������
//Ҫ���ܴ����κ��µĽڵ㣬ֻ�ܵ������нڵ�ָ���ָ��

//�������ڵ�Ķ���
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

	//pLastNodeInListָ��˫�������β�ڵ�
	//������Ҫ����ͷ�ڵ�
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