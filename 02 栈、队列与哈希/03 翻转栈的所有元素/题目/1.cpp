/*
翻转（也叫颠倒）栈的所有元素，例如输入栈{1, 2, 3, 4, 5}，其中，1处在栈顶，翻转之后的栈为{5, 4, 3, 2, 1}，其中，5在栈顶。
思路：两层递归的嵌套，
第一层递归，分两步，（1）栈底元素移动到栈顶；（2）递归调用除栈顶元素的子栈
其中第（1）步，又可实现为递归

时间复杂度：把栈底元素移动到栈顶操作的时间复杂度为O(N)，在翻转操作中对每个子栈都进行了把栈底元素移动到栈顶的操作，因此翻转算法时间复杂度为O(N^2)
*/

/*
函数功能：把栈底元素移动到栈顶
输入参数：
	s:栈的引用
*/ 
void move_bottom_to_top(stack<int>& s) {
	if (s.empty()) {
		return;
	}
	int top1 = s.top();
	s.pop();	// 弹出栈顶元素
	if (!s.empty()) {
		// 递归处理不包含栈顶元素的子栈
		move_bottom_to_top(s);
		int top2 = s.top();
		s.pop();
		// 交换栈顶元素与子栈栈顶元素
		s.push(top1);
		s.push(top2);
	}
	else {
		s.push(top1);
	}
}

void reverse_stack(stack<int>& s) {
	if (s.empty()) {
		return ;
	}
	// 把栈底元素移动到栈顶
	move_bottom_to_top(s);
	int top = s.top();
	s.pop();
	// 递归处理子栈
	reverse_stack(s);
	s.push(top);
}