/*
方法（思路步骤）
1. 首先找到倒数第k+1个结点slow和尾结点fast
2. 把链表断开为两个子链表，其中后半部分子链表结点的个数为k
3. 使原链表的尾结点指向链表的第一个结点
4. 使链表的头结点指向原链表倒数第k个结点

时间复杂度 O(N)
空间复杂度 O(1)
*/
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

/*把链表右旋k个位置*/
void rotateK(LinkList head, int k) {
	if (head==NULL || head->next==NULL)
		return ;
	//fast指针先走k步，然后与slow同时走
	LNode *slow, *fast, *tmp;
	slow = fast = head->next;
	int i;
	for (i=0; i<k&&fast; i++) {	//前移k步
		fast = fast->next;
	}
	//判断k是否已超出链表长度
	if (i<k)
		return;
	//循环结束后slow指向链表倒数第k+1个元素，fast指向链表最后一个元素
	while (fast->next != NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	tmp = slow;
	slow = slow->next;
	tmp->next = NULL;
	fast->next = head->next;
	head->next = slow;
}

LinkList constructList() {
	int i = 1;
	LinkList head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	LinkList tmp = NULL;
	LinkList cur = head;
	//构造第一个链表
	for (; i<8; i++) {
		tmp = (LinkList)malloc(sizeof(LNode));
		tmp->data = i;
		tmp->next = NULL;
		cur->next = tmp;
		cur = tmp;
	}
	return head;
}

/*函数功能：顺序打印单链表结点的数据*/
void printList(LinkList head) {
	for (LNode* cur=head->next; cur!=NULL; cur=cur->next) {
		printf("%d ", cur->data);
	}
}

/*
函数功能：释放链表所占的内存空间
输入参数：
	head：链表头结点
*/
void freeList(LinkList head) {
	LNode* tmp = NULL;
	LNode* cur = NULL;
	for (cur=head->next; cur!=NULL; ) {
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

int main() {
	//链表头指针
	LinkList head = constructList();
	printf("旋转前：");
	printList(head);
	rotateK(head, 3);
	printf("旋转后");
	printList(head);
	freeList(head);
	return 0;
}