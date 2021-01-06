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
// ��pos�ĺ�����в��� 
void SListInsertAfter(SListNode* pos, SLTDataType x){
	assert(pos);

	SListNode * cur = (SListNode *)malloc(sizeof(SListNode *));
	cur->_data = x;
	cur->_next = cur->_next;
	pos->_next = cur;

}
// ��pos��ǰ����в��� 
void SListEraseAfter(SListNode* pos){
	assert(pos);
	SListNode * tmp = pos->_next;

	pos->_next = tmp->_next;
	free(tmp);
}

void SListReverse(SList * plist){//����������
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
	SListNode * tmp = plist->_head->_next;//��¼next
	SListNode * cur = plist->_head;
	cur->_next = NULL;//��������ͷ����naxt�Ͽ�����tmp��¼���������ҵ�
	while (tmp){//ÿ��ѭ����ɶ�����Ȼ�����ͷ���³����Ĺ��̣�������������tmp��Ϊ��ʱ����ѭ��
		plist->_head = tmp;//����ͷ��tmpλ�ó�Ϊ��ͷ����ͷ��Ϊ���ĵ�һ���ڵ�
		tmp = tmp->_next;//��¼�´�ѭ���е�tmp��λ�ã���Ϊtmp�����ѭ�����Ѿ����꣬���Һ����Ҫ������
		plist->_head->_next = cur;//���������ͷ�γ�����
		cur = plist->_head;//��¼��ͷ��λ�ã������´�ѭ����Ϊ����
	}
#endif
}
