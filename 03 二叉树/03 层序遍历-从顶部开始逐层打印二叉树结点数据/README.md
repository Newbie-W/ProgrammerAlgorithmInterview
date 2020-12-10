### 情境：

> - 层序遍历，按层的顺序，从上至下，从左至右，逐层打印出二叉树的结点数据。
> - 实现printTreeLayer()函数，可在原来基础上添更多函数。
> - 为简化代码，重点放在算法自身逻辑上，故使用C++实现，可用C++类库提供的栈。

```C++
#include <iostream>
#include <queue>
using namespace std;

struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
};

void freeTree(struct BiTNode *root) {
	if (root == NULL) {
		return ;
	}
	freeTree(root->lchild);
	freeTree(root->rchild);
	freeTree(root);
}

/*
函数功能：用层序遍历的方式打印出二叉树的结点的内容
输入参数：
	root：二叉树根结点
*/
void printTreeLayer(struct BiTNode *root) {
	// 实现内容
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	struct BiTNode *root;
	root = array2tree(arr, sizeof(arr) / sizeof(arr[0]));		// 3.2节，实现有序数组转二叉树
	cout<<"树的层序遍历结果为：";
	printTreeLayer(root);
	ccout<<endl;
	freeTree(root);
	return 0;
}
```

### 方法
思路：<br>
为了实现对二叉树的层序遍历，就要求在遍历一个结点的同时记录下来其孩子结点的信息，然后按照这个记录的顺序来访问结点的数据，在实现的时候可以采用队列来存储当前遍历到的结点的孩子结点，从而实现二叉树的层序遍历。<br>
（**简言之**，使用队列，每次一个结点出队列，存储（入队列）该结点对应的左右孩子结点，并按序依次访问。）<br>

---
### 引申

> 用空间复杂度为O(1)的算法来实现层序遍历<br>
> 上面介绍的算法的空间复杂度为O(N)，不满足条件。通常情况下，提高空间复杂度都是要以牺牲时间复杂度作为代价的。对于本题而言，主要的**算法思路**是：不使用队列来存储每一层遍历到的结点，而是每次都会从根结点开始遍历。把遍历二叉树的第k层的结点，转换为遍历二叉树根结点的左右子树的第k-1层结点。<br>