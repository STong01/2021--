#include <iostream>
#include <stack>
using namespace std;

//之字形打印二叉树
//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，
//第三行再按照从左到右的顺序打印，其他行依次类推
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void Print3(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}

	std::stack<BinaryTreeNode*>levels[2];
	int current = 0;
	int next = 1;

	levels[current].push(pRoot);
	while (!levels[0].empty() || !levels[current].empty())
	{
		BinaryTreeNode* pNode = levels[current].top();
		levels[current].pop();

		cout << pNode->m_nValue;

		if (current == 0)
		{
			if (pNode->m_pLeft != nullptr)
			{
				levels[next].push(pNode->m_pLeft);
			}

			if (pNode->m_pRight != nullptr)
			{
				levels[next].push(pNode->m_pRight);
			}
		}
		else
		{
			if (pNode->m_pRight != nullptr)
			{
				levels[next].push(pNode->m_pRight);
			}

			if (pNode->m_pLeft != nullptr)
			{
				levels[next].push(pNode->m_pLeft);
			}
		}

		if (levels[current].empty())
		{
			cout << endl;
			current = 1 - current;
			next = 1 - next;
		}
	}
}

int main()
{

	system("pause");
	return 0;
}