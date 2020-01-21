/*
函数功能：对不带头结点的单链表进行逆序排序
输入参数：
	firstRef：指向链表第一个结点的指针的指针（不带头结点）
*/
void recursiveReverse(LinkList* firstRef) {
	if (firstRef==NULL || *firstRef==NULL)
		return ;
	LinkList cur, rest;
	cur = *firstRef;
	rest = cur->next;
	if (rest == NULL)
		return ;
	recursiveReverse(&rest);
	cur->next->next = cur;
	cur->next = NULL;
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
	LinkList firstNode = (*headRef)->next;
	recursiveReverse(&firstNode);
	(*headRef)->next = firstNode;
}