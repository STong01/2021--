#include <iostream>
using namespace std;

//地上有一个m行n列的方格，一个机器人从坐标（0,0）的格子开始移动，每次可以向左右上下移动一格，但不能进入行坐标和列坐标之和大于k的格子
//问机器人能够到达多少格子

//得到一个数字的数位之和
int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

//判断机器人能否进入坐标为(row、col)的方格
bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	if (row >= 0 && row < rows && col >= 0 && col <= cols && getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row*cols + col])
	{
		return true;
	}
	return false;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	int count = 0;
	if (check(threshold, rows, cols, row, col, visited))
	{
		visited[row*cols + col] = true;

		count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
			+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
	}
	return count;
}

int movingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows <= 0 || cols <= 0)
	{
		return 0;
	}

	bool* visited = new bool[rows*cols];
	for (int i = 0; i < rows*cols; i++)
	{
		visited[i] = false;
	}

	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

	delete[] visited;

	return count;
}

int main()
{

	system("pause");
	return 0;
}