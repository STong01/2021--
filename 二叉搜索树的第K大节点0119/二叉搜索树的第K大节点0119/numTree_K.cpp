#include <iostream>
using namespace std;

//给定一颗二叉树，请找出其中第K大的节点
//将二叉树中序遍历之后，所得到的数组即为二叉树的递增顺序，然后直接找其中的第K大的数字即可

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, unsigned int& k)
{
	BinaryTreeNode* target = nullptr;
	if (pRoot->m_pLeft != nullptr)
	{
		target = KthNodeCore(pRoot->m_pLeft, k);
	}

	if (target == nullptr)
	{
		if (k == 1)
		{
			target = pRoot;
		}
		k--;
	}

	if (target == nullptr && pRoot->m_pRight != nullptr)
	{
		target = KthNodeCore(pRoot->m_pRight, k);
	}

	return target;
}

BinaryTreeNode* KthNode(BinaryTreeNode* pRoot, unsigned int k)
{
	if (pRoot == nullptr || k == 0)
	{
		return nullptr;
	}
	return KthNodeCore(pRoot, k);
}

int main()
{

	system("pause");
	return 0;
}