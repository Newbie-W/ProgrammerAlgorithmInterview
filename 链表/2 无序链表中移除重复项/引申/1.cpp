/*
用cur指向链表第一个结点，此时分两种情况：
1.如果cur->data == cur->next->data,那么删除cur->next结点
2.如果cur->data != cur->next->data,那么删除cur = cur->next，继续遍历其余结点
*/
LinkList removeDupRecursion(LinkList head) {
	if (head->next == NULL)
		return head;
	LNode* cur = head;
	while (cur->next) {
		if (cur->data == cur->next->data) {
			LNode* tmp = cur->next;
			cur->next = cur->next->next;
			free(tmp);
		} else {
			cur = cur->next;
		}
	}
	return head;
}