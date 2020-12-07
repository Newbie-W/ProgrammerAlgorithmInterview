/*
输入两个整数序列，其中一个序列表示栈的push（入栈）顺序，判断另一个序列有没有可能为对应的pop（出栈）顺序。
思路步骤：
先按入栈顺序入栈，每次入栈后判断栈顶元素与出栈顺序的元素是否相同。如果栈顶元素==出栈顺序元素，则出栈；若不等于，则继续入栈

时间复杂度 O(N)（）
空间复杂度 O(N)（）
*/

bool isPopSerial(const char* push, const char* pop) {
	if (push == NULL || pop == NULL) {
		return false;
	}
	int pushLen = strlen(push);
	int popLen = strlen(pop);
	if (pushLen != popLen) {
		return false;
	}
	int pushIndex = 0;
	int popIndex = 0;
	stack<char> stack;
	while (pushIndex < pushLen) {
		// 把push序列依次入栈，直到栈顶元素等于pop序列的第一个元素
		stack.push(push[pushIndex]);
		pushIndex++;
		// 栈顶元素出栈，pop序列移动到下一个元素
		while (!stack.empty() && stack.top() == pop[popIndex]) {
			stack.pop();
			popIndex++;
		}
	}
	
	// 栈为空，且pop序列中元素都被遍历过
	if (stack.empty() && popIndex == popLen) {
		return true;
	}
	return false;
}