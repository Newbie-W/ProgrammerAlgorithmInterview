/*单链表数据结构*/
typedef struct LNode {
	ElemType data;			//数据域，假设ElemType为int
	struct LNode *next;		//指针域
}LNode, *LinkList;