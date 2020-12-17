#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void PrintMatrixInCircle(int** numbers, int cols, int rows, int start)
{
	int endX = cols - 1 - start;
	int endY = rows - 1 - start;

	//从左到右打印一行
	for (int i = start; i <= endX; i++)
	{
		int number = numbers[start][i];
		cout << number << " ";
	}

	//从上到下打印一列
	if (start < endY)

	{
		for (int i = start + 1; i <= endY; i++)
		{
			int number = numbers[i][endX];
			cout << number << endl;
		}
	}

	//从右到左打印一行
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; --i)
		{
			int number = numbers[endY][i];
			cout << number << " ";
		}
	}


	//从下到上打印一列
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

//顺时针打印矩阵，将矩阵分为四个方向，从四个方向向中间缩，当缩小到行列交叉的时候，矩阵打印完毕
class Solution 
{
public:
	//upX为矩阵行往下数据变化、downX为矩阵行往上数据变化；
	//leftY为矩阵列往右数据变化、rightY为矩阵列往左变化；
	void print(int upX, int leftY, int downX, int rightY, vector<vector<int>> &matrix, vector<int> &ret) 
	{
		//从左往右打印一行数据
		for (int j = leftY; j <= rightY; ++j)
		{
			ret.push_back(matrix[upX][j]);
		}
		//从上往下打印一列数据
		for (int i = upX + 1; i <= downX; ++i)
		{
			ret.push_back(matrix[i][rightY]);
		}
		//打印数据前首先判断是否还存在未打印数据
		//从右往左打印一行数据
		int height = downX - upX + 1;
		if (height > 1)
		{
			for (int rightj = rightY - 1; rightj >= leftY; --rightj)
			{
				ret.push_back(matrix[downX][rightj]);
			}
		}
		//从下往上打印一列数据
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