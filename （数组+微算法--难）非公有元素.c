#include <stdio.h>
int a[101],b[101];
int main()
{
	int n, i, flag=0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		a[b[i]]=1;
	}
	for (i = 1;i<=n; i++) 
		if (a[b[i]]) {
			if(flag) printf(" ");
            printf("%d",b[i]);
            flag=1;
            a[b[i]]=0;
	    }
}
