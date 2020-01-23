### 情境：

> - 给定两个单链表，链表的每个结点代表一位数，计算两个数的和。例如，链表（3->1->5）和链表(5->9->2),输出8->0->8(即513+295)<br>
> - 实现add()函数，可在原来基础上添更多函数。

```C++
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

void add(LinkList h1, LinkList h2);
/*更多函数及实现等可添至此处*/

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
	int i = 1;
	//链表头指针
	LinkList head1 = (LinkList)malloc(sizeof(LNode));
	head1->next = NULL;
	LinkList head2 = (LinkList)malloc(sizeof(LNode));
	head2->next = NULL;
	LinkList tmp = NULL;
	LinkList cur = head1;
	LinkList addResult = NULL;
	//构造第一个链表
	for (; i<7; i++) {
		tmp = (LinkList)malloc(sizeof(LNode));
		tmp->data = i+2;
		tmp->next = NULL;
		cur->next = tmp;
		cur = tmp;
	}
	cur = head2;
	//构造第二个链表
	for (i=9; i>4; i--) {
		tmp = (LinkList)malloc(sizeof(LNode));
		tmp->data = i;
		tmp->next = NULL;
		cur->next = tmp;
		cur = tmp;
	}
	printf("Head1: ");
	for (cur=head1->next; cur!=NULL; cur=cur->next)
		printf("%d ", cur->data);
	printf("\nHead2: ");
	for (cur=head2->next; cur!=NULL; cur=cur->next)
		printf("%d ", cur->data);
	addResult = add(head1, head2);
	printf("\n相加后：");
	for (cur=addResult->next; cur!=NULL; cur=cur->next)
		printf("%d ", cur->data);
	freeList(head1);
	freeList(head2);
	freeList(addResult);
	return 0;
}
```

### 方法
- 法一：整数相加法（遍历链表，表示出链表对应的数，加和）（缺点：数过大，超出long int 表示范围）
- 法二：链表相加法