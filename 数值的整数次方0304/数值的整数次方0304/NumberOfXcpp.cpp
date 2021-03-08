#include <iostream>
#include <algorithm>
using namespace std;

//ÊµÏÖº¯Êıdouble Power
double Power_1(double base, int exponent)
{
	double result = 1.0;
	for (int i = 0; i <= exponent; i++)
	{
		result *= base;
	}
	return result;
}


double Power_2(double base, unsigned int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}
	if (exponent == 1)
	{
		return base;
	}

	double result = Power_2(base, exponent >> 1);

	result *= result;
	if (exponent & 0x1 == 1)
	{
		result *= base;
	}

	return result;
}

int main()
{

	system("pause");
	return 0;
}