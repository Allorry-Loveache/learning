#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int ans;
string a;
int num[26] = { 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4 };        //26个字母打表需要按几次 
int main()
{
    getline(cin, a);
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z') ans += num[a[i] - 'a'];        //不能写a[i]!=' ',因为还有'\n'和'\r' 
        if (a[i] == ' ') ans++;    //不能写else因为也有'\n'和'\r'，这就是这个题的坑点，我交了好几次，欲哭无泪 
    }
    printf("%d", ans);
    return 0;
}



#include"iostream"
#include"cstdio"
#include"cstring"//为用strchr查找函数
using namespace std;
char s1[] = { " adgjmptw" }, s2[] = { "behknqux" }, s3[] = { "cfilorvy" }, s4[] = { "sz" };//可以望文生义，分别开按1~4次键盘的常量数组
int main()
{
    char c;
    int s = 0;
    while ((c = getchar()) != EOF) //！=EOF表示还没输入结束  
    {
        //在s1~s4中依次找，找到就加上1~4
        if (strchr(s1, c)) s++;
        else if (strchr(s2, c)) s += 2;
        else if (strchr(s3, c)) s += 3;
        else if (strchr(s4, c)) s += 4; //注意这里不能写成else，因为还会有\n等字符                       
    }
    cout << s << endl;
    return 0;
}