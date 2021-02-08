#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stddef.h>

#if 0
//strtok,字符串查找；
int main(){
	char str[] = "you are,a.student";
	char str1[] = "i am.a,student";
	char sep[] = ",. ";
	char *tok = NULL;
	char maxlen[20] = "";//存储最长字符单词；
	for (tok = strtok(str, sep); tok != NULL; tok = strtok(NULL, sep)){
		//puts(tok);
		if (strlen(maxlen) < strlen(tok)){
			strcpy(maxlen, tok);
		}
	}
	puts(maxlen);
	system("pause");
	return 0;
}
#endif

#if 0
//长度受限制字符串操作；
int main(){
	char str1[] = "abcdef";
	char str2[] = "abcahiohios";
	int n = strncmp(str1+1, str2+1, 3);//比较前n个字符；
	printf("%d\n", n);
	system("pause");
	return 0;
}
#endif

#if 0
//拷贝字符串前n个字符；
int main(){
	char str1[] = "abcdef";
	char str2[] = "1234";
	strncpy(str1, str2, 6);
	puts(str1);
	system("pause");
	return 0;
}
#endif

#if 0
//strncat:拼接前n个字符；
int main(){
	char str1[20] = "abcdef";
	char str2[] = "1234";
	strncat(str1, str2, 6);//将str2前n个字符拼接到str1后面；
	puts(str1);
	system("pause");
	return 0;
}
#endif

#if 0
//strstr:如果找到相对应的字符，就返回找到的首地址；如果没有找到，就返回NULL；
int main(){
	char str1[] = "abcbcdef";
	char str2[] = "bcdefk";
	char *p = NULL;
	if (p=strstr(str1, str2))//在str1中查找str2字符；
		puts(p);
	else
		printf("没有找见\n");
	system("pause");
	return 0;
}
#endif

#if 0
//理解strstr；
char *my_strstr(const char*str1, const char*str2){
	char*p = (char*)str1;
	char*s1 = (char*)str1;
	char*s2 = (char*)str2;
	assert(str1 != NULL);
	while (*p){
		s1 = p;
		s2 = (char*)str2;
		while (*s1 && *s2 && *s1 == *s2){
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return p;
		p++;
	}
	return NULL;
}
int main(){
	char str1[] = "abcbcdefggg";
	char str2[] = "bcdef";
	char *p = NULL;
	if (p = my_strstr(str1, str2))
		puts(str1);
	system("pause");
	return 0;
}
#endif

#if 0
//memcpy:拷贝字符；遇到\0后不会停止拷贝;
//模拟实行memcpy;
void *my_memcpy(void *dest, const void *src, size_t count){
	void *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (count){
		*(char*)dest = *(char*)src;
		src = (char*)src + 1;
		dest = (char*)dest + 1;
		count--;
	}
	return ret;
}

int main(){
	char str1[] = "abcdef";
	char str2[] = "12345678";
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7 };
	int arr2[10] = { 9, 8, 0 };
	my_memcpy(arr1, arr1+2, 5 * sizeof(int));
	//memcpy(str1, str2, 2);//将str2前n个字符拷贝到str1对应位置；
	puts(str1);
	system("pause");
	return 0;
}
#endif

#if 0
//memmove:字符拷贝，
int main(){
	char a[20] = "1234567890";
	char b[20] = "qwertyui";
	memmove(a, b + 2, 5);
	puts(a);
	system("pause");
	return 0;
}
#endif

#if 0
//结构体；
//struct{
//	int num;
//	char name[20];
//	int age;
//}aa;
//
//struct{
//	int num;
//	char name[20];
//	int age;
//}*p;
struct student{
	int num;       //4
	char name[20]; //20
	int age;       //4
};
//结构大小：->内存字节对齐问题，类型和其中所占字节大的对齐；
struct data{
	int num;    //4
	char a;     //1
	char b;     //1
	double d;   //8   
//前面小的在一边（int，char，char），小的内存之和和大的对齐（对齐为大的倍数）；
//如果小的在两边，则两边分别对齐；
};
int main(){
	struct student a;
	printf("%d\n", sizeof(struct student));//28
	system("pause");
	return 0;
}
#endif

