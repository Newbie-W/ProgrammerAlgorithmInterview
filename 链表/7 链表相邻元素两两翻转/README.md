### 情境：

> - 把链表相邻元素翻转。（如1->2>...->7，逆序后为2->1->4->3...->7）<br>
> - 实现reverse()函数，可在原来基础上添更多函数。

```C++
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

void reverse(LinkList head);
/*更多函数及实现等可添至此处*/

int main() {
	int i = 1;
	//链表头指针
	LinkList head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	LinkList tmp = NULL;
	LinkList cur = head;
	for (; i<8; i++) {
		tmp = (LinkList)malloc(sizeof(LNode));
		tmp->data = i;
		tmp->next = NULL;
		cur->next = tmp;
		cur = tmp;
	}
	printf("顺序输出：");
	for (cur=head->next; cur!=NULL; cur=cur->next)
		printf("%d ", cur->data);
	reverse(head);
	printf("\n逆序输出：");
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
- 法一：交换值法（交换数据域部分，不需要调整链表结构，但一般不太符合考官考点）
- 法二：就地逆序法