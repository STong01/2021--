#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回true，否则返回false。
bool VerifySquenceOfBST(int sequence[], int length)
{
	if (sequence == nullptr || length <= 0)
	{
		return false;
	}

	//数组的最后一个节点，为后序遍历结构的根节点，根节点比左子树的所有数据都大，比右子树所有数据都小
	int root = sequence[length - 1];

	//在二叉搜索树中左子树节点的值小于根节点的值
	int i = 0;
	for (; i < length - 1; i++)
	{
		if (sequence[i] > root)
		{
			break;
		}
	}

	//在二叉搜索树中右子树节点的值大于根节点的值
	int j = i;
	for (; j < length - 1; j++)
	{
		if (sequence[j] < root)
		{
			return false;
		}
	}

	//判断左子树是不是二叉搜索树
	bool left = true;
	if (i > 0)
	{
		//左子树递归判断是否为二叉搜索树
		left = VerifySquenceOfBST(sequence, i);
	}

	//判断右子树是不是二叉搜索树
	bool right = true;
	if (i < length - 1)
	{
		//右子树递归判断是否为二叉搜索树
		right = VerifySquenceOfBST(sequence + i, length - i - 1);
	}

	return (left && right);
}

bool VerifySquenceOfBST(vector<int> sequence)
{
	if (sequence.size() == 0)
	{
		return false;
	}

	int sum = sequence.size() - 1;
	int count = 0;

	//从遍历结果的最后一个节点向前面的节点一一遍历，遍历的所有子树都为二叉搜索树
	//二叉搜索树的所有子树依旧是二叉搜索树
	while (sum)
	{
		while (sequence[count] < sequence[sum])
		{
			++count;
		}
		while (sequence[count] > sequence[sum])
		{
			++count;
		}
		if (count < sum)
		{
			return false;
		}
		//缩小二叉搜索树的节点数，再次进行判断
		--sum;
		count = 0;
	}
	return true;
}

int main()
{

	system("pause");
	return 0;
}