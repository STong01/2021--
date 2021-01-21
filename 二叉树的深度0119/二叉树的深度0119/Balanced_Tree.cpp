#include <iostream>
using namespace std;

//输入一颗二叉树的根节点，判断该二叉树是不是平衡二叉树
//若某二叉树中任意节点的左右子数的深度相差不超过1，那么它就是一棵平衡二叉树

struct  BinaryTreeNode
{
	int m_Value;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//求二叉树的深度
int TreeDepth2(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return 0;
	}

	int nLeft = TreeDepth2(pRoot->m_pLeft);
	int nRight = TreeDepth2(pRoot->m_pRight);

	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

//判断该二叉树是不是平衡二叉树
bool IsBalanced1(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return true;
	}

	//分别求解左右子数的深度
	int left = TreeDepth2(pRoot->m_pLeft);
	int right = TreeDepth2(pRoot->m_pRight);

	int diff = left - right;

	if (diff > 1 || diff < -1)
	{
		return false;
	}

	return IsBalanced1(pRoot->m_pLeft) && IsBalanced1(pRoot->m_pRight);
}

bool IsBalanced2(BinaryTreeNode* pRoot, int* pDepth)
{
	if (pRoot == nullptr)
	{
		*pDepth = 0;
		return true;
	}

	int left, right;
	if (IsBalanced2(pRoot->m_pLeft, &left) && IsBalanced2(pRoot->m_pRight, &right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}

	return false;
}

bool IsBalanced2(BinaryTreeNode* pRoot)
{
	int depth = 0;
	return IsBalanced2(pRoot, &depth);
}

int main()
{

	system("pause");
	return 0;
}