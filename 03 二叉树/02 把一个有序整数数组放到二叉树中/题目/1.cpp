/*
把一个有序整数数组放到二叉树中。
思路步骤：
取数组的中间元素作为根结点，将数组分成左右两部分，对数组的两部分用递归的方法分别构建左右子树。

时间复杂度 O(N)（只遍历了一遍数组，其中N表示数组长度）
*/

#include <stdlib.h>
#include <stdio.h>

struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
};

/*
函数功能：把有序数组转换为二叉树
输入参数：
	a：数组头指针
	len：数组长度
返回值：转换后的树的根结点
*/
struct BiTNode array2tree(int *a, int len) {
	struct BiTNode* root = NULL;
	if (len > 0) {
		root = (struct BiTNode*)malloc(sizeof(struct BiTNode));
		// 树的根结点为数组中间的元素
		root->data = a[len / 2];
		// 递归地用左半部分数组构造root的左子树
		root->lchild = array2tree(a, len / 2);
		// 递归地用右半部分数组构造root的右子树
		root->rchild = array2tree(a + len / 2 + 1, len - len/2 - 1);
	} else {
		root = NULL;
	}
	return root;
}