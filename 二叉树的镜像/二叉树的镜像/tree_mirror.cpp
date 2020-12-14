#include <iostream>
using namespace std;

//完成一个函数，输入一棵二叉树，该函数输出它的镜像。
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//二叉树镜像
//首先确定二叉树根节点的位置
//之后交换二叉树左子树与右子树的位置
//再将二叉树的左右子树分别进入函数进行调换
//递归进行左右子树的左右子数调换
void MirrorRecursively(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
	{
		return;
	}
	if (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr)
	{
		return;
	}

	BinaryTreeNode* pTemp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pLeft = pTemp;

	if (pNode->m_pLeft)
	{
		MirrorRecursively(pNode);
	}
	if (pNode->m_pRight)
	{
		MirrorRecursively(pNode);
	}
}

int main()
{

	system("pause");
	return 0;
}