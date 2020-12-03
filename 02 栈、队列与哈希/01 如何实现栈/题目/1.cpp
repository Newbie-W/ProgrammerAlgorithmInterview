/*
实现一个栈的数据结构，使其具有以下方法：压栈、弹栈、取栈顶元素、判断栈是否为空以及获取栈中元素个数。
法一：数组实现
1. 数组首地址作为栈底，同时记录栈中元素长度size
2. 则可推得栈顶
（注意栈顶和栈底在栈中的位置（如，是否指向元素））
3.
进栈：将元素放到Arr[size]， 然后size++
出栈：取出Arr[size-1]的元素（栈顶元素），然后执行size--操作
*/

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Status;
// typedef int bool;

typedef struct MyStack {
	ElemType* base;
	int stackSize;		// 数组中存储元素的个数
	int len;			// 数组的总长度
} MyStack;

// 初始化栈
MyStack* initStack(MyStack *s) {
	s = (MyStack *)malloc(sizeof(MyStack));
	s->len = STACK_INIT_SIZE;	// 数组初始化长度
	s->stackSize = 0;			// 初始化初始栈大小
	if (!s) {
		printf("初始化失败\n");
	}
	s->base = (ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if (!s->base) {
		printf("初始化失败\n");
	}
	return s;
}

// 释放栈占用的空间
Status freeStack(MyStack *s) {
	if (s->base != NULL) {
		free(s->base);
	}
	free(s);
}

// 判断栈是否为空
bool isEmpty(MyStack *s) {
	return s->stackSize == 0;
}

// 返回栈的大小
int size(MyStack* s) {
	return s->stackSize;
}

// 返回栈顶元素
Status top(MyStack *s, ElemType* elem) {
	if (isEmpty(s)) {
		printf("栈已经为空\n");
		return 0;
	}
	*elem = s->base[s->stackSize - 1];
}

// 弹栈
Status pop(MyStack *s, ElemType* elem) {
	if (s->stackSize > 0) {
		*elem = s->base[--(s->stackSize)];
		return 1;
	}
	else {
		printf("栈已经为空\n")；
		return 0;
	}
}

// 判断数组器是否已满，如果已满，那么扩充数组空间
void ensureCapacity(MyStack *s) {
	if (s->stackSize >= s->len) {
		// 数组已满
		s->len += STACK_INCREMENT;
		s->base = (ElemType*)realloc(s->base, s->len);
	}
}

// 把item压入栈s中
void push(MyStack *s, ElemType item) {
	ensureCapacity(s);		// 检查容量
	s->base[(s->stackSize)++] = item;
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