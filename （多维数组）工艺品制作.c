
#include<stdio.h>
int a[50][50][50];
int w,x,h;
int q;
int main()
{
    scanf("%d%d%d",&w,&x,&h);
    scanf("%d",&q);
    while(q--)
    {
        int x1,x2,y1,y2,z1,z2;
        scanf("%d%d%d",&x1,&y1,&z1);
        scanf("%d%d%d",&x2,&y2,&z2);
        for(int i=x1;i<=x2;i++)
         for(int j=y1;j<=y2;j++)
          for(int k=z1;k<=z2;k++)
           a[i][j][k]=1;
    }
    int ans=0;
    for(int i=1;i<=w;i++)
     for(int j=1;j<=x;j++)
      for(int k=1;k<=h;k++)
       ans+=(a[i][j][k]==0);
    printf("%d\n",ans);
    return 0;
}
