### 情境：

> - 给定一个有序链表，其中每个结点也表示一个有序链表，结点包含两个类型的指针：<br>
> （1）指向主链表中下一个结点的指针（称为“正确”指针）<br>
> （2）指向此结点头的链表（称为“down”指针）<br>
> 所有链表都被排序，如下图1.13.1<br>
> ![img1.13.1 图](https://github.com/Newbie-W/ProgrammerAlgorithmInterview/blob/master/pics/1.13/img%201.13.1.png)<br>
> 实现一个函数flatten()，该函数用来将链表扁平化成单个链表，扁平化的链表也应该被排序。例如，对于上述输入链表，输出链表应为3->6->8->11->15->21->22->30->31->39->40->45->50<br>

```C++
#include <iostream>
#include <map>
using namespace std;

Node* flatten(Node* root);
/*更多函数及实现等可添至此处*/

typedef struct Node {
	int data;
	struct Node *right;
	struct Node *down;
} Node;

/*把一个结点插入到链表头*/
void insert(Node** head_ref, int new_data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->right = NULL;
	
	new_node->data = new_data;
	
	// 把这个新建的结点插入到链表的头部
	new_node->down = (*head_ref);
	
	// 链表的头结点变为新创建的结点
	(*head_ref) = new_node;
}

/*打印扁平化处理后的链表*/
void printList(Node *node) {
	while (node) {
		printf("%d ", node->data);
		node = node->down;
	}
	print("\n");
}

void freeList(Node* node) {
	Node* tmp;
	while (node) {
		tmp = node;
		node = node->down;
		free(tmp);
	}
}

int main() {
	Node* root = NULL;
	// 构造题目所需链表
	insert( &root, 31 );
	insert( &root, 8 );
	insert( &root, 6 );
	insert( &root, 3 );
	
	insert( &(root->right), 21 );
	insert( &(root->right), 11 );
	
	insert( &(root->right->right), 50 );
	insert( &(root->right->right), 22 );
	insert( &(root->right->right), 15 );
	
	insert( &(root->right->right->right), 55 );
	insert( &(root->right->right->right), 40 );
	insert( &(root->right->right->right), 39 );
	insert( &(root->right->right->right), 30 );
	
	root = flatten(root);
	// 输出扁平化处理展开的链表
	printList(root);
	freeList(root);
	return 0;
}
```

### 方法
主要思路为，使用归并排序中的合并操作，使用归并的方法把这些链表来逐个归并。<br>
具体而言，可以使用递归的方法，递归地合并已经扁平化地链表和当前的链表。在实现过程中，可以使用down指针来存储扁平化处理后的链表。<br>
（简单来说，就是设两个指针，分别往两个方向走）<br>