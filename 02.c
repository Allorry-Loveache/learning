#define _CRT_SECURE_NO_WARNINGS 1
/*����˼�����ģ����һ�к͵�һ���������*/

// #include <stdio.h> 
// int a[39][39];
// int main()
// {
// 	int i, j, n;
// 	scanf("%d", &n);
// 	a[0][(n + 1) / 2 - 1] = 1;
// 	int x = 0, y = (n + 1) / 2 - 1;
// 	for (i = 2; i <= n*n; i++) {
// 		if (x == 0 && y == n - 1) {
// 			a[++x][y] = i;
// 		}
// 		else if (x == 0) {
// 			a[n - 1][++y] = i;
// 			x = n - 1;
// 		}
// 		else if (y == n-1) {
// 			a[--x][0] = i;
// 			y = 0;
// 		}
// 		else if (a[x - 1][y + 1] == 0)
// 			a[--x][++y] = i;
// 		else a[++x][y] = i;
// 	}
// 	for (i = 0; i < n; i++) {
// 		for (j = 0; j < n; j++)
// 			printf("%d ", a[i][j]);
// 		puts("");
// 	}
// }

/*����ĵĵ㣺ֻҪ�������ϱߣ��߼����ϣ��ǿյģ�
			  �Ǿ����ȥ������ͷ����·����߼��£�*/
#include <stdio.h> 
int a[40][40];
int main()
{
	int i, j, n;
	scanf("%d", &n);
	int x = 1, y = (n + 1) / 2;
	for (i = 1; i <= n * n; i++) {
		a[x][y] = i;
		if (!(a[(x - 2 + n) % n + 1][(y + n) % n + 1]))
			x = (x - 2 + n) % n + 1, y = y % n + 1;
		else x = x % n + 1;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			printf("%d ", a[i][j]);
		puts("");
	}
}