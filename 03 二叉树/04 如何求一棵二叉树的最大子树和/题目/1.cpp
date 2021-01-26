/*
给定一棵二叉树，它的每个结点都是正整数或负整数，如何找到一棵子树，使得它所有结点的和最大？
思路步骤：
要求一个二叉树的最大子树和，最容易想到的办法就是针对每棵子树求出这棵子树所有结点的和，然后从中找最大值。而通过二叉树的后序遍历恰好可以做到这一点。在对二叉树进行后序遍历的过程中，如果当前遍历的结点的值与其左右子树和的值相加，结果>最大值，则更新最大值。

时间复杂度 O(N)（与二叉树的后序遍历有相同的复杂度， N为二叉树的结点个数）
*/

#include <stdlib.h>
#include <stdio.h>

struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
};

/*
函数功能：求最大子树和
输入参数：
	root：根结点
	maxSum：最大子树结点的和
	maxRoot：指向最大子树的根结点的指针
返回值：以root为根结点子树所有结点的和
*/
int findMaxSubTree(PTNode root, int* maxSum, PTNode* maxRoot) {
	if (root == NULL) {
		return 0;
	}
	// 求root左子树所有结点的和
	int lmax = findMaxSubTree(root->lchild, maxSum, maxRoot);
	// 求root右子树所有结点的和
	int rmax = findMaxSubTree(root->rchild, maxSum, maxRoot);
	int sum = lmax + rmax + root->data;
	// 以root为根的子树的和大于前面求出的最大值
	if (sum > *maxSum) {
		*maxSum = sum;
		*maxRoot = root;
	}
	// 返回以root为根结点的子树的所有结点的和
	return sum;
}