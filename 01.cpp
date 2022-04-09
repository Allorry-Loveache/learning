#include<stdio.h>
int arr[10] = { 6,2,5,5,4,5,6,3,7,6 };
int size(int x) {
	int num = 0;
	while (x / 10 != 0) {
		num += arr[x % 10];
		x /= 10;
	}
	num += arr[x];
	return num;
}
int main() {
	int n, a, b, c, t = 0;
	scanf("%d", &n);
	for (a = 0; a <= 1111; a++) {
		for (b = 0; b <= 1111; b++) {
			c = a + b;
			if (size(a) + size(b) + size(c) + 4 == n) {
				t++;
			}
		}
	}
	printf("%d", t);
}