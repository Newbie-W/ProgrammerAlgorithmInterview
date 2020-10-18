/*
有一个链表，其中每个对象包含两个指针p1和p2。指针p1指向下一个对象，指针p2也指向一个对象，沿p1可以像普通链表一样完成顺序遍历，沿p2则可能会有重复。（具体图见本目录下README.md）。使用C/C++语言实现。
问题：设计一个函数，翻转这个链表，并返回头指针。链表结点的数据结构如下：
struct Node {
	Node* p1;
	Node* p2;
	int data;
};

函数定义如下：
Node* revert(Node* head);


思路步骤：
由于链表可以通过指针p1来完成顺序遍历，因此可以：
（1）先对指针p1进行逆序，在逆序的过程中，把指针p2的关系记录下来（可以用map来记录，key为当前遍历的结点p，值为p->p2），
（2）当完成指针p1的逆序后，可以通过遍历map来对指针p2进行逆序。

时间复杂度 O(N)
空间复杂度 O(N)
*/

Node* revert(Node* head) {
	map<Node*, Node*> p2Relation;
	Node* pReversedHead = NULL;
	Node* pNode = pHead;
	Node* pPrev = NULL;
	// 翻转p1
	while (pNode != NULL) {
		Node* pNext = pNode->p1;	// 取出当前结点（沿p1）的下一结点
		if (pNext == NULL) {
			pReversedHead = pNode;
		}
		p2Relation.insert(pair<Node*, Node*>(pNode, pNode->p2));
		pNode->p1 = pPrev;			// 当前结点指向其前一结点
		pPrev = pNode;
		pNode = pNext;
	}
	
	// 翻转p2
	map<Node*, Node*>::iterator it;
	for (it=p2Relation.begin(); it!=p2Relation.end(); ++it) {
		it->second->p2 = it->first;	
	}
	return pReversedHead;
}