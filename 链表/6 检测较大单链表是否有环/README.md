### 情境：

> - 单链表有环指的是单链表当中某个结点的next指针域指向链表中在它之前的某一结点，这样在链表的尾部就形成了一个环形结构。如何判断单链表是否有环存在？
> - 实现isLoop()和findLoopNode()函数。

```C++
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

LNode* isLoop(LinkList head);
LNode* findLoopNode(LinkList head, LNode* meetNode)；
/*更多函数及实现等可添至此处*/

/*
函数功能：构造链表
输入参数：
	head：链表头结点
*/
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
	cur->next = head->next->next->next;
	return head;
}

/*
函数功能：释放链表所占的内存空间
输入参数：
	head：链表头结点，如果链表有环，那么loopNode为环的入口
*/
void freeList(LinkList head, LNode* loopNode) {
	LNode* tmp = NULL;
	LNode* cur = NULL;
	for (cur=head->next; cur!=NULL; ) {
		tmp = cur;
		cur = cur->next;
		if (tmp == loopNode)
			return;		//似乎只释放了非环部分？
		free(tmp);
	}
}


int main() {
	//结点头指针
	LinkList head = constructList();
	LNode* meetNode = isLoop(head);
	LNode* loopNode = NULL;
	if (meetNode != NULL) {
		printf("%s\n", "有环");
		loopNode = findLoopNode(head, meetNode);
		printf("环的入口点为：%d\n", loopNode->data);
	} else
		printf("%s\n", "无环");
	freeList(head, loopNode);
	return 0;
}
```

### 方法
- 法一：蛮力法
> hash_set处理，看指针是否重复出现过
- 法二：快慢指针遍历法
> 慢指针（slow）可能没走完一圈，而快指针（fast）可能走了很多圈。<br>
> 假设同样时间内，slow走s步，fast走2s步（2s = s + n圈长度）<br>
> 设 环长r，链表长度L，入口环与相遇点距离x，起点到环入口距离(即非环链表部分的长度)a<br>
> 如图所示：![img1.6.1 图](/pics/img1.6.1.jpg)
> 可列公式：
> $$ 2s = s + nr \tag{1}$$
> $$ a + x = s \tag{2}$$
> $$ r = L - a \tag{3}$$<br>
> 由(1)式，知
> $$ s = nr $$ (相遇走的步数=n圈环长度)
> 则
> $$ a+x = nr = (n-1)r + L-a $$
> $$ a = (n-1)r + L-a-x $$
> 其中，```L-a-x```为相遇点到环入口的距离；a即前面非环链表部分长度 = (n-1) x 环长 + 相遇点到环入口的距离。故选择【链表头】和【相遇点】分别设指针，每次走一步，最终可在第一次相遇，且相遇在环入口点。

---
### 引申

> 如果链表有环，找出环的入口点（实现代码即，原题目的法二代码的findLoopNode()函数）<br>