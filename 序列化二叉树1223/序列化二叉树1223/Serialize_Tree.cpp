#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//请实现两个函数，分别用来序列化和反序列化二叉树
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

//ReadStream函数每次从流中读出一个数字或者一个字符'$'。
//当从流中读出是一个数字时，函数返回true；否则返回false；
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
		// 如果是string类型，直接用operator += ,这里char* 需要用函数
		strcpy(ret, res.c_str());
		strcat(ret, left);
		strcat(ret, right);

		return ret;
	}

	// 参数使用引用&， 以实现全局变量的目的
	BinaryTreeNode* deseri(char *&s) 
	{
		if (*s == '#') 
		{
			++s;
			return nullptr;
		}

		// 构造根节点值
		int num = 0;
		while (*s != ',') 
		{
			num = num * 10 + (*s - '0');
			++s;
		}

		++s;
		// 递归构造树
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