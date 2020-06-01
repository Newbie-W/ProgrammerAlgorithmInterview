/*
单链表有环指的是单链表当中某个结点的next指针域指向链表中在它之前的某一结点，这样在链表的尾部就形成了一个环形结构。如何判断单链表是否有环存在？
法二：快慢指针遍历法


时间复杂度 O(N)
空间复杂度 O(1)
*/

/*
函数功能：判断单链表是否有环
输入参数：
	head：链表头结点
返回值：
	NULL：无环，否则返回slow与fast指针相遇点的指针
*/
LNode* isLoop(LinkList head) {
	if (head==NULL || head->next==NULL)
		return NULL;
	//初始化两个指针都指向链表第一个结点
	LNode *slow = head->next;
	LNode *fast = head->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return slow;
	}
	return NULL;
}

/*
函数功能：找出环的入口点
输入参数：
	head：fast与slow指针相遇点
返回值：
	NULL：无环，否则返回slow与fast指针相遇点的指针
*/
LNode* findLoopNode(LinkList head, LNode* meetNode) {
	LNode* first = head->next;
	LNode* second = meetNode;
	while (first != second) {
		first = first->next;
		second = second->next;
	}
	return first;
}