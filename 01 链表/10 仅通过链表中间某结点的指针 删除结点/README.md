### 情境：

> - 假设给定链表1->2->3->4->5->6->7中指向第5个元素的指针，要求把结点5删除，删除后链表变为1->2->3->4->6->7<br>
> - 实现removeNode()函数，可在原来基础上添更多函数。

```C++
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

bool removeNode(LNode* p);
/*更多函数及实现等可添至此处*/

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
	int i = 1;
	//链表头结点
	LinkList head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	LNode* tmp = NULL;
	LNode* cur = head;
	LNode* p = NULL;
	//构造链表
	for (; i<8; i++) {
		tmp = (LinkList)malloc(sizeof(LNode));
		tmp->data = i;
		tmp->next = NULL;
		cur->next = tmp;
		cur = tmp;
		if (i == 5)
			p = tmp;
	}
	printf("删除结点%d前的链表：", p->data);
	printList(head);
	bool result = removeNode(p);
	if (result) {
		printf("删除该结点后的链表：");
		printList(head);
	}
	freeList(head);
	return 0;
}
```

### 方法
> 思路步骤：<br>
> 一般而言，删除单链表一结点p，首先要找到p的前驱结点pre，然后通过pre->next = p->next来实现对结点p的删除。（单链表给定指针，只能删除其后的结点。）但本题而言，无法获取结点p的前驱结点，因此，不能采用这种传统的方法。
> 可分两种情况：<br>
> （1）如果结点为链表最后一个结点，则无法删除该结点<br>
> （2）非链表最后一个结点，可以通过将其后继结点的数据复制到当前结点中，然后删除后继结点的方法<br>
> 把结点p的后继结点的数据复制到结点p的数据域中，然后删除p的后继结点<br>

---
### 引申

> 只给定单链表中某个结点p（非空结点），如何在p面前插入一个结点
> > **方法**  
> > 主要思路：首先分配一个新结点q，把结点q插入在结点p后，然后把p的数据域复制到结点q的数据域中，最后把结点p的数据域设置为待插入的值。