/*
实现一个栈的数据结构，使其具有以下方法：压栈、弹栈、取栈顶元素、判断栈是否为空以及获取栈中元素个数。
法二：链表实现
直接在头结点后插入或删除元素即可
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Status;
// typedef int bool;

typedef struct Node Node;
struct Node {
	ElemType data;
	Node* next;
};

typedef Node MyStack;

// 初始化栈
MyStack* initStack(MyStack* s) {
	s = (Node *) malloc(sizeof(Node));
	if (!s) {
		printf("申请结点失败\n");
		return s;
	}
	s->next = NULL;
	return s;
}

// 释放栈占用的空间
Status freeStack(MyStack *s) {
	Node* p = s->next;
	while(p != NULL) {
		Node* tmp = p;
		p = p->next;
		free(tmp);
	}
}

// 判断栈是否为空
bool isEmpty(MyStack *s) {
	if (s->next == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

// 返回栈的大小
int size(MyStack *s) {
	int size = 0;
	Node* p = s->next;
	while (p != NULL) {
		p = p->next;
		size++;
	}
	return size;
}

// 返回栈顶元素
Status top(MyStack *s, ElemType* e) {
	if (s->next != NULL) {
		*e = s->next->data;
		return 1;
	}
	printf("栈已经为空\n");
	return 0;
}

// 弹栈
Status pop(MyStack* s, ElemType* e) {
	Node* tmp = s->next;
	if (tmp) {
		s->next = tmp->next;
		*e = tmp->data;
		free(tmp);
		return 1;
	}
	printf("栈已经为空\n");
	return 0;
}

// 把e压入栈s中
void push(MyStack *s, ElemType e) {
	Node* p = (Node *)malloc(sizeof(Node));
	if (p == NULL) {
		printf("申请结点失败\n");
		return;
	}
	p->data = e;
	p->next = s->next;
	s->next = p;
}

int main() {
	MyStack* s;
	int elem;
	s = initStack(s);
	push(s, 1);
	push(s, 2);
	if (top(s, &elem)) {
		printf("栈顶元素：%d\n", elem);
	}
	pop(s, &elem);
	if (top(s, &elem)) {
		printf("栈顶元素：%d\n", elem);
	}
	freeStack(s);
	return 0;
}