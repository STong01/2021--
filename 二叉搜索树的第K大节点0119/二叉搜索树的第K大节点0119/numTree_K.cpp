#include <iostream>
using namespace std;

//����һ�Ŷ����������ҳ����е�K��Ľڵ�
//���������������֮�����õ������鼴Ϊ�������ĵ���˳��Ȼ��ֱ�������еĵ�K������ּ���

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