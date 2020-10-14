/*
找出单链表中的倒数第k个元素，如1->2->...->7，则倒数第k=3个元素为5
法二：快慢指针法
设两个指针，一个比另一个先前移k步，然后然后两个指针同时往前移。循环到先行的指针值为NULL时，另一指针指向的位置即所找位置。

时间复杂度 O(N)
空间复杂度 O(1)
*/

/*
函数功能：找出链表倒数第k个结点
输入参数：
	head：链表头结点
返回值：指向倒数第k个结点的指针
*/
LinkList findLastK(LinkList head, int k) {
	if (head==NULL || head->next==NULL)
		return head;
	LNode *slow, *fast;
	slow = fast = head->next;
	int i;
	for (i=0; i<k&&fast; ++i) {	//前移k步
		fast = fast->next;
	}
	//判断k是否已超过链表长度
	if (i < k)
		return NULL;
	while (fast != NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}