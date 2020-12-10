/*
层序遍历，按层的顺序，从上至下，从左至右，逐层打印出二叉树的结点数据

思路步骤：
为了实现对二叉树的层序遍历，就要求在遍历一个结点的同时记录下来其孩子结点的信息，然后按照这个记录的顺序来访问结点的数据，在实现的时候可以采用队列来存储当前遍历到的结点的孩子结点，从而实现二叉树的层序遍历。
（简言之，使用队列，每次一个结点出队列，存储（入队列）该结点对应的左右孩子结点，并按序依次访问。）

时间复杂度 O(N)（在二叉树的层序遍历过程中，对树中的各个结点只进行了一次访问）
空间复杂度 O(N)（使用了队列保存遍历的中间结点，所使用队列的大小取决于二叉树中每一层中结点个数的最大值。具有N个结点的完全二叉树的深度为 h = log_2 N + 1，而深度为h的这一层最多的结点个数为2h-1=N/2。也就是说队列中可能的最多的结点个数为N/2）
*/

/*
函数功能：用层序遍历的方式打印出二叉树的结点的内容
输入参数：
	root：二叉树根结点
*/
void printTreeLayer(struct BiTNode *root) {
	if (root == NULL) {
		return ;
	}
	BiTNode* p;
	queue<BiTNode *> queue;
	// 树根结点进队列
	queue.push(root);
	while (!queue.empty()) {
		p = queue.front();
		queue.pop();
		// 访问当前结点
		cout<<p->data<<" ";
		// 如果这个结点的左孩子不为空则入队列
		if (p->lchild != NULL) {
			queue.push(p->lchild);
		}
		// 如果这个结点的右孩子不为空则入队列
		if (p->rchild != NULL) {
			queue.push(p->rchild);
		}
	}
}