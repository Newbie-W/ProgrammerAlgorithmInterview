/*
输入两个整数序列，其中一个序列表示栈的push（入栈）顺序，判断另一个序列有没有可能为对应的pop（出栈）顺序。

思路步骤：
（1）
（2）
（3）

时间复杂度 O(N)（）
空间复杂度 O(N)（）
*/

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