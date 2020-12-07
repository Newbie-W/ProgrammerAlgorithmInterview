### 情境：

> - 用两个栈模拟队列操作。<br>
> - 实现MyStack类中的函数。
> - 为简化代码，重点放在算法自身逻辑上，故使用C++实现，可用C++类库提供的栈。

```C++
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
		// 实现内容
	}
	
	T pop() {
		// 实现内容
	}
};

int main() {
	MyStack<int> stack;
	stack.push(1);
	stack.push(2)'
	cout<<"队列首元素为："<<stack.pop()<<endl;
	cout<<"队列首元素为："<<stack.pop()<<endl;
	return 0;
}
```


### 方法
假设使用栈A和栈B模拟队列Q，A为插入栈，B为弹出栈，以实现队列Q。<br>
再假设A和B都为空，可以认为栈A提供入队列功能，栈B提供出队列功能。<br>
1. 要**入队列**，入栈A即可
2. 而**出队列**，要分两种情况：
（1）如果栈B不为空，则直接弹出栈B的数据<br>
（2）如果栈B为空，则依次弹出栈A的数据，放入栈B中，再弹出栈B的数据。<br>
（**简言之，实现入队列操作时，直接入栈存，但出栈时，先将栈中的元素全部出栈，放入新栈，再从新栈出栈。**）<br>
