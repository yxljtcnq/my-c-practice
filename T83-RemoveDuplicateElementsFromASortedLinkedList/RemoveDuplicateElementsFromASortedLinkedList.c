#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct ListNode {
	int val;
	struct ListNode* next;

};

struct ListNode* deleteDuplicates(struct ListNode* head) {
	struct ListNode* p = head->next;
	while (p->next->next == NULL)
	{
		if (p->next->val == p->next->next->val)
		{
			struct ListNode* temp = p->next;
			p->next = p->next->next;
			free(temp);
		}
	}

}