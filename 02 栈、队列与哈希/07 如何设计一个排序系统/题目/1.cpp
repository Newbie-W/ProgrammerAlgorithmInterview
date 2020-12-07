/*
请设计一个排队系统，能够让每个进入队伍的用户都能看到自己在队列中所处的位置和变化，队伍可能随时有人可能加入或退出；当有人退出影响到用户的位置排名时，需要及时反馈到用户，用C/C++实现。
思路步骤：
使用列表实现队列。入队列时，直接加入列表；而出队列时，如果指定了用户，那么就需要更新列表的用户序号。
*/

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
		u.setSeq(userList.size() + 1);
		userList.push_back(u);
	}
	
	// 队头出队列
	void deQueue() {
		userList.pop_front();
		updateSeq();
	}
	
	// 队列中的人随机离开
	void deQueue(User& u) {
		userList.remove(u);
		updateSeq();
	}
	
	// 出队列后更新队列中每个人的序列
	void updateSeq() {
		int i = 1;
		list<User>::iterator iter;
		fot (iter = userList.begin(); iter != userList.end(); ++iter) {
			iter->setSeq(i);
			i++;
		}
	}
	
	// 打印队列的信息
	void printList() {
		list<User>::iterator iter;
		for (iter = userList.begin(); iter != userList.end(); ++iter) {
			cout<<"id:"<<iter->getId()<<" name:"<<iter->getName()<<" seq:"<<iter->getSeq()<<endl;
		}
	}
};