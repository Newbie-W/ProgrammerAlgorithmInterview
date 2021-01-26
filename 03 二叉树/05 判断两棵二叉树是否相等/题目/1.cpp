/*
两棵二叉树相等，是指这两棵二叉树有着相同的结构，并且在相同位置上的结点有相同的值。如何判断两棵二叉树是否相等？
思路步骤：
两棵二叉树相等，则对应根结点的值、对应结构同，其子树也相等。因此使用递归便可以实现。

时间复杂度 O(N)（对两棵树进行了遍历）
空间复杂度 O(1)（没有申请额外的存储空间）
*/

#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0

struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
};

typedef struct BiTNode* PTNode;
typedef int bool;

/*
函数功能：判断两棵二叉树是否相等
输入参数：
	root1和root2分别两棵二叉树的根结点
*/
bool isEqual(PTNode root1, PTNode root2) {
	if (root1 == NULL && root2 == NULL) {
		return true;
	}
	if (root1 == NULL || root2 == NULL) {
		return false;
	}
	return root1->data == root2->data && isEqual(root1->lchild, root2->lchild) && isEqual(root1->rchild, root2->rchild);
}