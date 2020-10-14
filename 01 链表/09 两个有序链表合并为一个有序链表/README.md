### 情境：

> - 已知两个链表head1和head2均有序（如升序排列），请把它们合并成一个链表，要求合并后的链表依然有序。<br>
> - 实现merge()函数，可在原来基础上添更多函数。

```C++
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

LNode* merge(LNode* head1, LNode* head2);
/*更多函数及实现等可添至此处*/

/*
函数功能：构造链表
输入参数：
	start：链表第一个结点的值
*/
LinkList constructList(int start) {
	int i = start;
	LinkList head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	LinkList tmp = NULL;
	LinkList cur = head;
	for (; i<7; i+=2) {
		tmp = (LinkList)malloc(sizeof(LNode));
		tmp->data = i;
		tmp->next = NULL;
		cur->next = tmp;
		cur = tmp;
	}
	return head;
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

void printList(LinkList head) {
	for (LNode* cur=head->next; cur!=NULL; cur=cur->next)
		printf("%d ", cur->data);
	printf("\n");
}

int main() {
	LinkList head1 = constructList(1);
	LinkList head2 = constructList(2);
	printf("head1:");
	printList(head1);
	printf("head2");
	printList(head2);
	printf("合并后的链表：");
	LinkList head = merge(head1, head2);
	printList(head);
	return 0;
}
```

### 方法
分别用指针head1和head2遍历列表，当head1指向的数据 < head2指向的数据，则将head1指向结点归入合并后的链表；否则，将head2指向结点归入合并后的链表。如果一个链表遍历结束，则把未结束链表连接到合并后链表的尾部。<br>
假定均按升序排列，首先通过比较链表第一个结点中的元素大小，确定最终合并链表的头结点；接下来每次找两链表的剩余结点的最小值，合并到结果链表里。在实现时需注意，要释放（两个链表中）首个结点较大的链表头结点。