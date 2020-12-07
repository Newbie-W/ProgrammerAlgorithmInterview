/*
LRU是Least Recently Used的缩写，即“最近最少使用”，LRU缓存就是使用这种原理实现的，简单地说就是缓存一定量的数据，当超过设定的阈值时就把一些过期的数据删掉。常用于页面置换算法，是虚拟页式存储管理中常用的算法。如何实现LRU缓存方案？

思路步骤：
可以使用两个数据结构实现一个LRU缓存
（1）使用双向链表实现的队列，队列的最大容量为缓存的大小。在使用过程中，把最近使用的页面移动到队列头，最近没有使用的页面被放在队列尾的位置。
（2）使用一个哈希表，把页号作为键，把缓存在队列中的结点的地址作为值。
当引用一个页面时，所需的【页面在内存】中，需要把这个页对应的结点移动到队列的前面。如果所需的【页面不在内存】中，将它存储在内存中。

简单来说，就是将一个新结点添加到队列的前面，并在哈希表中更新相应的结点地址。如果队列是满的，那么就从队列尾部移除一个结点，并将新结点添加到队列的前面。
*/
#include <stdio.h>
#inlcude <stdlib.h>

// 用实现队列的双向链表的结点
typedef struct Node 
{
	unsigned pageNum;		// 存储页号
	struct Node *prev, *next;
} Node;

// 队列
typedef struct Queue
{
	unsigned count;			// 当前使用的大小
	unsigned cacheSize;		// 队列的大小
	Node *front, *rear;		// 队首和队尾
} Queue;

// 哈希表
typedef struct Hash
{
	int hashSize;		// 哈希表的大小
	Node* *array;		// 存储结点的地址
} Hash;

// 创建一个队列的结点
Node* newNode(unsigned pageNum)
{
	Node* newNode = (Node *)malloc(sizeof(Node));
	newNode->pageNum = pageNum;
	newNode->prev = newNode->next = NULL;
	return newNode;
}

// 创建一个大小为cacheSize的队列
Queue* createQueue(int cacheSize)
{
	Queue* queue = (Queue *)malloc(sizeof(Queue));
	queue->count = 0;					// 队列为空
	queue->front = queue->rear = NULL;
	queue->cacheSize = cacheSize;		// 队列大小
	return queue;
}

// 创建大小为hashSize的哈希表
Hash* createHash(int hashSize)
{
	Hash* hash = (Hash*)malloc(sizeof(Hash));
	hash->hashSize = hashSize;
	
	// 创建存储结点地址的数组
	hash->array = (Node **)malloc(hash->hashSize * sizeof(Node*));
	
	int i;
	for (i = 0; i < hash->hashSize; ++i)
	{
		hash->array[i] = NULL;
	}
	
	return hash;
}

// 判断缓存队列是否已满
int isQueueFull(Queue* queue)
{
	return queue->count == queue->cacheSize;
}

// 判断队列是否为空
int isQueueEmpty(Queue* queue)
{
	return queue->rear == NULL;
}

// 从队列里删除一个页的缓存（结点）
void deQueue(Queue* queue)
{
	if (isQueueEmpty(queue))
	{
		return;
	}
	
	// 队列中只有一个结点，删除后队列为空
	if (queue->front == queue->rear)
	{
		queue->front = NULL;
	}
	
	// 删除队尾的结点
	Node* temp = queue->rear;
	queue->rear = queue->rear->prev;
	
	if (queue->rear)
	{
		queue->rear->next = NULL;
	}
	
	free(temp);
	queue->count--;
}

// 把页号为pageNum的页也缓存到队列中，同时也添加到Hash表中
void enQueue(Queue* queue, Hash* hash, unsigned pageNum)
{
	// 如果队列满了，那么需要删除队尾的缓存的页
	if (isQueueFull(queue))
	{
		hash->array[queue->rear->pageNum] = NULL;
		deQueue(queue);
	}
	
	// 创建新的结点并添加到队首
	Node* temp = newNode(pageNum);
	temp->next = queue->front;
	
	// 对于队列为空的情况需要单独处理
	if (isQueueEmpty(queue))
	{
		queue->rear = queue->front = temp;
	}
	else
	{
		queue->front->prev = temp;
		queue->front = temp;
	}
	
	// 把新缓存的结点同时添加到hash表中
	hash->array[pageNum] = temp;
	queue->count++;
}
	
	
/*
当访问某一个page的时候会调用这个函数，对于访问的page有两种情况：
1. 如果page在缓存队列中，那么直接把这个结点移动到队首
2. 如果page不在缓存队列中，那么把这个page缓存到队首
*/
void accessPage(Queue* queue, Hash* hash, unsigned pageNum)
{
	Node* reqPage = hash->array[pageNum];
	
	// page不在缓存队列中，把它缓存到队首
	if (reqPage == NULL)
	{
		enQueue(queue, hash, pageNum);
	}
	
	// page已经在缓存队列中，移动到队首
	else if (reqPage != queue->front)
	{
		reqPage->prev->next = reqPage->next;
		if (reqPage->next)
		{
			reqPage->next->prev = reqPage->prev;
		}
		
		// 对于被访问的page被缓存在队列尾的情况 需要特殊处理
		if (reqPage == queue->rear)
		{
			queue->rear = reqPage->prev;
			queue->rear->next = NULL;
		}
		
		// 把访问的缓存结点放在队首
		reqPage->next = queue->front;
		reqPage->prev = NULL;
		
		// 队列第一个结点变为当前访问的page的缓存结点
		reqPage->next->prev = reqPage;
		queue->front = reqPage;
	}
}