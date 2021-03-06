/*
法三：空间换时间
使用辅助空间，牺牲一定的空间，降低时间复杂度


主要思路：
1.建立一个hash_set，用来存储已经遍历过的结点，并将其初始化为空。
2.从头开始遍历链表中的所有结点，存在以下两种情况：
	（1）如果结点内容已经在hash_set中，则删除此结点，继续向后遍历
	（2）如果结点内容不在hash_set中，则保留此结点，将此结点内容添加至hash_set中，继续向后遍历。
*C语言需自己实现hash_set，C++使用类库即可
*/