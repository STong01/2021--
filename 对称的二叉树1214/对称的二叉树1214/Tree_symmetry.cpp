#include <iostream>
using namespace std;

//ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵģ����һ�ö����������ľ���һ������ô���ǶԳƵġ�
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//�ж϶������Ƿ�Ϊ�Գƶ�����
//��root1��������root2���������жԳƱȽ�
//root1����������ʼ���еݹ飬root2����������ʼ�ݹ�
//�Ӷ����жԳƱȽ�
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