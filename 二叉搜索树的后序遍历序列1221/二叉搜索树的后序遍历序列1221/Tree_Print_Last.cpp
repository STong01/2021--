#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������������򷵻�true�����򷵻�false��
bool VerifySquenceOfBST(int sequence[], int length)
{
	if (sequence == nullptr || length <= 0)
	{
		return false;
	}

	//��������һ���ڵ㣬Ϊ��������ṹ�ĸ��ڵ㣬���ڵ�����������������ݶ��󣬱��������������ݶ�С
	int root = sequence[length - 1];

	//�ڶ������������������ڵ��ֵС�ڸ��ڵ��ֵ
	int i = 0;
	for (; i < length - 1; i++)
	{
		if (sequence[i] > root)
		{
			break;
		}
	}

	//�ڶ������������������ڵ��ֵ���ڸ��ڵ��ֵ
	int j = i;
	for (; j < length - 1; j++)
	{
		if (sequence[j] < root)
		{
			return false;
		}
	}

	//�ж��������ǲ��Ƕ���������
	bool left = true;
	if (i > 0)
	{
		//�������ݹ��ж��Ƿ�Ϊ����������
		left = VerifySquenceOfBST(sequence, i);
	}

	//�ж��������ǲ��Ƕ���������
	bool right = true;
	if (i < length - 1)
	{
		//�������ݹ��ж��Ƿ�Ϊ����������
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

	//�ӱ�����������һ���ڵ���ǰ��Ľڵ�һһ����������������������Ϊ����������
	//�������������������������Ƕ���������
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
		//��С�����������Ľڵ������ٴν����ж�
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