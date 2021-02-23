#include <iostream>
using namespace std;

//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//完成一个函数，输入这样的一个二维数组和一个整数，判断该数组中是否含有该整数
bool Find(int* matrix, int rows, int columns, int number)
{
	bool found = false;

	if (matrix != nullptr && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0)
		{
			if (matrix[row*columns + column] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row* columns + column]>number)
			{
				--column;
			}
			else
			{
				++row;
			}
		}
	}
	return found;
}

int main()
{

	system("pause");
	return 0;
}