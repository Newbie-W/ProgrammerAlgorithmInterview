/*
K链表翻转是指把每K个相邻的结点看成一组进行翻转，如果剩余结点不足K个，则保持不变。假设给定链表1->2->3->4->5->6->7和一个数K，如果K的值为2，那么翻转后的链表为2->1->4->3->6->5->7。如果K的值为3，那么翻转后的链表为3->2->1->6->5->4->7
思路步骤：
（与1.7翻转形式类似。掐头去尾留中间，中间翻转；然后拼接好，再重复前面步骤对后面的k个元素）

时间复杂度 O(N)（只对链表遍历一次）
空间复杂度 O(1)
*/

/*
函数功能：对不带头结点的单链表翻转。
输入参数：
	head：指向链表头结点
*/
LinkList reverse(LinkList head) {
	if (head==NULL || head->next==NULL)
		return ;
	LNode *cur = head->next;		//当前遍历结点
	LNode *pre = head;				//前驱结点
	LNode *next = cur->next;		//后继结点
	pre->next = NULL;
	
	//使当前遍历到的结点cur指向其前驱结点
	while (cur != NULL) {
		//如，1->2->3->4->5...
		next = cur->next;			//（如cur->data=2，next指向的对应数据为3）
		cur->next = pre;			//（如2->1）
		pre = cur;					//（如 前驱结点改为2）
		cur = next;					//（如 当前结点改为3）
	}
	return pre;
}

/*
函数功能：对链表k翻转。
输入参数：
	head：指向链表头结点
	k：表示以k个结点为1组进行翻转
*/
LinkList reverseK(LinkList head, int k) {
	if (head==NULL || head->next==NULL || k<2)
		return ;
	int i = 1;
	LNode *pre = head;
	LNode *begin = head->next;
	LNode *end = NULL;
	LNode *pNext = NULL;
	while (begin != NULL) {
		//如，head->1->2->3->4->5...
		end = begin;
		//找到从begin开始第k个结点
		for (; i<k; i++) {
			if (end->next != NULL)
				end = end->next;
			else		//剩余结点个数<k
				return;
		}
		pNext = end->next;				//找到第k个结点后的一结点
		end->next = NULL;				//断开第k个和k+1个结点的指针
		pre->next = reverse(begin);		//翻转k个元素，并拼在pre后
		begin->next = pNext;			//上句翻转后，begin到了末尾，后面接上第k+1个结点
		pre = begin;					//重新赋值新的pre（上一次翻转的末尾位，即原来的begin）
		begin = pNext;					//重新赋值新的begin
		i = 1;
	}
}