#if 0
//结构体
typedef struct student{
	int num;
	char name[20];
}STU;
//typedef    表示用STU表示struct student；
//则STU a = struct student a；
struct node{
	int n;
	//struct node next;结构体中不能包含值类型；
	struct node *next;//但是可以包含自己的指针类型；
};
int main(){
	system("pause");
	return 0;
}
#endif

#if 0
//结构体
struct s1{
	char c1;
	int c2;
	char c3;
};
//1、第一个成员永远都放在结构体起始位置的0偏移量处；
//2、从第二个成员开始，每个成员都放在某个对齐数的整数倍的偏移处；
//某个对齐数：成员自身对齐数和默认对齐数的较小值；
//3、结构体总大小就是所有成员对齐数中的最大值的整数倍；
int main(){
	printf("%d\n",offsetof(struct s1,c1));
	printf("%d\n", offsetof(struct s1, c2));
	printf("%d\n", offsetof(struct s1, c3));
	printf("%d\n", sizeof(struct s1));
	system("pause");
	return 0;
}
#endif

#if 0
//结构体;
struct s2{
	char c1;//1
	char c2;//1
	int c3;//4
};
struct s3{
	struct s2 a;//8   嵌套的结构体和自身对齐数对齐->4
	int b;//4
	//double c;//8
	char c[15];//15
};
int main(){
	printf("%d\n", sizeof(struct s3));
	system("pause");
	return 0;
}
#endif

#if 0
//结构体
typedef struct student{
	int num;
	char name[20];
	char sex;
}STU;
int main(){
	STU a = { 1, "zhangsan", 'f' };//初始化以及赋值
	STU b;//初始化
	b.num = 2;//赋值
	strcpy(b.name, "lisi");//赋值
	b.sex = 'm';//赋值
	STU c;
	STU *p = &a;//赋值
	c = { 3, "wangwu", 'm' };
	printf("%d,%s,%c\n",a.num,a.name,a.sex);
	printf("%d,%s,%c\n", b.num, b.name, b.sex);
	printf("%d,%s,%c\n", c.num, c.name, c.sex);
	printf("%d,%s,%c\n", (*p).num, p->name, p->sex);
	system("pause");
	return 0;
}
#endif

#if 0
//结构体
#pragma pack(1)//默认对齐数为1
struct data{
	int a;
	char c;
};
int main(){
	printf("%d\n", sizeof(struct data));
	system("pause");
	return 0;
}
#endif

#if 0
//位段
//struct A{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
struct A{
//位段上的空间是按照要求开辟一个或者四个字节；
	char e;//1字节
	int a : 2;//00000010 00000000 00000000 00000000//占字节中的n位，并且不能跨字节占位，若不够则重新开辟新空间；
	int b : 5;//01000010 00000000 00000000 00000000
	int c : 10;//01000010 00000000 00000010 00000000
	int d : 30;//重新开辟新空间；
};
int main(){
	printf("%d\n", sizeof(struct A));
	system("pause");
	return 0;
}
#endif

#if 0
//枚举--一一列举
enum week{Mon = 1, Tues, Wed, Thu, Fri，Sat，Sun};//在没有给值的情况下，默认从0开始；
enum data{a=5,b,c,d,e=1,f};//里面的值为枚举常量；
int main(){
	enum week w;//定义枚举变量w；
	enum data t;
	w = Thu;
	t = d;
	printf("%d\n", w);
	printf("%d\n", t);
	system("pause");
	return 0;
}
#endif

#if 0
//共用体；
union data{
	int a;
	char b;
	double c;
	int i;
	char e;
};
int main(){
	union data aa;
	union data d;
	d.i = 0x11223344;
	d.e = 0x55;
	printf("%x\n", d.i);
	printf("%d\n", sizeof(aa));
	printf("%p\n", &aa.a);
	printf("%p\n", &aa.b);
	printf("%p\n", &aa.c);
	system("pause");
	return 0;
}
#endif

#if 1
int sys_check(){
	int a = 1;
	return *((char*)&a);
}
int main(){
	int n = sys_check();
	if (n == 1)
		printf("小端\n");
	else
		printf("大端\n");
	system("pause");
	return 0;
}
#endif