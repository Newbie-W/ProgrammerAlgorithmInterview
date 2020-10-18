### 情境：

> - 单链表相交指的是两个链表存在完全重合的部分（两链表 从中间某个位置到最终是一样的，如下图1.11.1）。要求判断两个链表是否相交，如果相交，那么找出相交处的结点。<br>
> ![img1.11.1 图](https://github.com/Newbie-W/ProgrammerAlgorithmInterview/blob/master/pics/1.11/img%201.11.1.png)<br>
> - 实现 isIntersect()函数，可在原来基础上添更多函数。

```C++
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

void isIntersect(LinkList head);
/*更多函数及实现等可添至此处*/

void printList(LinkList head) {
	for (LNode* cur=head->next; cur!=NULL; cur=cur->next)
		printf("%d ", cur->data);
	printf("\n");
}

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
	//链表头结点
	LinkList head1 = (LinkList)malloc(sizeof(LNode));
	head1->next = NULL;
	//链表头结点
	LinkList head2 = (LinkList)malloc(sizeof(LNode));
	head2->next = NULL;
	LNode* tmp = NULL;
	LNode* cur = head1;
	LNode* p = NULL;
	// 构造第一个链表
	for (; i<8; i++) {
		tmp = (LinkList)malloc(sizeof(LNode));
		tmp->data = i;
		tmp->next = NULL;
		cur->next = tmp;
		cur = tmp;
		if (i == 5)
			p = tmp;
	}
	cur = head2;
	// 构造第一个链表
	for (; i<8; i++) {
		tmp = (LinkList)malloc(sizeof(LNode));
		tmp->data = i;
		tmp->next = NULL;
		cur->next = tmp;
		cur = tmp;
	}
	// 使它们相交于结点5
	cur->next = p;
	printf("head1（地址：数据域）： ");
	printList(head1);
	printf("head2（地址：数据域）： ");
	printList(head2);
	LNode* interNode = isIntersect(head1, head2);
	if (interNode == NULL) {
		printf("这两个链表不相交");
	} else {
		printf("这两个链表相交点为：%d", interNode->data);
	}
	freeList(head1);
	// 释放链表head2所占的空间，相交后重复的结点已经被free(head1)释放（因此在释放链表head2的时候只需要释放它们相交的结点的所有前驱结点即可）
	for (cur=head2->next; cur != NULL; ) {
		if (cur == interNode)
			break;
		tmp = cur;
		cur = cur->next;
		freeList(tmp);
	}
	return 0;
}
```

### 方法
- 法一：Hash法
> **思路**：如果有两个链表相交，那么它们一定会有公共结点，由于结点的地址可以作为结点的唯一标识，那么可以通过判断两个链表中的结点是否有相同的地址来判断链表是否相交。<br>
> **具体实现**: 首先遍历链表head1，把遍历到的所有结点的地址存放到Hash表中；接着遍历链表head2，每遍历到一个结点，就判断这个结点的地址在Hash表中是否存在。如果存在，那么说明两个链表相交并且当前遍历到的结点就是它们的相交点，否则，直到链表head2遍历结束，就说明这两个单链表不相交。<br>
> **复杂度分析**：
> > 时间复杂度：O(n1+n2)，需要分别遍历两个链表，n1、n2分别为两个链表的长度<br>
> > 空间复杂度：O(n1)，需要申请额外的存储空间来存储链表head1中结点的地址<br>
- 法二：首尾相接法
> **思路**：将两个链表首尾相连，（如，把链表head1尾结点链接到head2的头指针），然后检测这个链表是否存在环。如果存在，则两个链表相交，而环入口结点即为相交的结点。如下图所示（具体实现方法及算法性能分析见1.6）<br>
> ![img1.11.2 图](https://github.com/Newbie-W/ProgrammerAlgorithmInterview/blob/master/pics/1.11/img%201.11.2.png)<br>
- 法三：尾结点法
> **思路**：如果两个链表相交，那么两个链表从相交点到链表结束都是相同的结点，必然是Y字形，所以判断两个链表的最后一个结点是不是相同即可。即先遍历一个链表，直到尾部，再遍历另外一个链表，如果也可以走到同样的结尾点，则两个链表相交，这时记下两个链表的长度n1、n2，再遍历一次，长链表结点先出发前进|n1-n2|步，之后两个链表同时前进，每次一步，相遇的第一点即为两个链表相交的第一个点<br>

---
### 引申

> 如果单链表有环，如何判断两个链表是否相交
> > **方法**  
> > （1）如果一个单链表有环，另一个没环，那么它们肯定不相交
> > （2）如果两个单链表都有环且相交，那么这两个链表一定共享这个环。判断两个有环的链表是否相交的方法：首先采用1.6节中介绍的方法，找到链表head1中环的入口点p1，然后遍历链表head2，判断链表中是否包含结点p1；
> > > 如果包含，则两链表相交；<br>
> > > 否则不相交。<br>
> > 
> > 找相交点的方法：把结点p1看作两个链表的尾结点，这样就可以把问题转换为求两个无环链表相交点的问题，即可采用本节介绍的方式解决问题。