
#include<stdio.h>
int main(){
	int n,a,b;
	scanf("%d",&n);
	a = n/16;
	b = n%16;
	printf("%d",a*10+b);
	return 0;
}
