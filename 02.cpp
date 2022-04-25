#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//删除偶数
	vector <int> v = { 2,14,21,54,33,75,976,23,5,754,12,53,0 };
	vector<int>::iterator i = v.begin();
	/*for (; i < v.end(); i++) {
		if (*i % 2 == 0) v.erase(i);
	  }
	  该代码报错，erase忽略了一些元素
	*/
	//以上代码报错，以下内容为正确案例
	while (i != v.end()) {
		if (*i % 2 == 0)  i = v.erase(i);  //返回删除位置的下一个位置
		else i++;
	}
	for (i = v.begin(); i < v.end(); i++) {
		cout << *i << ' ';
	}
}
