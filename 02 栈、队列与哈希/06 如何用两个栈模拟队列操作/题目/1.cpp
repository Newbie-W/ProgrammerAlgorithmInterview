/*
用两个栈模拟队列操作。
思路步骤：
实现入队列操作时，直接入栈存，但出栈时，先将栈中的元素全部出栈，放入新栈，再从新栈出栈。

时间复杂度 O(1)（算法入队列操作的时间复杂度为O(1)，出队列操作的时间复杂度，则依赖于入队列与出队列执行的频率。总体来讲，出队列操作的时间复杂度为O(1)，但会有个别操作需要耗费更多的时间（因为需要在两个栈之间移动数据））
*/

#include <iostream>
#include <stack>
#include <limits>
using namespace std;

template <class T>
class MyStack {
private:
	stack<T> A;
	stack<T> B;
public:
	void push(T data) {
		A.push(data);
	}
	
	T pop() {
		if (B.empty()) {
			while (!A.empty()) {
				B.push(A.top());
				A.pop();
			}
		}
		T first = B.top();
		B.pop();
		return first;
	}
};