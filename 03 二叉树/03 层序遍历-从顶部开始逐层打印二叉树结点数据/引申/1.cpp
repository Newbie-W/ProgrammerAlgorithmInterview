/*
用空间复杂度为O(1)的算法来实现层序遍历

对于本题而言，主要的算法思路是：不使用队列来存储每一层遍历到的结点，而是每次都会从根结点开始遍历。把遍历二叉树的第k层的结点，转换为遍历二叉树根结点的左右子树的第k-1层结点。
通过本算法，可以首先求解出二叉树的高度h，然后调用下面的函数h次，即可打印出每一层的结点。


时间复杂度 O(N)
空间复杂度 O(1)
*/

int printAtLayer(struct BiTNode *root, int level) {
	if (!root || level < 0) {
		return 0;
	}
	else if (level == 0) {
		printf("%d\n", root->data);
		return 1;
	}
	else {
		// 把打印根结点level层的结点转换为求解根结点的孩子结点的level-1层的结点
		return printAtLayer(root->lchild, level - 1) + printAtLayer(root->rchild, level - 1);
	}
}