### 情境：

> - 两棵二叉树相等，是指这两棵二叉树有着相同的结构，并且在相同位置上的结点有相同的值。如何判断两棵二叉树是否相等？<br>
> - 实现isEqual()函数。

```C++
#include <stdlib.h>
#include <stdio.h>

// #define true 1
// #define false 0

struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode;

typedef struct BiTNode* PTNode;
//typedef int bool;

/*
函数功能：判断两棵二叉树是否相等
输入参数：
	root1和root2分别两棵二叉树的根结点
*/
bool isEqual(PTNode root1, PTNode root2) {
	// 实现内容
}

/*
函数功能：构造二叉树
返回值：返回新构造的二叉树的根结点
*/
PTNode constructTree() {		// 与前节构造的二叉树同
	struct BiTNode *root = (struct BiTNode*)malloc(sizeof(BiTNode));
	struct BiTNode *node1 = (struct BiTNode*)malloc(sizeof(BiTNode));
	struct BiTNode *node2 = (struct BiTNode*)malloc(sizeof(BiTNode));
	struct BiTNode *node3 = (struct BiTNode*)malloc(sizeof(BiTNode));
	struct BiTNode *node4 = (struct BiTNode*)malloc(sizeof(BiTNode));
	root->data = 6;
	node1->data = 3;
	node2->data = -7;
	node3->data = -1;
	node4->data = 9;
	root->lchild = node1;
	root->rchild = node2;
	node1->lchild = node3;
	node1->rchild = node4;
	node2->lchild = node2->rchild = node3->lchild = node3->rchild = node4->lchild = node4->rchild = NULL;
	return root;
}

/*
函数功能：释放二叉树结点所占的内存空间
输入参数：
	root：二叉树根结点
*/
void freeTree(struct BiTNode *root) {
	if (root == NULL) {
		return ;
	}
	freeTree(root->lchild);
	freeTree(root->rchild);
	freeTree(root);
}

int main() {
	PTNode root1 = constructTree();
	PTNode root2 = constructTree();
	bool equal = isEqual(root1, root2);
	if (equal)
		printf("两棵树相等\n");
	else
		printf("两棵树不相等\n");
	freeTree(root1);
	freeTree(root2);
	return 0;
}
```


### 方法
**分析**<br>
两棵二叉树相等，则对应根结点的值、对应结构同，其子树也相等。因此使用**递归**便可以实现。<br>