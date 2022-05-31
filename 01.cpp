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
		//��¼�����������һ��Ԫ�ص��±�
		int end = i;
		//�������Ԫ��
		int tem = arr[end + 1];
		//������
		while (end >= 0){
			//�Ȳ��������������
			if (tem < arr[end]){
				arr[end + 1] = arr[end];
				end--;
			}
			//�Ȳ������С������ѭ��
			else break;
		}
		//tem�ŵ��Ȳ������С�����ĺ���
		arr[end + 1] = tem;
		//����ִ�е���λ�����������:
		//1.������Ԫ���ҵ�Ӧ����λ�ã�break����ѭ�����ˣ�
		//2.������Ԫ�رȵ�ǰ���������е�����Ԫ�ض�С��whileѭ�������󵽴ˣ�
	}
}




//ϣ������    ---    ����gap�Ĳ�������
void ShellSort(int* arr, int n){
	int gap = n;
	while (gap > 1){
		//ÿ�ζ�gap��3����
		gap = gap / 3 + 1;
		//��������
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




//ѡ������
void SelectSort(int* arr, int n)
{
	//������뵥������ĵ�һ���������һ�������±�
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//�������ֵ���±�
		int maxi = begin;
		//������Сֵ���±�
		int mini = begin;
		//�ҳ����ֵ����Сֵ���±�
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
		//��Сֵ�������п�ͷ
		swap(arr[mini], arr[begin]);
		//��ֹ��������beginλ�ñ�����
		if (begin == maxi)
		{
			maxi = mini;
		}
		//���ֵ�������н�β
		swap(arr[maxi], arr[end]);
		++begin;
		--end;
	}
}







//������
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








//��������
void _MergeSort(int* a, int l, int r, int* t) {
	if (l >= r) return;
	//���
	int mid = (l + r) / 2;
	_MergeSort(a, l, mid, t);
	_MergeSort(a, mid + 1, r, t);
	//�鲢
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
	//����t �͵� a
	for (int j = l; j <= r; j++)
		a[j] = t[j];
}

void MergeSort(int* a, int n) {
	int* t = new int[n];   //��ʱ����
	_MergeSort(a, 0, n - 1, t);
	delete[] t;
}





//��������  ������ʽ
void merge(int* a, int* t, int begin1, int end1, int begin2, int end2) {
	int i = begin1;
	int l = begin1, r = end2;  //�洢һ��
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
			int end2 = i + 2 * gap - 1;  //�Ұ������ĩβ�������г���
			if (i + gap >= n) break;     //�Ұ����䲻���ڣ�ֱ�ӱ𲢹���
			if (end2 >= n)               //�Ұ�����Խ���ˣ�����end2
				end2 = n - 1;

			merge(a, t, i, i + gap - 1, i + gap, end2);
		}
		gap *= 2;
	}
}








//  ��������
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
