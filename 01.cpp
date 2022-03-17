
int read() {         //���
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

void write(int s) {  //��д
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

void qsort(int l, int r)//Ӧ�ö���˼��
{
	int mid = a[(l + r) / 2];//�м���
	int i = l, j = r;
	while (i <= j) {//����ע��Ҫ��=
		while (a[i] < mid) i++;//������벿�ֱ��м��������
		while (a[j] > mid) j--;//�����Ұ벿�ֱ��м���С����
		if (i <= j)//�����һ�鲻����������������С�Ҵ󣩵���
		{
			swap(a[i], a[j]);//����
			i++;
			j--;
		}
	}
	if (l < j) qsort(l, j);//�ݹ�������벿��
	if (i < r) qsort(i, r);//�ݹ������Ұ벿��
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