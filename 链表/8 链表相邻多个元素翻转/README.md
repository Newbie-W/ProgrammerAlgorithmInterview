### 情境：

> - K链表翻转是指把每K个相邻的结点看成一组进行翻转，如果剩余结点不足K个，则保持不变。假设给定链表1->2->3->4->5->6->7和一个数K，如果K的值为2，那么翻转后的链表为2->1->4->3->6->5->7。如果K的值为3，那么翻转后的链表为3->2->1->6->5->4->7<br>
> - 实现reverseK()函数，可在原来基础上添更多函数。

```C++
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

LinkList reverseK(LinkList head, int k);
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
	reverseK(head, 3);
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
思路步骤：
与1.7翻转形式类似。掐头去尾留中间，中间翻转；然后拼接好，再重复前面步骤对后面的k个元素