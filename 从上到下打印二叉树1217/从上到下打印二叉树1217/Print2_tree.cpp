#include <iostream>
#include <queue>
using namespace std;

//分行从上往下打印二叉树
//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行
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

	//变量toBePronted表示在当前层中还没有打印的节点数，而变量nextLevel表示下一层的节点数
	//如果一个节点有子节点，则每把一个子节点加入队列，同时把变量nextLevel加1
	//每打印一个节点，toBePrinted减1，当ToBePrint变成0时，表示当前层的所有节点已经打印完毕，可继续打印下一层
	int nextLevel = 0;
	int toBePrinted = 1;
	while (!nodes.empty())
	{
		BinaryTreeNode* pNode = nodes.front();
		cout << pNode->m_nValue;

		//当我们打印一个节点的时候，我们将它的子节点存入队列中，nextLevel增加未打印节点数
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
			//toBePrinted表示某一行中需要打印的节点数
			//当toBePrinted为0的时候，表示这一行的节点数已经打印完毕，开始新一行的打印即可
			toBePrinted = nextLevel;
			//nextLevel总是表示我们下一行中需要打印的节点数，当我们需要打印下一行的时候，更新toBePrinted，nextLevel重置为0
			nextLevel = 0;
		}
	}
}

int main2()
{

	system("pause");
	return 0;
}