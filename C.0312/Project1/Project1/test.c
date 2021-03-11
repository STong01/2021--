//1.输出100到200之间的素数。
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//int i, j, n;
//for (i = 100; i <= 200; i++)
//{
//	n = sqrt(i)；
//for (j = 2; j <= n; j++)
//{
//if (i%j == 0)
//break;
//}
//if (j == i)
//printf("%d\n", i);
//}
//printf("\n");
//system("pause");
//return 0;
//}
//2.输出九九乘法表。
//#include<stdio.h>
//int main()
//{
//int i, j;
//for (i = 1; i <= 9; i++)
//{
//for (j = 1; j <= i; j++)
//{
//printf("  %d*%d=%d  ", i, j, i*j);
//}
//printf("\n");
//}
//system("pause");
//return 0;
//}
//3.输出1000到2000之间的闰年。
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int y;
//	for (y = 1000; y <= 2000; y++)
//	{
//		if (y % 400 == 0)
//		{
//			printf("%d  ", y);
//		}
//		else if (y % 4 == 0 && y % 100 != 0)
//		{
//			printf("%d  ", y);
//		}
//	}
//	system("pause");
//	return 0;
//}