### 情境：

> - 找出单链表中的倒数第k个元素，如1->2->...->7，则倒数第k=3个元素为5
> - 实现findLastK()函数，可在原来基础上添更多函数。

```C++
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

void findLastK(LinkList head, int k);
/*更多函数及实现等可添至此处*/

/*
函数功能：构造一个单链表
*/
void constructList() {
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
		cur=tmp;
	}
}

/*
函数功能：顺序打印单链表结点的数据
*/
void printList(LinkList head) {
	for (LNode* cur=head->next; cur!=NULL; cur=cur->next)
		printf("%d ", cur->data);
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
	LinkList result;
	//链表头指针
	LinkList head = constructList();
	printf("链表： ");
	printList(head);
	result = findLastK(head, 3);
	if (result)
		printf("\n链表倒数第3个元素为%d", result->data);
	freeList(head);
	return 0;
}
```

### 方法
- 法一：顺序遍历两遍法
> 思路：遍历单链表，求出链表长度n，再转换为求顺数第n-k个元素。
- 法二：快慢指针法

---
### 引申

> 将单链表向右旋转k个位置<br>
> （给定单链表1->2->3...->7，k=3，那么旋转后单链表为5->6->7->1->2->3->4）
> > **方法（思路步骤）**  
> > 1. 首先找到倒数第k+1个结点slow和尾结点fast
> > 2. 把链表断开为两个子链表，其中后半部分子链表结点的个数为k
> > 3. 使原链表的尾结点指向链表的第一个结点
> > 4. 使链表的头结点指向原链表倒数第k个结点