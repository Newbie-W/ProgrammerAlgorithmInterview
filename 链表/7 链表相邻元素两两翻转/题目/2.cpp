/*
把链表相邻元素翻转。（如1->2>...->7，逆序后为2->1->4->3...->7）
法二：就地逆序法
（1）如果单链表恰好有偶数个结点，那么只需要将奇偶结点对调即可；
（2）如果链表有奇数个结点，只需对调除最后一个结点外的所有结点；

时间复杂度 O(N)
空间复杂度 O(1)
*/

/*
函数功能：把链表相邻元素翻转。
输入参数：
	head：指向链表头结点
*/
void reverse(LinkList head) {
	//判断链表是否为空
	if (head==NULL || head->next==NULL)
		return ;
	LNode *cur = head->next;		//当前遍历结点
	LNode *pre = head;				//当前结点的前驱结点
	LNode *next = NULL;				//当前结点后继结点的后继结点
	while (cur && cur->next) {
		//如，head->1->2->3->4->5...
		next = cur->next->next;		//当前结点cur的后继结点的后继结点（如cur->data=3，next指向的对应数据为5）
		pre->next = cur->next;		//当前结点cur的前驱结点->cur的后继结点（如2->4）（->此处是“指向”，下同）
		cur->next->next = cur;		//cur的后继结点->cur（如4->3）(当前：...->4->3  5->...)
		cur->next = next;			//（如3->5）(当前：...->4->3->5->...)
		pre = cur;					//（如 前驱结点改为3）
		cur = next;					//（如 当前结点改为5）
	}
}