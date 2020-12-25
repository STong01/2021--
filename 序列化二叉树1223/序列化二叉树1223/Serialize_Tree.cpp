#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//��ʵ�������������ֱ��������л��ͷ����л�������
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int x) :
		m_nValue(x), m_pLeft(NULL), m_pRight(NULL) {
	}
};

void Serialize(BinaryTreeNode* pRoot, ostream& stream)
{
	if (pRoot == nullptr)
	{
		stream << "$,";
		return;
	}

	stream << pRoot->m_nValue << ",";
	Serialize(pRoot->m_pLeft, stream);
	Serialize(pRoot->m_pRight, stream);
}

//ReadStream����ÿ�δ����ж���һ�����ֻ���һ���ַ�'$'��
//�������ж�����һ������ʱ����������true�����򷵻�false��
bool ReadStream(istream& stream, int* number)
{
	if (stream.eof())
	{
		return false;
	}

	char buffer[32];
	buffer[0] = '\0';

	char ch;
	stream >> ch;
	int i = 0;
	while (!stream.eof() && ch != ',')
	{
		buffer[i++] = ch;
		stream >> ch;
	}

	bool isNumeric = false;
	if (i > 0 && buffer[0] != '$')
	{
		*number = atoi(buffer);
		isNumeric = true;
	}

	return isNumeric;
}

void Deserialize(BinaryTreeNode** pRoot, istream& stream)
{
	int number;
	if (ReadStream(stream, &number))
	{
		*pRoot = new BinaryTreeNode(number);
		(*pRoot)->m_nValue = number;
		(*pRoot)->m_pLeft = nullptr;
		(*pRoot)->m_pRight = nullptr;

		Deserialize(&((*pRoot)->m_pLeft), stream);
		Deserialize(&((*pRoot)->m_pRight), stream);
	}
}

class Solution 
{
public:
	char* Serialize(BinaryTreeNode *root)
	{
		if (!root) 
		{
			return "#";
		}

		string res = to_string(root->m_nValue);
		res.push_back(',');

		char* left = Serialize(root->m_pLeft);
		char* right = Serialize(root->m_pRight);

		char* ret = new char[strlen(left) + strlen(right) + res.size()];
		// �����string���ͣ�ֱ����operator += ,����char* ��Ҫ�ú���
		strcpy(ret, res.c_str());
		strcat(ret, left);
		strcat(ret, right);

		return ret;
	}

	// ����ʹ������&�� ��ʵ��ȫ�ֱ�����Ŀ��
	BinaryTreeNode* deseri(char *&s) 
	{
		if (*s == '#') 
		{
			++s;
			return nullptr;
		}

		// ������ڵ�ֵ
		int num = 0;
		while (*s != ',') 
		{
			num = num * 10 + (*s - '0');
			++s;
		}

		++s;
		// �ݹ鹹����
		BinaryTreeNode *root = new BinaryTreeNode(num);
		root->m_pLeft = deseri(s);
		root->m_pRight = deseri(s);

		return root;
	}

	BinaryTreeNode* Deserialize(char *str) 
	{
		return deseri(str);
	}
};

int main()
{

	system("pause");
	return 0;
}