#include <iostream>
using namespace std;

class A
{
public:
	A() :n2(0), n1(n2 + 2)
	{

	}

	void Print()
	{
		cout << "n1:" << n1 << ",n2:" << n2 << endl;
	}

private:
	int n1;
	int n2;

};

int StrToInt1(char* string)
{
	if (string == nullptr)
	{
		return 0;
	}

	int number = 0;
	while (*string != 0)
	{
		number = number * 10 + *string - '0';
		++string;
	}

	return number;
}

enum Status{ kValid = 0, kInvalid };
int g_nStatus = kValid;

long long StrToInt2Core(const char* digit, bool minus)
{
	long long num = 0;

	while (*digit != '\0')
	{
		if (*digit >= '0' && *digit <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag*(*digit - '0');
			
			if ((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			digit++;
		}
		else
		{
			num = 0;
			break;
		}
	}

	if (*digit == '\0')
	{
		g_nStatus = kValid;
	}
	return num;
}

int StrToInt2(const char* str)
{
	g_nStatus = kInvalid;
	long long num = 0;

	if (str != nullptr && *str != '\0')
	{
		bool minus = false;

		if (*str == '+')
		{
			str++;
		}
		else if (*str == '-')
		{
			str++;
			minus = true;
		}

		if (*str != '\0')
		{
			num = StrToInt2Core(str, minus);
		}

	}

	return (int)num;
}



int main()
{
	A a;
	a.Print();

	char str[] = "123";
	cout << StrToInt2(str) << endl;

	system("pause");
	return 0;
}