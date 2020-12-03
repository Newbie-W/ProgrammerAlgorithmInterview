/*
实现一个队列的数据结构， 使其具有【入队列】、【出队列】、【查看队列首尾元素】以及【查看队列大小】等功能
法二：链表实现
1. 分别用两个指针指向队列的首元素和尾元素。pHead指向队列首元素。pEnd指向队列尾元素
2. 
入队列：将队尾加入新结点，然后移动队列尾指针
出队列：队列首元素指针后移
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define TRUE 1
#define FALSE 0

typedef int T;
typedef int Status;
// typedef int bool;

typedef struct Node Node;
struct Node {
	T data;
	Node* next;
};

typedef struct MyQueue {
	Node* pHead;
	Node* pEnd;
} MyQueue;

// 初始化队列
void initQueue(MyQueue *q) {
	q->pEnd = q->pHead = NULL;
}

// 判断队列是否为空
bool isEmpty(MyQueue *q) {
	return q->pHead == NULL;
}

// 返回队列的大小
int size(MyQueue *q) {
	int size = 0;
	Node* p = q->pHead;
	while (p != NULL) {
		p = p->next;
		size++;
	}
	return size;
}

// 返回队列首元素
Status getFront(MyQueue *q, T* e) {
	if (!q->pHead) {
		printf("获取队列首元素失败。队列为空\n");
		return FALSE;
	}
	*e = q->pHead->data;
	return TRUE;
}

// 返回队列尾元素
T getBack(MyQueue *q, T* e) {
	if (!q->End) {
		printf("获取队列尾元素失败，队列为空\n");
		return FALSE;
	}
	*e = q->pEnd->data;
	return TRUE;
}

// （出队列）删除队列头元素
void deQueue(MyQueue *q) {
	if (!q->pHead) {
		printf("出队列失败，队列为空\n");
	}
	Node* tmp = q->pHead;
	q->pHead = q->pHead->next;
	if (!q->pHead) {		// 最后一个元素出队列，设置队尾指针也为空
		q->pEnd = NULL;
	}
	free(tmp);
}

// （入队列）新元素加入队列尾
Status enQueue(MyQueue *q, T e) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p) {
		printf("申请结点失败");
		return FALSE;
	}
	p->data = e;
	p->next = NULL;
	if (!q->pHead) {	// 新元素入空队列
		q->pHead = q->pEnd = p;
	}
	else {
		q->pEnd->next = p;
		q->pEnd = p;
	}
	return TRUE;
}

void destroyQueue(MyQueue *q) {
	Node* p = q->pHead;
	while (p) {
		Node* tmp = p;
		p = p->next;
		free(tmp);
	}
}

int main() {
	MyQueue queue;
	initQueue(&queue);
	enQueue(&queue, 1);
	enQueue(&queue, 2);
	int e;
	if (getFront(&queue, &e)) {
		printf("队列头元素为：%d\n", e);
	}
	if (getBack(&queue, &e)) {
		printf("队列尾元素为：%d\n", e)
	}
	printf("队列大小为：%d\n", size(&queue));
	return 0;
}