#include <iostream>
using namespace std;

//����һ�Ŷ������ĸ��ڵ㣬����������
//�Ӹ��ڵ㵽Ҷ�ڵ����ξ����Ľڵ㣨������Ҷ�ڵ㣩�γ�����һ��·�����·���ĳ���Ϊ�������

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//��һ����ֻ��һ���ڵ㣬��ô�������Ϊ1
//�����ڵ�ֻ��������û������������ô�������Ӧ���������������+1
//�����ڵ�ֻ��������û������������ô�������Ӧ���������������+1
//�����ڵ�����������������������������Ӧ��������������Ƚϴ��ֵ+1

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