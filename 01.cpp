#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

int a[] = { 1,5,32,8,91,15,27,2,3,643,2536 };
int n = sizeof(a) / sizeof(int);



void InsertSort(int* arr, int n){
	for (int i = 0; i < n - 1; ++i)
	{
		//记录有序序列最后一个元素的下标
		int end = i;
		//待插入的元素
		int tem = arr[end + 1];
		//单趟排
		while (end >= 0){
			//比插入的数大就向后移
			if (tem < arr[end]){
				arr[end + 1] = arr[end];
				end--;
			}
			//比插入的数小，跳出循环
			else break;
		}
		//tem放到比插入的数小的数的后面
		arr[end + 1] = tem;
		//代码执行到此位置有两种情况:
		//1.待插入元素找到应插入位置（break跳出循环到此）
		//2.待插入元素比当前有序序列中的所有元素都小（while循环结束后到此）
	}
}




//希尔排序    ---    带有gap的插入排序
void ShellSort(int* arr, int n){
	int gap = n;
	while (gap > 1){
		//每次对gap折3操作
		gap = gap / 3 + 1;
		//单趟排序
		for (int i = 0; i < n - gap; ++i){
			int end = i;
			int tem = arr[end + gap];
			while (end >= 0){
				if (tem < arr[end]){
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else break;
			}
			arr[end + gap] = tem;
		}
	}
}




//选择排序
void SelectSort(int* arr, int n)
{
	//保存参与单趟排序的第一个数和最后一个数的下标
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//保存最大值的下标
		int maxi = begin;
		//保存最小值的下标
		int mini = begin;
		//找出最大值和最小值的下标
		for (int i = begin; i <= end; ++i)
		{
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
		}
		//最小值放在序列开头
		swap(arr[mini], arr[begin]);
		//防止最大的数在begin位置被换走
		if (begin == maxi)
		{
			maxi = mini;
		}
		//最大值放在序列结尾
		swap(arr[maxi], arr[end]);
		++begin;
		--end;
	}
}







//堆排序
void AdjustDown(int* a, int n, int parent) {
	int child = parent * 2 + 1;
	while (child < n) {
		if (child + 1 < n && a[child] < a[child + 1]) child++;
		if (a[parent] < a[child]) {
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
void HeapSort(int *a, int n) {
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0) {
		swap(a[0], a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}








//并归排序
void _MergeSort(int* a, int l, int r, int* t) {
	if (l >= r) return;
	//拆分
	int mid = (l + r) / 2;
	_MergeSort(a, l, mid, t);
	_MergeSort(a, mid + 1, r, t);
	//归并
	int begin1 = l, end1 = mid;
	int begin2 = mid + 1, end2 = r;
	int i = l;
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] < a[begin2])
			t[i++] = a[begin1++];
		else t[i++] = a[begin2++];
	}
	while (begin1 <= end1) t[i++] = a[begin1++];
	while (begin2 <= end2) t[i++] = a[begin2++];
	//最后把t 送到 a
	for (int j = l; j <= r; j++)
		a[j] = t[j];
}

void MergeSort(int* a, int n) {
	int* t = new int[n];   //临时数组
	_MergeSort(a, 0, n - 1, t);
	delete[] t;
}





//并归排序  迭代形式
void merge(int* a, int* t, int begin1, int end1, int begin2, int end2) {
	int i = begin1;
	int l = begin1, r = end2;  //存储一下
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] < a[begin2])
			t[i++] = a[begin1++];
		else t[i++] = a[begin2++];
	}
	while (begin1 <= end1) t[i++] = a[begin1++];
	while (begin2 <= end2) t[i++] = a[begin2++];
	for (int j = l; j <= r; j++)
		a[j] = t[j];
}

void MSort(int* a, int n) {
	int* t = new int[n];
	int gap = 1;
	while (gap < n) {
		for (int i = 0; i < n; i += gap * 2) {
			int end2 = i + 2 * gap - 1;  //右半区间的末尾，单独列出来
			if (i + gap >= n) break;     //右半区间不存在，直接别并归了
			if (end2 >= n)               //右半区间越界了，调整end2
				end2 = n - 1;

			merge(a, t, i, i + gap - 1, i + gap, end2);
		}
		gap *= 2;
	}
}








//  计数排序
void CountSort(int* a, int n) {
	int maxx = *max_element(a, a + n);
	int minn = *min_element(a, a + n);
	int range = maxx - minn + 1;
	vector<int> t(range, 0);
	for (int i = 0; i < n; i++) 
		t[a[i] - minn]++;
	for (int i = 0, j = 0; i < range; i++) {
		while (t[i]--) a[j++] = i + minn;
	}
}

int main()
{
	CountSort(a, n);
	for (int i : a) cout << i << "  ";
}
