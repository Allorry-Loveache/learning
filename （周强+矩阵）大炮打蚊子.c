
#include <stdio.h>
int a[25][25]; char b[25][25];
int main()
{
	int m, n, i, k, x, y;
	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++)
		scanf("%s", b[i]);
	scanf("%d", &k);
	while(k--) {
		int count = 0;
		scanf("%d %d", &x, &y);
            //讨论五个伤害范围
		if (b[x][y] == '#') {    
			a[x][y] += 2;     //中心2点伤害
            //如果这个格子积累了2点以上的伤害，就清理掉，计数
			if (a[x][y] >= 2) {b[x][y] = '0'; count++;}  
		}
		if (b[x-1][y] == '#') {
			a[x-1][y] ++;
			if (a[x-1][y] >= 2) {b[x-1][y] = '0'; count++;}
		}
		if (b[x+1][y] == '#') {
			a[x+1][y] ++;
			if (a[x+1][y] >= 2) {b[x+1][y] = '0'; count++;}
		}
		if (b[x][y-1] == '#') {
			a[x][y-1] ++;
			if (a[x][y-1] >= 2) {b[x][y-1] = '0'; count++;}
		}
		if (b[x][y+1] == '#') {
			a[x][y+1] ++;
			if (a[x][y+1] >= 2) {b[x][y+1] = '0'; count++;}
		}
		printf("%d\n", count);
	}
}
