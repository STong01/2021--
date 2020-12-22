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
	//ÿ����·���д��һ���ڵ��ʱ����·��������֮���ϼ��Ͻڵ����ֵ
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	//�����Ҷ�ڵ㣬����·���Ͻڵ�ֵ�ĺ͵��������ֵ
	//���ӡ������·��
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

	//�������Ҷ�ڵ㣬����������ӽڵ�
	if (pRoot->m_pLeft != nullptr)
	{
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	}
	if (pRoot->m_pRight != nullptr)
	{
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
	}

	//�ڷ��ظ��ڵ�֮ǰ����·����ɾ����ǰ�ڵ�
	path.pop_back();
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
	if (pRoot == nullptr)
	{
		return;
	}

	//������·��������path
	std::vector<int>path;
	//����·���е�����֮��currentSum
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
		// �����ߵ��������Ҫ���ݣ�����ǰpath�е�root�ڵ����Ѿ�����Ҫ��
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