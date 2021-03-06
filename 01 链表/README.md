### 链表
-----
#### 一、
- 可分为有头结点的单链表和无头结点的单链表。
（单链表开始节点前一个类型相同的结点，称之为头结点）头结点的数据域可不存信息，或存线性表长度等。
- 头结点的作用（以下都说的是有头结点的链表）
	1. 插入、删除方面，链表中的各结点得到统一（因各结点均有前驱结点）。
	2. 链表是否空的方面，处理空链表与非空链表得到统一。（链表头指针指向头结点的非空指针）

#### 二、单链表的定义
（即Node.h）
```C++
typedef struct LNode {
	ElemType data;			//数据域，假设ElemType为int
	struct LNode *next;		//指针域
}LNode, *LinkList;
```
#### 三、常见笔试题
1. 如何实现链表的逆序
> **题目**：给定一个带头结点的单链表，将其逆序。（如head->1->2->...->7，逆序后为head->7->6...->1）<br>
> **引申**：<br>
> （1）对不带头结点的单链表进行逆序<br>
> （2）从尾到头输出链表
2. 如何从无序链表中移除重复项
> **题目**：给定一个没有排序的链表，去掉其重复项，并保留原顺序，例1->3->1->5->5->7，去掉重复项后变为1->3->5->7  
> **引申**：有序链表中移除重复项
3. 如何计算两个单链表所代表的数之和
> **题目**：给定两个单链表，链表的每个结点代表一位数，计算两个数的和。例如，链表（3->1->5）和链表(5->9->2),输出8->0->8(即513+295)<br>
4. 如何对链表进行重新排序
> **题目**：给定链表L0->L1->L2->...->Ln，把链表重新排序为L0->Ln->L1->L(n-1)->L2->L(n-2)->...。<br>
> 要求:<br>
> （1）在原来链表基础上进行排序，即不能申请新的结点<br>
> （2）只能修改结点的next域，不能修改数据域<br>
> **引申**：查询链表的中间结点
5. 如何找出单链表中的倒数第k个元素
> **题目**：找出单链表中的倒数第k个元素，如1->2->...->7，则倒数第k=3个元素为5<br>
> **引申**：将单链表向右旋转k个位置（给定单链表1->2->3...->7，k=3，那么旋转后单链表为5->6->7->1->2->3->4）
6. 如何检测一个较大单链表是否有环
> **题目**：单链表有环指的是单链表当中某个结点的next指针域指向链表中在它之前的某一结点，这样在链表的尾部就形成了一个环形结构。如何判断单链表是否有环存在？<br>
> **引申**：如果链表存在环，如何找到环的入口点
7. 如何把链表相邻元素翻转
> **题目**：把链表相邻元素翻转。（如1->2>...->7，逆序后为2->1->4->3...->7）<br>
8. 如何把链表以K个结点为一组进行翻转
> **题目**：K链表翻转是指把每K个相邻的结点看成一组进行翻转，如果剩余结点不足K个，则保持不变。假设给定链表1->2->3->4->5->6->7和一个数K，如果K的值为2，那么翻转后的链表为2->1->4->3->6->5->7。如果K的值为3，那么翻转后的链表为3->2->1->6->5->4->7<br>
9. 如何合并两个有序链表
> **题目**：已知两个链表head1和head2均有序（如升序排列），请把它们合并成一个链表，要求合并后的链表依然有序。<br>
10. 如何在只给定单链表中的某个结点的指针的情况下删除该结点
> **题目**：假设给定链表1->2->3->4->5->6->7中指向第5个元素的指针，要求把结点5删除，删除后链表变为1->2->3->4->6->7<br>
> **引申**：只给定单链表中某个结点p（非空结点），如何在p面前插入一个结点<br>
11. 如何判断两个单链表（无环）是否相交
> **题目**：单链表相交指的是两个链表存在完全重合的部分（两链表 从中间某个位置到最终是一样的，如下图1.11.1）。要求判断两个链表是否相交，如果相交，那么找出相交处的结点。<br>
> ![img1.11.1 图](https://github.com/Newbie-W/ProgrammerAlgorithmInterview/blob/master/pics/1.11/img%201.11.1.png)<br>
> **引申**：如果单链表有环，如何判断两个链表是否相交<br>
12. 如何翻转变异的链表
> **题目**：有一个链表，其中每个对象包含两个指针p1和p2。指针p1指向下一个对象，指针p2也指向一个对象，沿p1可以像普通链表一样完成顺序遍历，沿p2则可能会有重复。一种可能的例子如下。其中实线箭头是p1，虚线箭头是p2。使用C/C++语言实现<br>
> ![img1.12.1 图](https://github.com/Newbie-W/ProgrammerAlgorithmInterview/blob/master/pics/1.12/img%201.12.1.png)<br>
> 问题：设计一个函数，翻转这个链表，并返回头指针。链表结点的数据结构如下：<br>
> ``` C++
> struct Node {
> 	Node* p1;
> 	Node* p2;
> 	int data;
> };
> ```
13. 如何展开链接列表
> **题目**：给定一个有序链表，其中每个结点也表示一个有序链表，结点包含两个类型的指针：<br>
> （1）指向主链表中下一个结点的指针（称为“正确”指针）<br>
> （2）指向此结点头的链表（称为“down”指针）<br>
> 所有链表都被排序，如下图1.13.1<br>
> ![img1.13.1 图](https://github.com/Newbie-W/ProgrammerAlgorithmInterview/blob/master/pics/1.13/img%201.13.1.png)<br>
> 实现一个函数flatten()，该函数用来将链表扁平化成单个链表，扁平化的链表也应该被排序。例如，对于上述输入链表，输出链表应为3->6->8->11->15->21->22->30->31->39->40->45->50<br>

