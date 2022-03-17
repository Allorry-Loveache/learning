
typedef struct note {
	int x;
	int y;
}note;
int next[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
char a[21][21];
int book[21][21];
int nums(int x, int y) {
	int tx = x, ty = y, nums = 0;
	while (a[tx][ty] != '#') {
		if (a[tx][ty] == 'G') {
			nums++;
		}
		tx--;
	}
	tx = x;
	while (a[tx][ty] != '#') {
		if (a[tx][ty] == 'G') {
			nums++;
		}
		tx++;
	}
	tx = x;
	while (a[tx][ty] != '#') {
		if (a[tx][ty] == 'G') {
			nums++;
		}
		ty--;
	}
	ty = y;
	while (a[tx][ty] != '#') {
		if (a[tx][ty] == 'G') {
			nums++;
		}
		ty++;
	}
	return nums;

}
int main()
{
	note queue[401];
	int i, j, k, m, n, head = 1, tail = 1;
	int startx, starty, tx, ty;
	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++) {
		scanf("%s", a[i]);
	}
	scanf("%d %d", &startx, &starty);
	int mx = startx, my = starty;
	book[startx][starty] = 1;
	queue[tail].x = startx;
	queue[tail].y = starty;
	tail++;
	int max = nums(startx, starty);
	while (head < tail) {
		for (k = 0; k <= 3; k++) {
			tx = queue[head].x + next[k][0];
			ty = queue[head].y + next[k][1];
			if (tx<0 || tx>m - 1 || ty<0 || ty>n - 1) {
				continue;
			}
			if (a[tx][ty] == '.' && book[tx][ty] == 0) {
				book[tx][ty] = 1;
				queue[tail].x = tx;
				queue[tail].y = ty;
				tail++;
				int sum = nums(tx, ty);
				if (max < sum) {
					max = sum;
					mx = tx;
					my = ty;
				}
			}

		}
		head++;
	}
	printf("%d %d %d", max, mx, my);
}



//Éî¶ÈÓÅÏÈËÑË÷ÈçÏÂ£º

#include<stdio.h>
int next[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
char a[21][21];
int book[21][21];
int i, k, m, n, max, mx, my;
int nums(int x, int y) {
	int tx = x, ty = y, nums = 0;
	while (a[tx][ty] != '#') {
		if (a[tx][ty] == 'G') {
			nums++;
		}
		tx--;
	}
	tx = x;
	while (a[tx][ty] != '#') {
		if (a[tx][ty] == 'G') {
			nums++;
		}
		tx++;
	}
	tx = x;
	while (a[tx][ty] != '#') {
		if (a[tx][ty] == 'G') {
			nums++;
		}
		ty--;
	}
	ty = y;
	while (a[tx][ty] != '#') {
		if (a[tx][ty] == 'G') {
			nums++;
		}
		ty++;
	}
	return nums;
}
void dfs(int x, int y) {
	int tx, ty;
	for (k = 0; k <= 3; k++) {
		tx = x + next[k][0];
		ty = y + next[k][1];
		if (tx<0 || tx>m - 1 || ty<0 || ty>n - 1) {
			continue;
		}
		if (a[tx][ty] == '.' && book[tx][ty] == 0) {
			book[tx][ty] = 1;
			int sum = nums(tx, ty);
			if (sum > max) {
				max = sum;
				mx = tx;
				my = ty;
			}
			dfs(tx, ty);
		}
	}
	return;
}
int main()
{

	int startx, starty;
	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++) {
		scanf("%s", a[i]);
	}
	scanf("%d %d", &startx, &starty);
	mx = startx, my = starty;
	book[startx][starty] = 1;
	max = nums(startx, starty);
	dfs(startx, starty);
	printf("%d %d %d", max, mx, my);
}
