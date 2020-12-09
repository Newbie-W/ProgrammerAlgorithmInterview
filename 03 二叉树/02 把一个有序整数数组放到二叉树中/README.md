### 情境：

> - 把一个有序整数数组放到二叉树中。<br>
> - 实现array2tree()函数。

```C++
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
	// 实现内容
}

/*
函数功能：用中序遍历的方式打印出二叉树结点的内容
输入参数：
	root：二叉树根结点
*/
void printTreeMidOrder(struct BiTNode *root) {
	if (root == NULL) {
		return ;
	}
	// 遍历root结点的左子树
	if (root->lchild) {
		printTreeMidOrder(root->lchild);
	}
	// 遍历root结点
	printf("%d ", root->data);
	// 遍历root结点的右子树
	if (root->rchild) {
		printTreeMidOrder(root->rchild);
	}
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
	int i;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("数组： ");
	for (i=0; i<sizeof(arr)/sizeof(arr[0]); i++) 
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	struct BiTNode *root;
	root = array2tree(arr, sizeof(arr)/sizeof(arr[0]));
	printf("转换成树的中序遍历为：");
	printTreeMidOrder(root);
	printf("\n");
	freeTree(root);
	return 0;
}
```


### 方法
如果要把一个有序的整数数组放到二叉树中，那么所构造的二叉树必定也是一棵有序的二叉树。鉴于此，**实现思路**：取数组的中间元素作为根结点，将数组分成左右两部分，对数组的两部分用递归的方法分别构建左右子树。<br>
