### 情境：

> - 请设计一个排队系统，能够让每个进入队伍的用户都能看到自己在队列中所处的位置和变化，队伍可能随时有人可能加入或退出；当有人退出影响到用户的位置排名时，需要及时反馈到用户，用C/C++实现。<br>
> - 实现MyQueue类中的函数。
> - 本题用C++实现此队列，（也可用C语言实现）。

```C++
#include <iostream>
#include <list>
#include <string>
using namespace std;

class User {
private:
	int id;
	string name;
	int seq;
public:
	User(int id, string name, int seq = 0) {
		this->id = id;
		this->name = name;
		this->seq = 0;		// =seq?
	}
	
	string getName() {
		return name;
	}
	
	void setName(string name) {
		this->name = name;
	}
	
	int getSeq() {
		return seq;
	}
	
	void setSeq(int seq) {
		this->seq = seq;
	}
	
	int getId() {
		return id;
	}
	
	bool operator==(const User &u1)const {
		return (id == u1.id);
	}
};

class MyQueue {
private:
	list<User> userList;
public:
	// 进入队列尾部
	void enQueue(User u) {
		// 实现内容
	}
	
	// 队头出队列
	void deQueue() {
		// 实现内容
	}
	
	// 队列中的人随机离开
	void deQueue(User& u) {
		// 实现内容
	}
	
	// 出队列后更新队列中每个人的序列
	void updateSeq() {
		// 实现内容
	}
	
	// 打印队列的信息
	void printList() {
		// 实现内容
	}
};

int main() {
	User u1(1, "user1");
	User u2(2, "user2");
	User u3(3, "user3");
	User u4(4, "user4");
	MyQueue queue;
	queue.enQueue(u1);
	queue.enQueue(u2);
	queue.enQueue(u3);
	queue.enQueue(u4);
	queue.deQueue();		// 队首元素u1出队列
	queue.deQueue(u3);
	queue.printList();
	return 0;
}
```


### 方法
使用列表实现队列。入队列时，直接加入列表；而出队列时，如果指定了用户，那么就需要更新列表的用户序号。<br>
