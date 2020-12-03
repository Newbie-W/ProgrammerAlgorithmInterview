/*
实现一个队列的数据结构， 使其具有【入队列】、【出队列】、【查看队列首尾元素】以及【查看队列大小】等功能。
法一：数组实现
1. front记录队首元素， rear记录队尾元素的下一位置
2.
进栈：将元素放到Arr[rear++]
出栈：front++
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define TRUE 1
#define FALSE 0

typedef int T;
typedef int Status;
// typedef int bool;

typedef struct MyQueue {
	T arr[MAXSIZE];
	int front;		// 队列头
	int rear;		// 队列尾
} MyQueue;

// 初始化队列
void initQueue(MyQueue *q) {
	q->front = 0;
	q->rear = 0;
}

// 判断队列是否为空
bool isEmpty(MyQueue *q) {
	return q->front == q->rear;
}

// 返回队列大小
int size(MyQueue *q) {
	return q->rear - q->front;
}

// 返回队列首元素
Status getFront(MyQueue *q, T* e) {
	if (isEmpty(q)) {
		return FALSE;
	}
	*e = q->arr[q->front];
	return TRUE;
}

// 返回队列尾元素
T getBack(MyQueue *q, T* e) {
	if (isEmpty(q)) {
		return FALSE;
	}
	*e = q->arr[q->rear-1];
	return TRUE;
}

// （出队列）删除队列头元素
void deQueue(MyQueue *q) {
	if (q->rear > q->front) {
		q->front++;
	}
	else {
		printf("队列已经为空\n");
	}
}

// （入队列）把新元素加入到队列尾
void enQueue(MyQueue *q, T item) {
	if (q->rear > MAXSIZE-1) {
		printf("队列已满\n");
		return ; // 书中未提，但感觉此处需要加此句；此外，把if判断的“>=”改为了“>”；
	}
	q->arr[q->rear++] = item;
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