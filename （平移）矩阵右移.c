#include<stdio.h>
int main(){
    int i,n,m,j,a[15][15];
    scanf("%d %d",&m,&n);
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
	   scanf("%d",&a[i][j]);   
    m%=n;       //比如平移5个单位，对于3长度
                //矩阵，相当于平移2次
    for(i=0;i<n;i++){
    	for(j=0;j<n;j++)
      //反推法，比正着推要简单很多
      //这里仅为了打印，不需要多定义b数组
    	    printf("%d ",a[i][(j+n-m)%n]);
        printf("\n");	
    }	
}

//正推法code:
//#include<stdio.h>
//int a[15][15], b[15][15];
//int main() 
//{
//    int i, n, m, j;
//    scanf("%d %d", &m, &n);
//    for (i = 1; i <= n; i++)
//	  for (j = 1; j <= n; j++)
//	      scanf("%d", &a[i][j]);
//    m %= n;
//    for (i = 1; i <= n; i++)
//	  for (j = 1; j <= n; j++)
//	      b[i][(j + m -1) % n+1] = a[i][j];
//    for (i = 1; i <= n; i++) {
//	  for (j = 1; j <= n; j++)
//	      printf("%d ", b[i][j]);
//	  puts("");
//    }
//}
