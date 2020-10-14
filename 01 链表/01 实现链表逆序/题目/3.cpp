/*
法三：插入法
从第二个结点起，遍历到结点，插入到头结点后（作第一个结点），直至遍历结束。
eg:
起始：	head->1->2->3->4...->7
下一步:	head->1  2->3->4...->7
下一步:	head->2->1  3->4...->7
下一步:	head->3->2->1  4...->7
...直至到链表末尾

时间复杂度 O(N)	（只需对链表进行一次遍历）
较法一，本方法无需存前驱结点地址；
较法二，无需递归，效率高
*/

/*
函数功能：对单链表进行逆序
输入参数：
	head：链表头结点
*/
void reverse(LinkList head) {
	if (head==NULL || head->next==NULL)
		return ;
	LinkList cur = NULL;	//当前指针
	LinkList next = NULL;	//后继结点
	cur = head->next->next;
	//设置链表第一个结点为尾结点
	head->next->next = NULL;
	//把遍历到结点插入到头结点的后面
	while (cur != NULL) {
		next = cur->next;
		cur->next = head->next;
		head->next = cur;
		cur = next;
	}
}