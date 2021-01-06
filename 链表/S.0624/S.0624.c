#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

void listtest(){
	SList test;
	SListInit(&test);
	SListPushFront(&test, 1);
	SListPushFront(&test, 2);
	SListPushFront(&test, 4);
	SListPushFront(&test, 6);
	SListPushFront(&test, 9);
	SListPrint(&test);
	SListPopFront(&test);
	SListReverse(&test);
	SListPrint(&test);//¥Ú”°¡¥±Ì
	SListDestory(&test);
	SListPrint(&test);
}
int main(){
	listtest();
	system("pause");
	return 0;
}