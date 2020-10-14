/*
单链表相交指的是两个链表存在完全重合的部分（两链表 从中间某个位置到最终是一样的）。要求判断两个链表是否相交，如果相交，那么找出相交处的结点。

思路步骤：
如果两个链表相交，那么两个链表从相交点到链表结束都是相同的结点，必然是Y字形，所以判断两个链表的最后一个结点是不是相同即可。即，
（1）先遍历一个链表，直到尾部；
（2）再遍历另外一个链表，如果也可以走到同样的结尾点，则两个链表相交
（3）若相交，记下两个链表的长度n1、n2；
（4）再遍历一次，长链表结点先出发前进|n1-n2|步，之后两个链表同时前进，每次一步，相遇的第一点即为两个链表相交的第一个点<br>


时间复杂度 O(n1+n2)（ 假设这两个链表长度分别为n1、n2，重叠结点个数为L（0<L<min(n1, n2)），则总共对链表进行遍历的次数为n1+n2+L+n1-L+n2-L = 2(n1+n2)-L ）
空间复杂度 O(1)（常数个额外指针变量）
*/

/*
函数功能：判断两个链表是否相交，如果相交找出相交点
输入参数：
	head1、head2:分别为两个链表的头结点
返回值：如果不相交返回NULL，如果相交返回相交结点
*/
LNode* isIntersect(LinkList head1, LinkList head2) {
	if (head==NULL || head->next==NULL
		head==NULL || head->next==NULL || head1==head2)
		return NULL;
	LNode* temp1 = head1->next;
	LNode* temp2 = head2->next;
	int n1 = 0, n2 = 0;
	// 遍历head1，找到尾结点，同时记录head1的长度
	while (temp1->next) {
		temp1 = temp1->next;
		++n1;
	}
	// 遍历head2，找到尾结点，同时记录head2的长度
	while (temp2->next) {
		temp2 = temp2->next;
		++n2;
	}
	// head1与head2有相同的尾结点
	if (temp1 == temp2) {
		// 长链表先走|n1-n2|步
		if (n1 > n2) {
			while (n1 - n2 > 0) {
				head1 = head1->next;
				--n1;
			}
		}
		if (n2 > n1) {
			while (n2 - n1 > 0) {
				head2 = head2->next;
				--n2;
			}
		}
		// 两个链表同时前进，找出相同的结点
		while (head1 != head2) {
			head1 == head1->next;
			head2 == head2->next;
		}
		return head1;
	}
	// head1与head2没有相同的尾结点
	else 
		return NULL;
}