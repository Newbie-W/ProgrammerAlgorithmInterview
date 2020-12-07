### 情境：

> - 用O(1)时间复杂度求栈中最小元素。<br>
> - 实现MyStack类中的函数。
> - 为简化代码，重点放在算法自身逻辑上，故使用C++实现，可用C++类库提供的栈。

```C++
#include <iostream>
#include <stack>
#include <limits>
using namespace std;

class MyStack {
public:
	void push(int data) {
		// 实现内容
	}
	
	int pop() {
		// 实现内容
	}
	
	int min() {
		// 实现内容
	}
};

int main() {
	MyStack stack;
	stack.push(5);
	cout<<"栈中最小值为："<<stack.min()<<endl;
	stack.push(6);
	cout<<"栈中最小值为："<<stack.min()<<endl;
	stack.push(2);
	cout<<"栈中最小值为："<<stack.min()<<endl;
	stack.pop();
	cout<<"栈中最小值为："<<stack.min()<<endl;
	return 0;
}
```


### 方法
求栈中最小元素，通常为，使用一个变量记录栈底的位置，通过遍历栈中所有的元素，找出最小值；但这种方式，时间复杂度为O(N)。<br>
为了达到O(1)的时间复杂度，需要考虑空间换时间的方式，采用额外的存储空间来降低操作的时间复杂度。<br>

**主要思路**：使用两个栈，一个存数据，一个存储栈的最小值（下称最小值栈），具体步骤如下：（**简言之，元素入栈时，如果比最小值栈的栈顶元素更小，就入最小值栈；出栈时，如果出栈的为最小值栈的栈顶元素，则出最小值栈。**）<br>
如果当前入栈的元素比最小值栈中的元素还小，则把这个值压入保存最小元素的栈中；在出栈的时候，如果当前出栈的元素比栈中的最小值更小，则把这个值压入到最小值栈中，使得当前最小值变为当前最小值入栈前的那个最小值。为了简单起见，可在栈中保存int类型。<br>
