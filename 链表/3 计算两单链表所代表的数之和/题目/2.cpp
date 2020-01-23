/*
给定两个单链表，链表的每个结点代表一位数，计算两个数的和。例如，链表（3->1->5）和链表(5->9->2),输出8->0->8(即513+295)
法二：链表相加法
（1）每组结点进行相加后需要记录其是否有进位
（2）如果两个链表h1和h2的长度（L1和L2）不同（设L1<L2），L1位计算完，只需考虑L2剩余结点值（需考虑进位）
（3）对链表所有结点计算完，还需考虑进位问题。

时间复杂度 O(N)
空间复杂度 O(N)
*/

/*
函数功能：对两个带头结点的单链表所代表的数加和
输入参数：
	h1：第一个链表头结点
	h2：第二个链表头结点
返回值：相加后链表的头结点
*/
LinkList add(LinkList h1, LinkList h2) {
	if (h1==NULL || h1->next==NULL)
		return h2;
	if (h2==NULL || h2->next==NULL)
		return h1;
	int c = 0;		//用来记录进位
	int sum = 0;	//用来记录两个结点相加的值
	LNode* p1 = h1->next;	//用来遍历h1
	LNode* p2 = h2->next;	//用来遍历h2
	LNode* tmp = NULL;		//用来指向新创建的存储相加和的结点
	LinkList resultHead = (LinkList)malloc(sizeof(LNode)); //相加后链表头结点
	resultHead->next = NULL;
	LNode* p = resultHead;	//用来指向链表resultHead最后一个结点
	while (p1 && p2) {
		tmp = (LinkList)malloc(sizeof(LNode));
		tmp->next = NULL;
		sum = p1->data + p2->data;
		tmp->data = sum%10;			//两结点相加和
		c = sum/10;					//进位
		p->next = tmp;
		p = tmp;
		p1 = p1->next;
		p2 = p2->next;
	}
	//链表h2比h1长，接下来只需要考虑h2剩余结点的值
	if (p1 == NULL) {
		while (p2) {
			tmp = (LinkList)malloc(sizeof(LNode));
			tmp->next = NULL;
			sum = p2->data+c;
			tmp->data = sum%10;
			c = sum / 10;
			p->next = tmp;
			p = tmp;
			p2 = p2->next;
		}
	}
	//链表h1比h2长，接下来只需要考虑h1剩余结点的值
	if (p2 == NULL) {
		while (p1) {
			tmp = (LinkList)malloc(sizeof(LNode));
			tmp->next = NULL;
			sum = p1->data+c;
			tmp->data = sum%10;
			c = sum / 10;
			p->next = tmp;
			p = tmp;
			p1 = p1->next;
		}
	}
	//如果计算完成后还有进位，那么增加新的结点
	if (c == 1) {
		tmp = (LinkList)malloc(sizeof(LNode));
		tmp->next = NULL;
		tmp->data = 1;
		p->next = tmp;
	}
	return resultHead;
}