//#include<iostream>
//#include<cmath>
//using namespace std;
//int s[11], b[11];
//int n, minn=0x7fffffff;
////我不想用数组记录调料是否已用，我想通过递增来避免重复
//void dfs(int sx, int ss, int bb) { //起点，目前酸度，目前苦度
//	for (int i = sx + 1; i <= n; i++) {
//		ss *= s[i]; bb += b[i];
//		minn = min(minn, abs(ss - bb)); 
//		dfs(i, ss, bb);
//		ss /= s[i]; bb -= b[i];
//	}
//}
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> s[i] >> b[i];
//	dfs(0,1,0);
//	cout << minn;
//}




#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int M = 15;//养成良好习惯
int a[M], b[M], n, ans = 0x7fffffff;
//ans初始化为最大值
void dfs(int i, int x, int y) {
    //i是表示目前的配料编号，x为酸度，y为甜度
    if (i > n) {
        //注意，必须大于n才表示全部搜完
        if (x == 1 && y == 0)return;
        //判断清水的情况
        ans = min(abs(x - y), ans);
        //更新ans
        return;
    }
    //分两种情况搜索：1添加 2不添加
    dfs(i + 1, x * a[i], y + b[i]);
    dfs(i + 1, x, y);
    //这题无需回溯，不明白为何有些题解居然还用全局变量，非得回溯-_-||
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        //读入，用cin太慢了
    }
    dfs(1, 1, 0);
    printf("%d\n", ans);
    return 0;
}