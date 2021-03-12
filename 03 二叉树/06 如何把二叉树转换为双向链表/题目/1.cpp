/*
输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整指针的指向。
思路步骤：
（待再看，然后再总结）

时间复杂度 O(N)（同二叉树中序遍历的复杂度）
空间复杂度 O(1)（只用了两个额外的指针变量，记录双向链表的首尾结点）
*/

#include <stdlib.h>
#include <stdio.h>

//#define true 1
//#define false 0

struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode;

typedef struct BiTNode* PTNode;

PTNode pHead = NULL;	// 双向链表头结点
PTNode pEnd = NULL;		// 双向链表尾结点

/*
函数功能：把二叉树转换为双向链表
输入参数：
	root：二叉树根结点
*/
void inOrderBSTree(PTNode root) {
	// 实现内容
	if (root == NULL) {
		return ;
	}
	// 转换root的左子树
	inOrderBSTree(root->lchild);
	
	root->lchild = pEnd;	// 使当前结点的左指针指向双向链表中最后一个结点
	if (pEnd == NULL) {		// 双向链表为空，当前遍历的结点为双向链表的头结点
		pHead = root;
	}
	else {					// 使双向链表中最后一个结点的右指针指向当前结点
		pEnd->rchild = root;
	}
	pEnd = root;			// 将当前结点设为双向链表中最后一个结点
	
	// 转换root的右子树
	inOrderBSTree(root->rchild);
}