#include <iostream>
using namespace std;

//实现一个函数，用来判断一颗二叉树是不是对称的，如果一棵二叉树和它的镜像一样，那么他是对称的。
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//判断二叉树是否为对称二叉树
//将root1二叉树和root2二叉树进行对称比较
//root1从左子树开始进行递归，root2从右子树开始递归
//从而进行对称比较
bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot1 == nullptr && pRoot2 == nullptr)
	{
		return true;
	}

	if (pRoot1 == nullptr || pRoot2 == nullptr)
	{
		return false;
	}

	if (pRoot1->m_nValue != pRoot2->m_nValue)
	{
		return false;
	}

	return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}

bool isSymmetrical(BinaryTreeNode* pRoot)
{
	return isSymmetrical(pRoot, pRoot);
}

int main()
{

	system("pause");
	return 0;
}