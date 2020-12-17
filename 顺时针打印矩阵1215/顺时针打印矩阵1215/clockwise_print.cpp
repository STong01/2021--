#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void PrintMatrixInCircle(int** numbers, int cols, int rows, int start)
{
	int endX = cols - 1 - start;
	int endY = rows - 1 - start;

	//�����Ҵ�ӡһ��
	for (int i = start; i <= endX; i++)
	{
		int number = numbers[start][i];
		cout << number << " ";
	}

	//���ϵ��´�ӡһ��
	if (start < endY)

	{
		for (int i = start + 1; i <= endY; i++)
		{
			int number = numbers[i][endX];
			cout << number << endl;
		}
	}

	//���ҵ����ӡһ��
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; --i)
		{
			int number = numbers[endY][i];
			cout << number << " ";
		}
	}


	//���µ��ϴ�ӡһ��
	if (start < endX && start < endY - 1)
	{
		for (int i = endY - 1; i>start + 1; i++)
		{
			int number = numbers[i][start];
			cout << number << endl;
		}
	}
}

void PrintMatrixClockwisely(int** numbers, int cols, int rows)
{
	if (numbers == nullptr || cols <= 0 || rows <= 0)
	{
		return;
	}

	int start = 0;

	while (cols > (start * 2) && rows > (start * 2))
	{
		PrintMatrixInCircle(numbers, cols, rows, start);
		start++;
	}
}

//˳ʱ���ӡ���󣬽������Ϊ�ĸ����򣬴��ĸ��������м���������С�����н����ʱ�򣬾����ӡ���
class Solution 
{
public:
	//upXΪ�������������ݱ仯��downXΪ�������������ݱ仯��
	//leftYΪ�������������ݱ仯��rightYΪ����������仯��
	void print(int upX, int leftY, int downX, int rightY, vector<vector<int>> &matrix, vector<int> &ret) 
	{
		//�������Ҵ�ӡһ������
		for (int j = leftY; j <= rightY; ++j)
		{
			ret.push_back(matrix[upX][j]);
		}
		//�������´�ӡһ������
		for (int i = upX + 1; i <= downX; ++i)
		{
			ret.push_back(matrix[i][rightY]);
		}
		//��ӡ����ǰ�����ж��Ƿ񻹴���δ��ӡ����
		//���������ӡһ������
		int height = downX - upX + 1;
		if (height > 1)
		{
			for (int rightj = rightY - 1; rightj >= leftY; --rightj)
			{
				ret.push_back(matrix[downX][rightj]);
			}
		}
		//�������ϴ�ӡһ������
		int weight = rightY - leftY + 1;
		if (weight > 1)
		{
			for (int downi = downX - 1; downi >= upX + 1; --downi)
			{
				ret.push_back(matrix[downi][leftY]);
			}
		}
	}
	vector<int> printMatrix(vector<vector<int>>& matrix) 
	{
		vector<int> ret;
		if (matrix.empty())
		{
			return ret;
		}

		int upX = 0, leftY = 0;
		int downX = matrix.size() - 1;
		int rightY = matrix[0].size() - 1;
		while (upX <= downX && leftY <= rightY) 
		{
			print(upX++, leftY++, downX--, rightY--, matrix, ret);
		}
		return ret;
	}
};

int main()
{
	system("pause");
	return 0;
}