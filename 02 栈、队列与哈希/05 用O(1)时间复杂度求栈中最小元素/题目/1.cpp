/*
输入两个整数序列，其中一个序列表示栈的push（入栈）顺序，判断另一个序列有没有可能为对应的pop（出栈）顺序。
思路步骤：
元素入栈时，如果比最小值栈的栈顶元素更小，就入最小值栈；出栈时，如果出栈的为最小值栈的栈顶元素，则出最小值栈

时间复杂度 O(1)
空间复杂度 O(N)（申请了一个栈空间来保存栈中的最小元素）
*/

class MyStack {
private:
	stack<int> elemStack;		// 用来存储栈中元素
	stack<int> minStack;		// 最小值栈，栈顶永远存储当前elemStack中最小的值
public:
	void push(int data) {
		elemStack.push(data);
		// 更新保存最小元素的栈
		if (minStack.empty()) {
			minStack.push(data);
		}
		else {
			if (data < minStack.top()) {
				minStack.push(data);
			}
		}
	}
	
	int pop() {
		int topData = elemStack.top();
		elemStack.pop();
		if (topData == min()) {
			minStack.pop();
		}
		return topData;
	}
	
	int min() {
		if (minStack.empty()) {
			return numeric_limits<int>::max();
		}
		else {
			return minStack.top();
		}
	}
};