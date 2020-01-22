/*
法二：递归法
对于结点cur，首先递归地删除以cur->next为首的子链表中重复的结点，接着以cur->next为首的子链表中找出与cur有着相同数据域的结点并删除。

时间复杂度 O(N^2)
队规法会增加许多额外的函数调用，理论上效率比 法一 低
*/

/*
函数功能：对不带头结点的单链表删除重复结点
输入参数：
	head:指向链表第一个结点
*/
LinkList removeDupRecursion(LinkList head) {
	if (head->next==NULL)
		return head;
	LNode* pointer = NULL;
	LNode* cur = NULL;
	//对以head->next为首的子链表删除重复结点
	head->next = removeDupRecursion(head->next);
	pointer = head->next;
	//找出以head->next为首的子链表中与head结点相同的结点并删除
	while (pointer != NULL) {
		if (head->data == pointer->data) {
			cur->next = pointer->next;
			free(pointer);
			pointer = cur->next;
		} else {
			pointer = pointer->next;
			cur = cur->next;
		} 
	}
	return head;
}

/*
函数功能：对带头结点的单链表删除重复结点
输入参数：
	head:指向链表头结点
*/ 
void removeDup(LinkList head) {
	if (head == NULL)
		return ;
	head->next = removeDupRecursion(head->next);
}