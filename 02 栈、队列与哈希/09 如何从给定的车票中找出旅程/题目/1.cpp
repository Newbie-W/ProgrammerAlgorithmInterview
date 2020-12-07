/*
给定一趟旅途旅程中所有的车票信息，根据这个车票信息找出这趟旅程的路线。
例如：给定下面的车票：（“西安”到“成都”），（“北京”到“上海”），（“大连”到“西安”），（“上海”到“大连”）。那么可以得到旅程路线为，北京->上海，上海->大连，大连->西安，西安->成都。假定给定的路线不会有环，也就是终点和起点不会是同一个城市。
思路步骤：
（1）根据车票的出发地与目的地构建hashmap。Tickets={("西安", "成都"), ("北京", "上海"), ("大连", "西安"), ("上海", "大连")}
（2）构建Tickets的逆向hashmap。ReverseTickets={("成都", "西安"), ("上海", "北京"), ("西安", "大连"), ("大连", "上海")}
（3）遍历Tickets，对于遍历到的key值，判断这个值是否在ReverseTickets中的key中存在，如果不存在，那么说明遍历到的Tickets的key值就是旅途的起点。

时间复杂度 O(N)
空间复杂度 O(N)
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

void printResult(map<string, string> tickets)
{
	map<string, string> reverseTickets;
	map<string, string>:iterator it;
	
	// 构建车票信息的逆向列表
	for (it = tickets.begin(); it != tickets.end(); it++)
	{
		reverseTickets[it->second] = it->first;
	}
	
	// 找出旅程的起点
	string start;
	for (it = tickets.begin(); it != tickets.end(); it++)
	{
		if (reverseTickets.find(it->first) == reverseTickets.end())		// 在逆向中，找不到与其key相同的key
		{
			start = it->first;
			break;
		}
	}
	
	// 没有找到起点
	if (start.empty())
	{
		cout<<"输入不合理"<<endl;
		return;
	}
	
	it = tickets.find(start);
	while (it != tickets.end())		// 找到key为start的键值对
	{
		cout<<it->first<<"->"<<it->second;
		it = tickets.find(it->second);
		if (it != tickets.end())
		{
			cout<<","
		}
	}
}