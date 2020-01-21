/*
给定一个带头结点的单链表，将其逆序。（如head->1->2>...->7，逆序后为head->7->6...->1）
法一：就地逆序
从第2个结点开始，依次修改其指针域，指向其前结点。为此需指针变量存放其前驱结点&&后继结点的地址。（注意首尾的处理）
*/

/*
函数功能：对链表逆序
输入参数：
	head：指向链表头结点的指针
*/
void reverse(LinkList head) {
	//判断链表是否为空
	if (head==NULL || head->next==NULL) {
		return ;
	}
	LinkList pre = NULL;	//前驱结点
	LinkList cur = NULL;	//当前结点
	LinkList next = NULL;	//后继结点
	//把链表首结点变为尾结点
	cur = head->next;
	next = cur->next;
	cur->next = NULL;
	pre = cur;
	cur = next;
	//使当前遍历到的结点cur指向其前驱结点
	while (cur->next != NULL) {
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = cur->next;	//本句的意义？未能理解
		cur = next;
	}
	//结点最后一个结点指向倒数第二个结点
	cur->next = pre;
	//链表的头结点指向原来链表的尾结点
	head->next = cur;
}