### 情境：

> - 给定一个带头结点的单链表，将其逆序。（如head->1->2>...->7，逆序后为head->7->6...->1）
> - 实现reverse()函数，可在原来基础上添更多函数。

```C++
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

void reverse(LinkList head);
/*更多函数及实现等可添至此处*/

int main() {
	int i=1;
	//头结点
	LinkList head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	LinkList tmp = NULL;
	LinkList cur = head;
	//构造单链表
	for (; i<8; i++) {
		tmp = (LinkList)malloc(sizeof(LNode));
		tmp->data = i;
		tmp->next = NULL;
		cur->next = tmp;
		cur = tmp;
	}
	printf("逆序前：");
	for (cur=head->next; cur!=NULL; cur=cur->next) {
		printf("%d ", cur->data);
	}
	reverse(head);
	printf("逆序后：");
	for (cur=head->next; cur!=NULL; cur=cur->next) {
		printf("%d ", cur->data);
	}
	//释放链表所占空间
	for (cur=head->next; cur!=NULL; ) {
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	return 0;
}
```

### 方法
- 法一：就地逆序
- 法二：递归法
- 法三：插入法

---
### 引申

> （1）对不带头结点的单链表进行逆序

> （2）从尾到头输出
> > **方法**
> > - 法一：就地逆序+顺序输出（缺点：改变了链表原来的结构）
> > - 法二：逆序+顺序输出（缺点：需申请额外的存储空间）
> > - 法三：递归输出（先输出除当前结点外的后继子链表，然后输出当前结点）