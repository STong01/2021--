#include <iostream>
#include <stack>
using namespace std;

//֮���δ�ӡ������
//��ʵ��һ����������֮����˳���ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��ҵ����˳���ӡ��
//�������ٰ��մ����ҵ�˳���ӡ����������������
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