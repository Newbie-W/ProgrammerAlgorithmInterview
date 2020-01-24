### 情境：

> - 给定链表L0->L1->L2->...->Ln，把链表重新排序为L0->Ln->L1->L(n-1)->L2->L(n-2)->...。<br>
> 要求:<br>
> （1）在原来链表基础上进行排序，即不能申请新的结点<br>
> （2）只能修改结点的next域，不能修改数据域<br>
> - 实现reorder()函数，可在原来基础上添更多函数。

```C++
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

void reorder(LinkList head);
/*更多函数及实现等可添至此处*/

/*
函数功能：释放量表所占的内存空间
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
	printf("排序前： ");
	for (cur=head->next; cur!=NULL; cur=cur->next)
		printf("%d ", cur->data);
	reorder(head);
	printf("\n排序后： ");
	for (cur=head->next; cur!=NULL; cur=cur->next)
		printf("%d ",cur->data);
	freeList(head);
	return 0;
}
```

### 方法
> 思路步骤：<br>
> （1）首先找到链表的中间结点（快慢指针）
> （2）后半部分子链表逆序
> （3）两部分子链表合并（从两个链表各取一个结点进行合并）

---
### 引申

> 如何查找链表的中间结点
> > **方法**  
> > 使用上面题目题解中的findMiddleNode()函数即可。（思路：快慢指针。两个指针从链表的第一个结点开始同时遍历，慢指针走一步，快指针走两步。当快指针到链表尾部，慢指针刚好到链表中部。链表长度为奇数时，慢指针指向为链表中间指针；链表长度为偶数时，慢指针指向结点和慢指针指向结点的下一结点都是链表的中间结点）