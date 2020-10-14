/*
法三：递归输出
时间复杂度：O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

/*
函数功能：从尾到头输出单链表信息
输入参数：
	head：指向链表第一个结点
*/
void reversePrint(LinkList firstNode) {
	if (firstNode == Node)
		return ;
	reversePrint(firstNode->next);
	printf("%d ", firstNode->data);
}

int main() {
	int i = 1;
	//链表头指针
	LinkList head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	LinkList tmp = NULL;
	LinkList cur = head;
	for (; i<8; i++) {
		tmp = (LinkList)malloc(sizeof(LNode));
		tmp->data = i;
		tmp->next = NULL;
		cur->next = tmp;
		cur = tmp;
	}
	printf("顺序输出：");
	for (cur=head->next; cur!=NULL; cur=cur->next) {
		printf("%d ", cur->data);
	}
	printf("\n逆序输出：");
	reversePrint(head->next);
	for (cur=head->next; cur!=NULL; ) {
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	return 0;
}