#include <iostream>
#include <queue>
using namespace std;

//���д������´�ӡ������
//���ϵ��°����ӡ��������ͬһ��Ľڵ㰴�����ҵ�˳���ӡ��ÿһ���ӡ��һ��
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void Print2(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}

	std::queue<BinaryTreeNode*> nodes;
	nodes.push(pRoot);

	//����toBePronted��ʾ�ڵ�ǰ���л�û�д�ӡ�Ľڵ�����������nextLevel��ʾ��һ��Ľڵ���
	//���һ���ڵ����ӽڵ㣬��ÿ��һ���ӽڵ������У�ͬʱ�ѱ���nextLevel��1
	//ÿ��ӡһ���ڵ㣬toBePrinted��1����ToBePrint���0ʱ����ʾ��ǰ������нڵ��Ѿ���ӡ��ϣ��ɼ�����ӡ��һ��
	int nextLevel = 0;
	int toBePrinted = 1;
	while (!nodes.empty())
	{
		BinaryTreeNode* pNode = nodes.front();
		cout << pNode->m_nValue;

		if (pNode->m_pLeft != nullptr)
		{
			nodes.push(pNode->m_pLeft);
			++nextLevel;
		}

		if (pNode->m_pRight != nullptr)
		{
			nodes.push(pNode->m_pRight);
			++nextLevel;
		}

		nodes.pop();
		--toBePrinted;

		if (toBePrinted == 0)
		{
			cout << endl;
			toBePrinted = nextLevel;
			nextLevel = 0;
		}
	}
}

int main2()
{

	system("pause");
	return 0;
}