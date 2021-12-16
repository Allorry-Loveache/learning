#include<stdio.h>
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i+=2){
	for(j=1;j<=n-i;j++)
	    printf(" ");
	for(k=1;k<=i;k++)
	    printf("* "); 
	printf("\n");
    }
    n-=2;
    for(i=n;i>0;i-=2){
        for(j=n-i+2;j>0;j--)
            printf(" ");
	for(k=i;k>0;k--)
	    printf("* ");
	printf("\n");	    
    }
	
}
