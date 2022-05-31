
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





//其他版本

//三数取中优化
int getmid(int a, int b, int c){
    if(a>c)
    	return (a>b)?(b>c)? b: c  : a;
    else 
	return (c>b)?(a>b)? a: b  : c; 
}

void q_sort(int begin, int end){
    if (begin >= end) return;
    int mid = (begin + end) / 2;
    //三数取中
    int base = getmid(begin, end, mid);
    //全部取到最左边作为基准值
    if (base != begin) swap(a[base], a[begin]);
    int l = begin, r = end;
    while (l < r) {
        while (a[r] >= a[begin] && l < r) r--;
        while (a[l] <= a[begin] && l < r) l++;
        if (l < r) swap(a[l], a[r]);
    }
    swap(a[l], a[begin]);

    q_sort(begin, l - 1);
    q_sort(l + 1, end);
}





//前后指针版

void q_sort(int left, int right) {
	if (left >= right) return;
	int cur = left + 1, prev = left;
	int base = left;
	while (cur <= right) {
		if (a[cur] < a[base] && ++prev != cur) {
			swap(a[prev], a[cur]);
		}
		cur++;
	}
	swap(a[prev], a[base]);
	q_sort(left, prev - 1);
	q_sort(prev + 1, right);
}





//迭代版本
//单趟排
int PartSort(int* arr, int begin, int end)
{
	int key = arr[begin];
	while (begin < end)
	{
		while (key <= arr[end] && begin < end)
		{
			--end;
		}
		arr[begin] = arr[end];
		while (key >= arr[begin] && begin < end)
		{
			++begin;
		}
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	int meeti = begin;
	return meeti;
}

void QuickSortNoR(int* arr, int begin, int end)
{
	stack<int> st;
	//先入右边
	st.push(end);
	//再入左边
	st.push(begin);
	while (!st.empty())
	{
		//左区间
		int left = st.top();
		st.pop();
		//右区间
		int right = st.top();
		st.pop();
		//中间数
		int mid = PartSort(arr, left, right);
		//当左区间>=mid-1则证明左区间已经排好序了
		if (left < mid - 1)
		{
			st.push(mid - 1);
			st.push(left);
		}
		//当mid+1>=右区间则证明右区间已经排好序
		if (right > mid + 1)
		{
			st.push(right);
			st.push(mid + 1);
		}
	}
}
