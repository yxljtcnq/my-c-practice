#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode* next;
}ListNode;


//初始化
void initList(ListNode* L)
{
	L->next = NULL;
}


//尾插法
void lastcreate(ListNode* list, int data)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = NULL;
	if (list->next == NULL)
	{
		list->next = newNode;
	}
	else
	{
		ListNode* p = list->next;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = newNode;
	}
}


//打印函数
void printList(ListNode* L)
{
	ListNode* p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//融合函数
struct ListNode* mergeTwoLists(ListNode* L1 ,ListNode* L2 , ListNode* L3) 
{
	ListNode* p1 = L1->next ;
	ListNode* p2 = L2->next;
	ListNode* p3 = L3;
	while (p1 && p2)
	{
		if (p1->data == p2->data)
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->data < p2->data)
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	p3->next = p1 ? p1 : p2;
}


//销毁函数
void destroyList(ListNode* l)
{
	if (l->next = NULL)
	{
		return;
	}
	else
	{
		ListNode* temp = l->next;
		l = l->next;
		free(temp);
	}
}

int main()
{
	ListNode L1;
	initList(&L1);
	ListNode L2;
	initList(&L2);
	ListNode L3;
	initList(&L3);
	lastcreate(&L1,10);
	lastcreate(&L1,20);
	lastcreate(&L1,30);
	lastcreate(&L1,40);
	lastcreate(&L1,50);
	lastcreate(&L2,1);
	lastcreate(&L2,11);
	lastcreate(&L2,21);
	lastcreate(&L2,31);
	lastcreate(&L2,41);
	lastcreate(&L2,51);
	printList(&L1);
	printList(&L2);
	mergeTwoLists(&L1, &L2,&L3);
	printList(&L3);
	destroyList(&L1);
	destroyList(&L2);
	destroyList(&L3);

}