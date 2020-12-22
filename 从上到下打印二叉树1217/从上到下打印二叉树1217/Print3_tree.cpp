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
			//当我们打印奇数行的时候，我们下一行打印的是偶数行
			//偶数行总是先打印右子树、后打印左子树，所以我们在打印奇数行的时候应该在下一个打印栈中先存入左子树，后存入右子树
			//此时我们在打印的时候才会实现先进后出的效果
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
			//当我们打印偶数行的时候，我们下一行打印的是奇数行
			//奇数行总是先打印左子树、后打印右子树，所以我们在打印偶数行的时候应该在下一个打印栈中先存入右子树，后存入左子树
			//此时我们在打印的时候才会实现先进后出的效果
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
			//更新打印栈和待打印栈
			//current总是为打印栈
			//next总是为待打印栈
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