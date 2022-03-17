
int read() {         //快读
	char ch = getchar();
	int s = 0, w = 1;
	while (ch < '0' || ch>'9') {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}

void write(int s) {  //快写
	int k = 0, len = 0;
	if (s == 0)
		putchar('0');
	while (s) {
		k = k * 10 + s % 10;
		s /= 10, len++;
	}
	for (int i = 0; i < len; i++) {
		putchar(k % 10 + '0');
		k /= 10;
	}
}

int n, a[1000001];

void qsort(int l, int r)//应用二分思想
{
	int mid = a[(l + r) / 2];//中间数
	int i = l, j = r;
	while (i <= j) {//这里注意要有=
		while (a[i] < mid) i++;//查找左半部分比中间数大的数
		while (a[j] > mid) j--;//查找右半部分比中间数小的数
		if (i <= j)//如果有一组不满足排序条件（左小右大）的数
		{
			swap(a[i], a[j]);//交换
			i++;
			j--;
		}
	}
	if (l < j) qsort(l, j);//递归搜索左半部分
	if (i < r) qsort(i, r);//递归搜索右半部分
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	sort(1, n);
	for (int i = 1; i <= n; i++) {
		write(a[i]);
		putchar(' ');
	}
}