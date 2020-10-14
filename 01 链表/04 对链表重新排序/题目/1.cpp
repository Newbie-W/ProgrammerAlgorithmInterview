/*
给定链表L0->L1->L2->...->Ln，把链表重新排序为L0->Ln->L1->L(n-1)->L2->L(n-2)->...。
要求:
 （1）在原来链表基础上进行排序，即不能申请新的结点
 （2）只能修改结点的next域，不能修改数据域

思路步骤：
（1）首先找到链表的中间结点（快慢指针）
（2）后半部分子链表逆序
（3）两部分子链表合并（从两个链表各取一个结点进行合并）

时间复杂度 O(N)
空间复杂度 O(1)
*/

/*
函数功能：找出链表Head的中间结点，把链表从中间断层两个子链表
输入参数：
	head:链表头结点
返回值：指向链表的中间结点的指针
*/
LinkList findMiddleNode(LinkList head) {
	if (head==NULL || head->next==NULL)
		return head;
	LNode* fast = head;		//快指针每次走两步
	LNode* slow = head;		//慢指针每次走一步
	LNode* slowPre = head;
	//当fast到链表尾时，slow恰好指向链表的中间结点
	while (fast!=NULL && fast->next!=NULL) {
		slowPre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	//把链表断开成两个独立的子链表
	slowPre->next = NULL;
	return slow;
}

/*
函数功能：对不带头结点的单链表翻转
输入参数：
	head:指向链表头结点
*/
LinkList reverse(LinkList head) {
	if (head==NULL || head->next==NULL)
		return head;
	LNode* pre = head;
	LNode* cur = head->next;
	LNode* next = cur->next;
	pre->next = NULL;
	
	//使当前遍历到的结点cur指向其前驱结点
	while (cur!=NULL) {
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = cur->next;
		cur = next;
	}
	return pre;
}

/*
函数功能：对链表进行排序
输入参数：
	head:指向链表头结点
*/ 
void reorder(LinkList head) {
	if (head==NULL || head->next==NULL)
		return ;
	//前半部分链表第一个结点
	LNode* cur1 = head->next;
	LNode* mid = findMiddleNode(head->next);
	//后半部分链表逆序后的第一个结点
	LNode* cur2 = reverse(mid);
	LNode* tmp = NULL;
	//合并两个链表
	while (cur1->next != NULL) {
		tmp = cur1->next;
		cur1->next = cur2;
		cur1 = tmp;
		
		tmp = cur2->next;
		cur2->next = cur1;
		cur2 = tmp;
	}
	cur1->next = cur2;
}