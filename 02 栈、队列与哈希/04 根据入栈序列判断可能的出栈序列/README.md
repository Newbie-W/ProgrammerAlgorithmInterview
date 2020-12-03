### 情境：

> - 输入两个整数序列，其中一个序列表示栈的push（入栈）顺序，判断另一个序列有没有可能为对应的pop（出栈）顺序。<br>
> - 实现isPopSerial()函数，可在原来基础上添更多函数。
> - 为简化代码，重点放在栈翻转的逻辑上，故使用C++实现，可用C++类库提供的栈。

```C++
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isPopSerial(const char* push, const char* pop);

int main() {
	char push[] = "12345";
	char pop[] = "32541";
	if (isPopSerial(push, pop)) {
		cout<<pop<<"是"<<push<<"的一个pop序列"<<endl;
	}
	else {
		cout<<pop<<"不是"<<push<<"的一个pop序列"<<endl;
	}
	return 0;
}
```


### 方法
主要思路：使用一个栈来模拟入栈顺序，具体步骤如下：<br>
（1）把push序列依次入栈，知道栈顶元素等于pop序列的第一个元素，然后栈顶元素出栈，pop序列移动到第二个元素。<br>
（2）如果栈顶元素仍然等于pop序列现在的元素，那么继续出栈并pop后移；否则对push序列继续入栈<br>
（3）如果push序列已经全部入栈，但pop序列未全部遍历，而且栈顶元素不等于当前pop元素，那么这个序列不是一个可能的出栈序列。如果栈为空，而且pop序列也全部被遍历过，则说明此为一个可能的pop序列。<br>
如下图2.4.1所示，为一个合理pop序列的判断过程。<br>
![img2.4.1 图](https://github.com/Newbie-W/ProgrammerAlgorithmInterview/blob/master/pics/2.04/img%202.4.1.PNG)<br>
