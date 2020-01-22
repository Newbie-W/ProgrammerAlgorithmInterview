### 情境：

> - 给定一个没有排序的链表，去掉其重复项，并保留原顺序，例1->3->1->5->5->7，去掉重复项后变为1->3->5->7
> - 实现removeDup()函数，可在原来基础上添更多函数。

```C++
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

void removeDup(LinkList head);
/*更多函数及实现等可添至此处*/

int main() {
	int i = 1;
	//链表头指针
	LinkList head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	LinkList tmp = NULL;
	LinkList cur = head;
	for (; i<7; i++) {
		tmp = (LinkList)malloc(sizeof(LNode));
		if (i%2 == 0)
			tmp->data = i+1;
		else if (i%3 == 0)
			tmp->data = i-2;
		else 
			tmp->data = i;
		tmp->next = NULL;
		cur->next = tmp;
		cur = tmp;
	}
	printf("删除重复结点前：");
	for (cur=head->next; cur!=NULL; cur=cur->next)
		printf("%d ", cur->data);
	removeDup(head);
	printf("删除重复结点后：");
	for (cur=head->next; cur!=NULL; cur=cur->next)
		printf("%d ", cur->data);
	for (cur=head->next; cur!=NULL; ) {
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	return 0;
}
```

### 方法
- 法一：顺序删除
- 法二：递归法
- 法三：空间换时间

---
### 引申

> 如何从有序链表中移除重复项
> > **方法**
> > 上面提到的方法同样适用于有序，但未利用有序条件。（有序则无需两次遍历）