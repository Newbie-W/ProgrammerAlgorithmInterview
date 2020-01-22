/*
法二：递归法
逆序除第一个结点外的序列。做法是将第一个结点放置于已逆序的结点序列后。

时间复杂度 O(N)	（只需对链表进行一次遍历）
法二在性能方面，较法一，有所下降
*/

/*
函数功能：对不带头结点的单链表进行逆序排序
输入参数：
	firstRef：指向链表第一个结点的指针的指针（不带头结点）
*/
void recursiveReverse(LinkList* firstRef) {
	if (firstRef==NULL || *firstRef==NULL)
		return ;
	LinkList cur, rest;
	cur = *firstRef;	//cur: 1->2...->7
	rest = cur->next;	//rest: 2->3...->7
	if (rest == NULL)
		return ;
	//逆序rest，逆序后链表：7->6...->2
	recursiveReverse(&rest);
	//把第一个结点添加到尾结点:7->6...->1
	cur->next->next = cur;
	cur->next = NULL;
	//更新逆序后链表第一个结点的指向
	*firstRef = ref;
}

/*
函数功能：对带头结点的单链表进行逆序
输入参数：
	headRef：指向链表头结点指针的指针
*/
void reverse(LinkList* headRef) {
	if (*headRef==NULL || (*headRef)->next==NULL)
		return ;
	//获取链表第一个结点
	LinkList firstNode = (*headRef)->next;
	//对链表进行逆序
	recursiveReverse(&firstNode);
	//头结点指向逆序后链表的第一个结点
	(*headRef)->next = firstNode;
}