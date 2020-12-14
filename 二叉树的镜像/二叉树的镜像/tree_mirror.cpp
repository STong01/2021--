#include <iostream>
using namespace std;

//���һ������������һ�ö��������ú���������ľ���
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//����������
//����ȷ�����������ڵ��λ��
//֮�󽻻�����������������������λ��
//�ٽ������������������ֱ���뺯�����е���
//�ݹ��������������������������
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