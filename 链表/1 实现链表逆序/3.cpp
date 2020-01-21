/*
函数功能：对单链表进行逆序
输入参数：
	head：链表头结点
*/
void Reverse(LinkList head) {
	if (head==NULL || head->next==NULL)
		return ;
	LinkList cur = NULL;
	LinkList next = NULL;
	cur = head->next->next;
	head->next->next = NULL;
	while (cur != NULL) {
		next = cur->next;
		cur->next = head->next;
		head->next = cur;
		cur = next;
	}
}