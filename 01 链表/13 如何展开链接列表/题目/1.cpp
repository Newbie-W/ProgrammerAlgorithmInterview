/*
给定一个有序链表，其中每个结点也表示一个有序链表，结点包含两个类型的指针：
（1）指向主链表中下一个结点的指针（称为“正确”指针）
（2）指向此结点头的链表（称为“down”指针）
所有链表都被排序，（具体图见本目录下README.md）

实现一个函数flatten()，该函数用来将链表扁平化成单个链表，扁平化的链表也应该被排序。例如，对于上述输入链表，输出链表应为3->6->8->11->15->21->22->30->31->39->40->45->50

思路步骤：
由于链表可以通过指针p1来完成顺序遍历，因此可以：
（1）先对指针p1进行逆序，在逆序的过程中，把指针p2的关系记录下来（可以用map来记录，key为当前遍历的结点p，值为p->p2），
（2）当完成指针p1的逆序后，可以通过遍历map来对指针p2进行逆序。
（简单来说，就是设两个指针，分别往两个方向走）
*/

Node* merge(Node* a, Node* b) {
	// 如果有其中一个链表为空，直接返回另外一个链表
	if (!a) {
		return b;
	}
	if (!b) {
		return a;
	}
	
	// 把两个链表头中较小的结点赋值给result
	Node* result;
	if (a->data < b->data) {
		result = a;
		result->down = merge(a->down, b);
	} else {
		result = b;
		result->down = merge(a, b->down);
	}
	return result;
}

/*把链表扁平化处理*/
Node* flatten(Node* root) {
	if (!root || !root->right) {
		return root;
	}
	/*把root结点对应的链表与右边的链表合并*/
	return merge(root, flatten(root->right));
}