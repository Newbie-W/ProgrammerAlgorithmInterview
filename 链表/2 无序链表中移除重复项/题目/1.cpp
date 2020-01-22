/*
给定一个没有排序的链表，去掉其重复项，并保留原顺序；例1->3->1->5->5->7，去掉重复项后变为1->3->5->7
法一：顺序删除
通过双重循环一一比对，重复删除结点。

时间复杂度 O(N^2)
空间复杂度 O(1)	（遍历链表过程中，使用了常量个额外的指针变量来保存当前遍历的结点、前驱结点和被删除的结点）
*/

/*
函数功能：对带头结点的无序单链表删除重复的结点
输入参数：
	head:指向链表头结点
*/ 
void removeDup(LinkList head) {
	if (head==NULL || head->next==NULL)
		return ;
	LNode* outerCur = head->next;	//外层循环指针，指向链表第一个结点
	LNode* innerCur = NULL;			//内层循环用来遍历outerCur后面的结点
	LNode* innerPre = NULL;			//innerCur的前驱结点
	LNode* tmp = NULL;				//用来指向被删除结点的指针
	for (; outerCur!=NULL; outerCur=outerCur->next) {
		for (innerCur=outerCur->next,innerPre=outerCur; innerCur!=NULL; ) {
			//找到重复结点删除
			if (outerCur->data == innerCur->data) {
				tmp = innerCur;
				innerPre->next = innerCur->next;
				innerCur = innerCur->next;
				free(tmp);
			} else {
				innerPre = innerCur;
				innerCur = innerCur->next;
			}
		}
	}
}