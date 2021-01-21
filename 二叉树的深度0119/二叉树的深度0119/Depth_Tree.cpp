#include <iostream>
using namespace std;

//输入一颗二叉树的根节点，求该树的深度
//从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//若一棵树只有一个节点，那么它的深度为1
//若根节点只有左子树没有右子树，那么树的深度应该是左子树的深度+1
//若根节点只有右子树没有左子树，那么树的深度应该是右子树的深度+1
//若根节点既有右子树又有左子树，树的深度应该是左右子数深度较大的值+1

int TreeDepth1(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return 0;
	}

	int nLeft = TreeDepth1(pRoot->m_pLeft);
	int nRight = TreeDepth1(pRoot->m_pRight);

	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

int main1()
{

	system("pause");
	return 0;
}