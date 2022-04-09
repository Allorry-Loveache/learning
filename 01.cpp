//#include<iostream>
//#include<cmath>
//using namespace std;
//int s[11], b[11];
//int n, minn=0x7fffffff;
////�Ҳ����������¼�����Ƿ����ã�����ͨ�������������ظ�
//void dfs(int sx, int ss, int bb) { //��㣬Ŀǰ��ȣ�Ŀǰ���
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
const int M = 15;//��������ϰ��
int a[M], b[M], n, ans = 0x7fffffff;
//ans��ʼ��Ϊ���ֵ
void dfs(int i, int x, int y) {
    //i�Ǳ�ʾĿǰ�����ϱ�ţ�xΪ��ȣ�yΪ���
    if (i > n) {
        //ע�⣬�������n�ű�ʾȫ������
        if (x == 1 && y == 0)return;
        //�ж���ˮ�����
        ans = min(abs(x - y), ans);
        //����ans
        return;
    }
    //���������������1��� 2�����
    dfs(i + 1, x * a[i], y + b[i]);
    dfs(i + 1, x, y);
    //����������ݣ�������Ϊ����Щ����Ȼ����ȫ�ֱ������ǵû���-_-||
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        //���룬��cin̫����
    }
    dfs(1, 1, 0);
    printf("%d\n", ans);
    return 0;
}