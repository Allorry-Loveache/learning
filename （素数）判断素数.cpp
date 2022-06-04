bool isPrime_3(int n){
	if(n==2||n==3)	return 1;
	if(n%6!=1&&n%6!=5)	return 0;
	for(int i=5;i*i<=n;i+=6)
		if(n%i==0||n%(i+2)==0)	return 0;
	return 1;
}





//以下为 欧拉筛

#include<iostream>
using namespace std;
bool a[1000000] = { 1,1 }; // 打标机，标识素数
int b[100];// 记录所有的素数
int c = 0; // 记录素数的个数
int main()
{
	//素数的倍数不会是素数
	for (int i = 2; i <= 100; i++) {
		if (a[i] == 0) b[c++] = i;  // 把没打标记的存入素数
		for (int j = 0; j < c; j++) {  //遍历目前已经存了的素数
			if (i * b[j] > 100) break;
			a[i * b[j]] = 1;
			//灵魂一步，为了避免重复标记，必须有下面这一步
			if (i % b[j] == 0) break; 
		}
	}
	for (int i : b) cout << i << ' ';
}
