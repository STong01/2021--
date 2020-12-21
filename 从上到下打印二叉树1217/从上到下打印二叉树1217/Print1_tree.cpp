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

	//首先直接在队列中放入树的根节点
	dequeTreeNode.push_back(pTreeRoot);

	while (dequeTreeNode.size())
	{
		//确保每次队列的首节点为我们要接下来打印的节点
		BinaryTreeNode* pNode = dequeTreeNode.front();
		//确保打印一个节点，队列中的首元素直接pop出来
		//这样才能使得每个首元素为我们要打印的节点
		dequeTreeNode.pop_front();
		cout << pNode->m_nValue;

		//当我们打印一个节点时候，它的子节点必定在下一层中打印的顺序也依旧如此
		//所以我们在打印一个节点的时候，直接将它的子节点放入队列即可
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