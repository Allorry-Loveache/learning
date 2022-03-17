// 1.仿strstr做法，最基本
//但凡轻敌了，直接暴毙，这道题挺麻烦的

#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000005];
	char b[15];
	int flag = 1, sum = 0, save = 0;
	gets(b); gets(a);
	for (int i = 0; a[i] != '\0'; i++)
		if (a[i] >= 65 && a[i] <= 90) a[i] += 32;
	for (int i = 0; b[i] != '\0'; i++)
		if (b[i] >= 65 && b[i] <= 90) b[i] += 32;
	//仿照strstr的算法进行查找
	char* p1 = a, * p2 = b, * start = a;
	while (*start) {
		p1 = start;
		p2 = b;
		while (*p1 && *p2) {
			if (*p1 == *p2) {
				p1++; p2++;
			}
			else {
				break;
			}
		}
		//1. 保证开头是空格  或者不是别的，就是单词首字母
		//2. 保证末尾是空格或者终止符
		if (*p2 == '\0' && (start == a || *(start - 1) == ' ') &&
			(*p1 == ' ' || *p1 == '\0')) {
			if (flag) {
				save = start - a;   //保存第一次指针之间的距离
				flag = 0;
			}
			sum++;
		}
		start++;
	}
	if (flag) {
		printf("-1");
	}
	else printf("%d %d", sum, save);
}



// 2.灵活运用find 和 string::npos
#include <iostream>
#include <string>
//命名空间
using namespace std;
int main() {
	//定义两个字符串
	string a;
	string b;
	//用string库，调用getline, 直接读入一整行
	getline(cin, a);
	getline(cin, b);
	//转换大小写，可以都转换为大写，或者小写
	for (int i = 0; i < a.length(); ++i) {
		a[i] = tolower(a[i]);
	}
	for (int i = 0; i < b.length(); ++i) {
		b[i] = tolower(b[i]);
	}
	//因为连起来的不算，所以要在前后加几个空格，一定要是同样多的，同量减同量，等于同量
	a = ' ' + a + ' ';
	b = ' ' + b + ' ';
	//先看看会不会找不到，用a.find()和string::npos
	if (b.find(a) == string::npos) {  //string::npos是特殊值，找不到字符串
		cout << -1 << endl;
	}
	//如果找得到
	else {
		int alpha = b.find(a);   //第一次的位置，find函数返回size_t
		int beta = b.find(a), s = 0;//beta记录出现位置的下标， 计数器初始化为0
		while (beta != string::npos) {
			++s;//计数器
			beta = b.find(a, beta + 1);   //从b的下标为beta+1处开始查找
		}
		cout << s << " " << alpha << endl;//输出第一个和总共有几个
	}
	//函数返回值为0，结束整个程序
	return 0;
}



// 3.灵活运用 insert 和 transform
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	string a, b;
	cin >> a;
	getchar();//其实我不知道要不要吞回车 
	transform(a.begin(), a.end(), a.begin(), ::tolower);//使a小写化 
	getline(cin, b);
	b.insert(0, " ");//让b前面加个空格 之后用find不怕查不到第一个 
	//然后处理a的首尾
	a = a + ' ';
	a.insert(a.begin(), ' ');
	transform(b.begin(), b.end(), b.begin(), ::tolower);//小写化 
	if (b.find(a) == -1)
	{
		cout << "-1";
	}
	else
	{
		int sum = 0; int n = 0;
		while (b.find(a, n) != -1)//find找不到会返回npos也就是-1 
		{
			sum++;
			n = b.find(a, n) + 1;//剩下都好理解 

		}
		cout << sum << " ";
		cout << b.find(a);
	}
}



