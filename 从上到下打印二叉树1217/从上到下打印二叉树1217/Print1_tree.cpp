#include <iostream>
#include <deque>
using namespace std;

//不分行从上到下打印二叉树
//从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印
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

	dequeTreeNode.push_back(pTreeRoot);

	while (dequeTreeNode.size())
	{
		BinaryTreeNode* pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		cout << pNode->m_nValue;

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