
#include<iostream>
using namespace std;

int main(void) {
	//打印二进制数
	int a[32];
	int num = 32;
	int tmp = 0;
	for (int i = 31; i >= 0; i--) {
		//第一次向左移动31位，第二次30位 
		tmp = (num >> i) & 1;
		a[31 - i] = tmp;
	}
	for (int i : a) cout << i;
}

