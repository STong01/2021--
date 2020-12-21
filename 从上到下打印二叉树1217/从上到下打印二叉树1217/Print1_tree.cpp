#include <iostream>
#include <deque>
using namespace std;

//�����д��ϵ��´�ӡ������
//���ϵ��´�ӡ����������ÿ���ڵ㣬ͬһ��Ľڵ㰴�մ����ҵ�˳���ӡ
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
	if (!pTreeRoot)
	{
		return;
	}

	std::deque<BinaryTreeNode*> dequeTreeNode;

	//����ֱ���ڶ����з������ĸ��ڵ�
	dequeTreeNode.push_back(pTreeRoot);

	while (dequeTreeNode.size())
	{
		//ȷ��ÿ�ζ��е��׽ڵ�Ϊ����Ҫ��������ӡ�Ľڵ�
		BinaryTreeNode* pNode = dequeTreeNode.front();
		//ȷ����ӡһ���ڵ㣬�����е���Ԫ��ֱ��pop����
		//��������ʹ��ÿ����Ԫ��Ϊ����Ҫ��ӡ�Ľڵ�
		dequeTreeNode.pop_front();
		cout << pNode->m_nValue;

		//�����Ǵ�ӡһ���ڵ�ʱ�������ӽڵ�ض�����һ���д�ӡ��˳��Ҳ�������
		//���������ڴ�ӡһ���ڵ��ʱ��ֱ�ӽ������ӽڵ������м���
		if (pNode->m_pLeft)
		{
			dequeTreeNode.push_back(pNode->m_pLeft);
		}

		if (pNode->m_pRight)
		{
			dequeTreeNode.push_back(pNode->m_pRight);
		}
	}
}

int main1()
{
	system("pause");
	return 0;
}