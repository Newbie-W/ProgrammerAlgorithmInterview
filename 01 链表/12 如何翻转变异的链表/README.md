### 情境：

> - 有一个链表，其中每个对象包含两个指针p1和p2。指针p1指向下一个对象，指针p2也指向一个对象，沿p1可以像普通链表一样完成顺序遍历，沿p2则可能会有重复。一种可能的例子如下。其中实线箭头是p1，虚线箭头是p2。使用C/C++语言实现。<br>
> ![img1.12.1 图](https://github.com/Newbie-W/ProgrammerAlgorithmInterview/blob/master/pics/1.12/img%201.12.1.png)<br>
> 问题：设计一个函数，翻转这个链表，并返回头指针。链表结点的数据结构如下：<br>
> ``` C++
> struct Node {
> 	Node* p1;
> 	Node* p2;
> 	int data;
> };
> ```
> - 函数定义如下：<br>
> ``` C++
> Node* revert(Node* head);
> ```
> - 实现revert()函数，可在原来基础上添更多函数。<br>

```C++
#include <iostream>
#include <map>
using namespace std;

Node* revert(Node* head);
/*更多函数及实现等可添至此处*/

struct Node {
	int data;
	Node* p1;
	Node* p2;
	Node(int d):data(d), p1(NULL), p2(NULL){}
};
```

### 方法
由于链表可以通过指针p1来完成顺序遍历，因此可以：<br>
（1）先对指针p1进行逆序，在逆序的过程中，把指针p2的关系记录下来（可以用map来记录，key为当前遍历的结点p，值为p->p2），<br>
（2）当完成指针p1的逆序后，可以通过遍历map来对指针p2进行逆序。<br>