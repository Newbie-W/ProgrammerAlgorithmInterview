/*树结点数据结构*/
typedef struct BiTNode {
	ElemType data;		// 数据域，本章算法假设ElemType为int
	struct BiTNode *lchild, *rchild;		// 左右孩子指针
};