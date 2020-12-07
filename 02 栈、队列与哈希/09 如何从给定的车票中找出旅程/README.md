### 情境：

> - 给定一趟旅途旅程中所有的车票信息，根据这个车票信息找出这趟旅程的路线。例如：给定下面的车票：（“西安”到“成都”），（“北京”到“上海”），（“大连”到“西安”），（“上海”到“大连”）。那么可以得到旅程路线为，北京->上海，上海->大连，大连->西安，西安->成都。假定给定的路线不会有环，也就是终点和起点不会是同一个城市。<br>
> - 实现printResult()函数。

```C++
#include <iostream>
#include <map>
#include <string>
using namespace std;

void printResult(map<string, string> tickets)
{
	// 实现内容
}


int main() {
	map<string, string> tickets;
	tickets["西安"] = "成都";
	tickets["北京"] = "上海";
	tickets["大连"] = "西安";
	tickets["上海"] = "大连";
	printResult(tickets);
	return 0;
}
```


### 方法
- **法一**：<br>
对于这种题目，一般而言，可以使用**拓扑排序**进行解答。根据车票信息构建一个图，然后找出这张图的拓扑排序序列，这个序列就是旅程的路线，但这种方法的效率不高，时间复杂度O(N)<br>

- **法二**<br>
此处使用法二，**hash法**。主要思路为，根据车票信息，构建hashmap，从hashmap中找到整个旅程的起点，接着就可以从起点出发依次找到下一站，进而知道终点。<br>
**具体实现**<br>
（1）根据车票的出发地与目的地构建hashmap。```Tickets={("西安", "成都"), ("北京", "上海"), ("大连", "西安"), ("上海", "大连")}```<br>
（2）构建```Tickets```的逆向hashmap。```ReverseTickets={("成都", "西安"), ("上海", "北京"), ("西安", "大连"), ("大连", "上海")}```<br>
（3）遍历```Tickets```，对于遍历到的key值，判断这个值是否在```ReverseTickets```中的key中存在，如果不存在，那么说明遍历到的```Tickets```的```key```值就是旅途的起点。<br>