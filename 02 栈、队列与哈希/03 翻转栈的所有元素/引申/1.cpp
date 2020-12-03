/*
主要思路是：首先对不包含栈顶元素的子栈进行排序，如果栈顶元素大于子栈的栈顶元素，则交换这两个元素。因此在原题目（栈翻转）实现的方法中，只需要在交换栈顶元素与子栈顶元素的时候增加一个条件判断即可

时间复杂度 O(N^2)
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
		if (top1 > top2) {
			s.pop();
			// 交换栈顶元素与子栈栈顶元素
			s.push(top1);
			s.push(top2);
			return ;
		}
		
	}
	s.push(top1);
}

void sort_stack(stack<int>& s) {
	if (s.empty()) {
		return ;
	}
	// 把栈底元素移动到栈顶
	move_bottom_to_top(s);
	int top = s.top();
	s.pop();
	// 递归处理子栈
	sort_stack(s);
	s.push(top);
}

int main() {
	stack<int> s;
	s.push(1);
	s.push(3);
	s.push(2);
	sort_back(s);
	cout<<"排序后出栈顺序为：";
	while (!s.empty()) {
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}