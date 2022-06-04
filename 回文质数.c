#include<iostream>
using namespace std;

bool prime(int n){
	if(n==2||n==3)	return 1;
	if(n%6!=1&&n%6!=5)	return 0;
	for(int i=5;i*i<=n;i+=6)
		if(n%i==0||n%(i+2)==0)	return 0;
	return 1;
}


bool func1(int n){  //回文
    int a[10];
    int t=n, sum=0;
    while(t>0){   //用数字反转判断回文
        sum=sum*10+t%10;
        t/=10;
    }
    return n==sum;
}

bool func2(int n){ //没有偶数位的回文数,除了11
    if(n>=1000 && n<=9999 || n>=100000 && n<=999999 
    || n>=10000000 && n<=99999999)
    return 0;
    return 1;
}

int main()
{
    int m,n;
    cin>>m>>n;
    if(m%2==0) m++;
    for(int i=m;i<=n;i+=2){
        if(!func2(i)) continue;
        if(!func1(i)) continue;
        if(!prime(i)) continue;
        printf("%d\n",i);
    }
    return 0;
}
