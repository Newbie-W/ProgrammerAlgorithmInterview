/*
给定一个数组，找出数组中是否有两个数对(a, b)和(c, d)，使得a+b=c+d，其中，a、b、c、d是不同的元素。如果有多个答案，打印任意一个即可。例如给定数组：{3, 4, 7, 10, 20, 9, 8}， 可以找到两个数对(3, 8)和(4, 7)，使得3+8=4+7。
思路步骤：
hash法，以数对为单位进行遍历，在遍历过程中，把数对与数对的和存储在哈希表中（键为数对的和，值为数对），当遍历到一个键值对，如果它的和在哈希表中已经存在，那么就找到了满足条件的键值对。

时间复杂度 O(N^2)（因为算法使用了双重循环，而hashmap的插入和查找操作实际的时间复杂度为O(1)）
*/

#include <iostream>
#include <map>
#include <utility>
using namespace std;

bool findPairs(int arr[], int n)
{
	// 键为数对的和，值为数对
	map<int, pair<int, int>> sumPair;
	
	// 遍历数组中所有可能的数对
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; j++)
		{
			// 如果这个数对的和在map中没有，则放入map中
			int sum = arr[i] + arr[j];
			if (sumPair.find(sum) == sumPair.end())
			{
				sumPair[sum] = make_pair(i, j);
			}
			
			// map中已经存在与sum相同的数对，找出来并打印
			else 
			{
				pair<int, int> pp = sumPair[sum];	// pp->previous pair
				cout<<"("<<arr[pp.first]<<", "<<arr[pp.second]<<"), ("<<arr[i]<<", "<<arr[j]<<")\n";
				return true;
			}
		}
	}
	return false;
}