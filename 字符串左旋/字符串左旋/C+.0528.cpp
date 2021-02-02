#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
//实现一个函数，可以左旋字符串中的k个字符。 
void left_remove(char *p, int n, int len)
{
	int i;
	for (i = 0; i <= n-1; i++)
	{
		int j = 0;
		char tmp = p[0];
		for (j = 0; j < len; j++)
		{
			p[j] = p[j + 1];
		}
		p[len - 1] = tmp;
	}
}
int main(){
	char arr[] = "ABCD";
	int n;
	int len = strlen(arr);
	printf("需要旋转的字符串：%s\n", arr);		
	printf("需要旋转的位数:");
	scanf("%d", &n);
	//while (n < 1 || n > len - 1)//对于输入旋转字符数的临界值判断，是否超过字符串长度
	//{
	//	if (n == len)//旋转字符数为字符串长度时，旋转后的字符串与旋转前的字符串一致，所以可直接输出
	//	{
	//		printf("%s", arr);
	//		system("pause");
	//		return 0;
	//	}
	//	else
	//	{
	//		printf("输入错误，请重新输入\n");
	//		scanf("%d", &n);
	//	}
	//}
	left_remove(arr, n, len);//函数用以完成旋转字符的功能
	printf("旋转后字符串: %s\n", arr);
	system("pause");
	return 0;
}
#endif

#if 1
//判断一个字符串是否为另外一个字符串旋转之后的字符串。
int find_round(char * src, char * find){
	char tmp[256] = { 0 };
	strcpy(tmp, src);
	strcat(tmp, src);
	return strstr(tmp, find) ? 1 : 0;
}
int main(){
	char src[] = { 20 };
	char find[] = { 20 };
	printf("输入需旋转的字符串：");
	scanf("%s", &src);
	printf("输入检验的字符串：");
	scanf("%s", &find);
	printf("%d\n", find_round(src, find));
	system("pause");
	return 0;
}
#endif