### 情境：

> - 给定一棵二叉树，它的每个结点都是正整数或负整数，如何找到一棵子树，使得它所有结点的和最大？<br>
> - 实现findMaxSubTree()函数。

```C++
#include <stdlib.h>
#include <stdio.h>

struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode;

typedef struct BiTNode* PTNode;

/*
函数功能：求最大子树和
输入参数：
	root：根结点
	maxSum：最大子树结点的和
	maxRoot：指向最大子树的根结点的指针
返回值：以root为根结点子树所有结点的和
*/
int findMaxSubTree(PTNode root, int* maxSum, PTNode* maxRoot) {
	// 实现内容
}

/*
函数功能：构造二叉树
返回值：返回新构造的二叉树的根结点
*/
struct BiTNode* constructTree() {
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
	struct BiTNode * root = constructTree();
	int maxInt = (unsigned)(-1) >> 1;
	int minInt = maxInt + 1;
	// 子树和的初始化为最小值
	int *sum = &minInt;
	struct BiTNode *maxRoot;		// 最大子树的根结点
	int max = findMaxSubTree(root, sum, &maxRoot);
	printf("最大子树和为：%d\n", *sum);
	printf("对应子树的根结点为：%d\n", maxRoot->data);
	freeTree(root);
	return 0;
}
```


### 方法
**分析**<br>
要求一个二叉树的最大子树和，最容易想到的办法就是**针对每棵子树求出这棵子树所有结点的和，然后从中找最大值**。而通过**二叉树的后序遍历**恰好可以做到这一点。在对二叉树进行后序遍历的过程中，如果当前遍历的结点的值与其左右子树和的值相加，结果>最大值，则更新最大值。<br>
