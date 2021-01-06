#include "slist.h"
#include <stdio.h>
#include <stdlib.h>

void SListInit(SList* plist){
	assert(plist);

	plist->_head = NULL;
}

void SListDestory(SList* plist){
	SListNode * tmp;
	while (plist->_head){
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

void SListPushFront(SList* plist, SLTDataType x){
	assert(plist);
	SListNode * cur = (SListNode * )malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}

void SListPopFront(SList* plist){
	assert(plist);
	SListNode * tmp;
	if (plist->_head){
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
void SListPrint(SList* plist){
	assert(plist);
	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next){
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}

SListNode* SListFind(SList* plist, SLTDataType x) {
	assert(plist);

	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next){
		if (cur->_data == x){
			return cur;
		}
	}
	return NULL;
}
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x){
	assert(pos);

	SListNode * cur = (SListNode *)malloc(sizeof(SListNode *));
	cur->_data = x;
	cur->_next = cur->_next;
	pos->_next = cur;

}
// 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos){
	assert(pos);
	SListNode * tmp = pos->_next;

	pos->_next = tmp->_next;
	free(tmp);
}

void SListReverse(SList * plist){//单链表逆序
	assert(plist->_head);
#if 0
	SListNode * tmp = plist->_head->_next;
	SListNode * cur = plist->_head;
	while(tmp){
		cur->_next = tmp->_next;
		tmp->_next = plist->_head;
		plist->_head = tmp;
		tmp = cur->_next;
	}
#elif 0
	SList * reve = (SList*)malloc(sizeof(SList));
	SListInit(reve);
	SListNode*cur;
	for (cur = plist->_head; cur; cur = cur->_next){
		SListPushFront(reve, cur->_data);
	}
	SListDestory(plist);
	plist->_head = reve->_head;
#else
	SListNode * tmp = plist->_head->_next;//纪录next
	SListNode * cur = plist->_head;
	cur->_next = NULL;//断链，将头结点和naxt断开，有tmp纪录，所以能找到
	while (tmp){//每次循环完成断链，然后与旧头重新成链的过程，当旧链结束（tmp）为空时跳出循环
		plist->_head = tmp;//换新头，tmp位置成为心头，旧头成为他的第一个节点
		tmp = tmp->_next;//纪录下次循环中的tmp的位置，因为tmp在这次循环中已经用完，而且后面就要断链。
		plist->_head->_next = cur;//断链，与旧头形成新链
		cur = plist->_head;//纪录旧头的位置，方便下次循环成为新链
	}
#endif
}
