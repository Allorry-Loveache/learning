
#include<iostream>
using namespace std;
struct note {
	int x;
	int y;
	int step;
}b[160010];

int a[401][401];
int nex[8][2] = { {1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1} };

int main()
{
	int n, m, sx, sy;
	cin >> n >> m >> sx >> sy;
	int head = 1, tail = 2;
	b[head].x = sx; b[head].y = sy; b[head].step = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = -1;
	a[sx][sy] = 0;
	while (head < tail) {
		for (int k = 0; k < 8; k++) {
			int tx = b[head].x + nex[k][0];
			int ty = b[head].y + nex[k][1];
			if (tx<1 || tx>n || ty<1 || ty>m) continue;
			if (a[tx][ty] == -1) {
				b[tail].x = tx;
				b[tail].y = ty;
				b[tail].step = b[head].step + 1;
				a[tx][ty] = b[tail].step;
				tail++;
			}
		}
		head++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%-5d", a[i][j]);
		}
		printf("\n");
	}

}
