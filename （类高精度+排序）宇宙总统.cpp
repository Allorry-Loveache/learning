#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
    string x; //装票数
    int num;  //装号数
    int lenx; //装票数的位数
    bool operator<(const node& d) const {
        if (lenx != d.lenx) return lenx > d.lenx;
        if (x != d.x) return x > d.x;
        return 0;
    }
}s[25];
//inline bool cmp(node a, node b)
//{
//    if (a.lenx > b.lenx) return 1; //前一个比后一个位数多，不交换
//    if (a.lenx == b.lenx && a.x > b.x) return 1; //位数相同，但前一个按字典序排列比后一个大，也不交换。
//    return 0; //剩下情况均要交换。
//}
//另一种cmp写法
/*inline bool cmp(node x, node y) {
    if (x.s.size() == y.s.size())
        return x.s > y.s;
    else return x.s.size() > y.s.size();
}*/

inline string read() {
    string a;
    char ch = getchar();
    while (ch == ' ' || ch == '\r' || ch == '\n') ch = getchar();
    while (ch != -1 && ch != ' ' && ch != '\r' && ch != '\n') {
        a.push_back(ch);
        ch = getchar();
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        s[i].x = read();
        s[i].num = i; //存号数
        s[i].lenx = s[i].x.size(); //存票数的位数
    }
    sort(s + 1, s + n + 1); //排序
    cout << s[1].num << endl;  //输出首位答案即可，注意先输出号数
    cout << s[1].x << endl; //再输出票数
    return 0;
}



//滚动数组 方便快捷
//#include<iostream>
//#include<string>
// using namespace std;
// int main()
// {
//     int n;
//     string a, m = "0";
//     int max1 = 0, max2 = 0;
//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         cin >> a;
//         if (a.length() > max1 || a.length() == max1 && a > m) {
//             m = a;
//             max1 = a.length();
//             max2 = i;
//         }
//     }
//     cout << max2 << endl << m;
// }
