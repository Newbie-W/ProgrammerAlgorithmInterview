### 情境：

输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整指针的指向。如图3.6.1<br>
> ![img3.6.1 图](https://github.com/Newbie-W/ProgrammerAlgorithmInterview/blob/master/pics/3.06/img%203.6.1.png)<br>
> - 实现inOrderBSTree()函数。

```C
#include <stdlib.h>
#include <stdio.h>

// #define true 1
// #define false 0

struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode;

typedef struct BiTNode* PTNode;

/*
函数功能：释放双向链表结点所占的空间
输入参数：
	head：链表头结点指针
*/
void freeList(PTNode head) {
	PTNode cur = head;
	PTNode tmp = NULL;
	while (cur != NULL) {
		tmp = cur;
		cur = cur->rchild;
		free(tmp);
	}
}

PTNode pHead = NULL;	// 双向链表头结点
PTNode pEnd = NULL;		// 双向链表尾结点

/*
函数功能：把二叉树转换为双向链表
输入参数：
	root：二叉树根结点
*/
void inOrderBSTree(PTNode root) {
	// 实现内容
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	PTNode root;
	root = array2tree(arr, sizeof(arr) / sizeof(arr[0]));		// 3.2节，实现有序数组转二叉树
	inOrderBSTree(root);
	PTNode cur;
	printf("转换后双向链表正向遍历：");
	for (cur=pHead; cur!=NULL; cur=cur->rchild) {
		printf("%d ", cur->data);
	}
	printf("\n");
	printf("转换后双向链表逆向遍历：");
	for (cur=pEnd; cur!=NULL; cur=cur->lchild) {
		printf("%d ", cur->data);
	}
	freeList(pHead);
	return 0;
}
```


### 方法
**分析**<br>
由于 转换后的双向链表中的结点的顺序 与 二叉树中序遍历的顺序 相同。因此可以对二叉树的**中序遍历算法进行修改**，通过**在中序遍历的过程中修改结点指针的指向**来转换成一个排序的双向链表。<br>
![img3.6.2 图](https://github.com/Newbie-W/ProgrammerAlgorithmInterview/blob/master/pics/3.06/img%203.6.2.png)<br>
**具体解释：**如图所示，当前遍历的结点为root，其左子树已转换为双向链表，并且用两个指针 pHead和pEnd 分别指向 链表的头结点 与 尾结点。<br>
在遍历root结点时，只需要将root结点的lchild指针域指向pEnd，把pEnd的rchild指针域指向root；此时，root结点就被加入到双向链表里了；<br>
然后root变成了双向链表的尾结点。<br>
对于所有结点都可通过同样的方法来修改指针的指向；因此，可采用**递归**方法求解，在求解时，需特别注意【递归的结束条件】和【边界情况（如双向链表为空）】。<br>