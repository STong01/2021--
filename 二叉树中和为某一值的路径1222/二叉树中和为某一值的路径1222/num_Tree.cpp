#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int currentSum)
{
	//每次在路径中存放一个节点的时候，在路径的数据之和上加上节点的数值
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	//如果是叶节点，并且路径上节点值的和等于输入的值
	//则打印出这条路径
	bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
	if (currentSum == expectedSum && isLeaf)
	{
		printf("A path is found:");
		std::vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); ++iter)
		{
			printf("%d/t", *iter);
		}

		printf("/n");
	}

	//如果不是叶节点，则遍历它的子节点
	if (pRoot->m_pLeft != nullptr)
	{
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	}
	if (pRoot->m_pRight != nullptr)
	{
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
	}

	//在返回父节点之前，在路径上删除当前节点
	path.pop_back();
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
	if (pRoot == nullptr)
	{
		return;
	}

	//定义存放路径的数组path
	std::vector<int>path;
	//定义路径中的数据之和currentSum
	int currentSum = 0;
	FindPath(pRoot, expectedSum, path, currentSum);
}

class Solution 
{
public:
	using vvi = vector<vector<int>>;
	using vi = vector<int>;
	void dfs(BinaryTreeNode *root, int sum, vi &path, vvi &ret) 
	{
		path.push_back(root->m_nValue);
		if (sum == root->m_nValue && !root->m_pLeft && !root->m_pRight)
		{
			ret.push_back(path);
		}
		if (root->m_pLeft)
		{
			dfs(root->m_pLeft, sum - root->m_nValue, path, ret);
		}
		if (root->m_pRight)
		{
			dfs(root->m_pRight, sum - root->m_nValue, path, ret);
		}

		path.pop_back(); 
		// 代码走到这里，表明要回溯，代表当前path中的root节点我已经不需要了
	}
	vector<vector<int> > FindPath(BinaryTreeNode* root, int expectNumber) 
	{
		vvi ret;
		vi path;
		if (!root)
		{
			return ret;
		}

		dfs(root, expectNumber, path, ret);
		return ret;
	}
};


int main()
{

	system("pause");
	return 0;
}