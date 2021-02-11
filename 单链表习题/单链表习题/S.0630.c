#include "List.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	List list;
	ListInit(&list);
	ListPushBack(&list, 7);
	ListPushBack(&list, 6);
	ListPushBack(&list, 5);
	ListPushBack(&list, 4);
	ListPrint(&list);
	system("pause");
	return 0;
}