/*
已知两个链表head1和head2均有序（如升序排列），请把它们合并成一个链表，要求合并后的链表依然有序。
思路步骤：
分别用指针head1和head2遍历列表，当head1指向的数据 < head2指向的数据，则将head1指向结点归入合并后的链表；否则，将head2指向结点归入合并后的链表。如果一个链表遍历结束，则把未结束链表连接到合并后链表的尾部。<br>

时间复杂度 O(N)
空间复杂度 O(1)
*/

/*
函数功能：合并两个升序排列的单链表
输入参数：
	head1 和 head2代表两个单链表
返回值：合并后链表的头结点
*/
LNode* merge(LNode* head1, LNode* head2) {
	if (head1==NULL || head1->next==NULL)
		return head2;
	if (head2==NULL || head2->next==NULL)
		return head1;
	LNode* cur1 = head1->next;		//用于遍历head1
	LNode* cur2 = head2->next;		//用于遍历head2
	LNode* head = NULL;	//合并后链表的头结点
	LNode* cur = NULL;	//合并后的链表在尾结点（合并链表的末尾结点）
	//合并后链表的头结点为第一个结点元素最小的那个链表的头结点
	if (cur1->data > cur2->data) {
		head = head2;
		free(head1);
		cur = cur2;
		cur2 = cur2->next;
	} 
	else {
		head = head1;
		free(head2);
		cur = cur1;
		cur1 = cur1->next;
	}
	//每次找链表剩余结点的最小值对应的结点连接到合并后链表的尾部
	while (cur1 && cur2) {
		if (cur1->data < cur2->data) {
			cur->next = cur1;
			cur = cur1;
			cur1 = cur1->next;
		}
		else {
			cur->next = cur2;
			cur = cur2;
			cur2 = cur2->next;
		}
	}
	
	//当遍历完一个链表，把另一个链表剩余的结点连接到合并后的链表后
	if (cur1 != NULL) {
		cur->next = cur1;
	}
	if (cur2 != NULL) {
		cur->next = cur2;
	}
	
	return head;
}