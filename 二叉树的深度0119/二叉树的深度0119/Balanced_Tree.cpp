#include <iostream>
using namespace std;

//����һ�Ŷ������ĸ��ڵ㣬�жϸö������ǲ���ƽ�������
//��ĳ������������ڵ���������������������1����ô������һ��ƽ�������

struct  BinaryTreeNode
{
	int m_Value;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//������������
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

//�жϸö������ǲ���ƽ�������
bool IsBalanced1(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return true;
	}

	//�ֱ�����������������
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