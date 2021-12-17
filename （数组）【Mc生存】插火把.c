/*火把的照亮可以拆分：
00100
0   0
1   1
0   0
00100 
 
 111
 111
 111 */

#include <stdio.h>
int a[100+5][100+5];
int main()
{
	int i, j, m, k, n, x, y, count = 0;
	scanf("%d %d %d", &n, &m, &k);
	while (m--) {
		scanf("%d %d", &x, &y);
		++x; ++y; //以下代码可能越界，在此直接把矩阵整体平移，防bug
		for (i = x - 1; i <= x + 1; i++)
			for (j = y - 1; j <= y + 1; j++)
				a[i][j] = 1;
		a[x][y - 2] = a[x][y + 2] = a[x - 2][y] = a[x + 2][y] = 1;
	}
	while (k--) {
		scanf("%d %d", &x, &y);
		++x; ++y;
		for (i = x - 2; i <= x + 2; i++)
			for (j = y - 2; j <= y + 2; j++)
				a[i][j] = 1;
	}
	for (i = 2; i <= n+1; i++)   //不用平移回去，直接整体打印
		for (j = 2; j <= n+1; j++)
			if (!a[i][j]) count++;
	printf("%d", count);
}
