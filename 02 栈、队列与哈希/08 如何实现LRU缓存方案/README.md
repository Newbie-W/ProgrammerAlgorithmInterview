### 情境：

> - LRU是Least Recently Used的缩写，即“最近最少使用”，LRU缓存就是使用这种原理实现的，简单地说就是缓存一定量的数据，当超过设定的阈值时就把一些过期的数据删掉。常用于页面置换算法，是虚拟页式存储管理中常用的算法。如何实现LRU缓存方案？<br>

```C++
#include <iostream>
#include <list>
#include <string>
using namespace std;

/* 添加需要的结构体、函数等 */

int main() {
	// 假设缓存大小为3
	Queue* q = createQueue(3);
	
	// 假设可以被访问的page为0~7
	Hash* hash = createHash(8);
	
	// 访问网页
	accessPage(q, hash, 1);
	accessPage(q, hash, 2);
	accessPage(q, hash, 5);
	accessPage(q, hash, 1);
	accessPage(q, hash, 6);
	accessPage(q, hash, 7);
	
	// 通过上面的访问序列后，缓存的信息
	printf("%d ", q->front->pageNum);
	printf("%d ", q->front->next->pageNum);
	printf("%d \n", q->front->next->next->pageNum);
	return 0;
}
```


### 方法
可以使用两个数据结构实现一个LRU缓存<br>
（1）使用双向链表实现的队列，队列的最大容量为缓存的大小。在使用过程中，把最近使用的页面移动到队列头，最近没有使用的页面被放在队列尾的位置。<br>
（2）使用一个哈希表，把页号作为键，把缓存在队列中的结点的地址作为值。<br>
当引用一个页面时，所需的**页面在内存**中，需要把这个页对应的结点移动到队列的前面。如果所需的**页面不在内存**中，将它存储在内存中。<br>
简单来说，**就是将一个新结点添加到队列的前面，并在哈希表中更新相应的结点地址。如果队列是满的，那么就从队列尾部移除一个结点，并将新结点添加到队列的前面**。<br>
