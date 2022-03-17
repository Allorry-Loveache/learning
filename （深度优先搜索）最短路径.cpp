
int a[51][51], book[51][51];
int endx, endy, min = 99999, m, n;
int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
void dfs(int x, int y, int step) {
	if (x == endx && y == endy) {
		if (min > step) min = step;
		return;
	}
	if (step > min) return;
	int k, tx, ty;
	for (k = 0; k < 4; k++) {
		tx = x + next[k][0];
		ty = y + next[k][1];
		if (tx<1 || tx>m || ty<1 || ty>n) {
			continue;
		}
		if (a[tx][ty] == 0 && book[tx][ty] == 0) {
			book[tx][ty] = 1;
			dfs(tx, ty, step + 1);
			book[tx][ty] = 0;
		}
	}
	return;
}
int main()
{
	int startx, starty, i, j;
	scanf("%d %d %d %d %d %d", &startx, &starty, &endx, &endy, &m, &n);
	book[startx][starty] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	dfs(startx, starty, 0);
	printf("%d", min);
}

