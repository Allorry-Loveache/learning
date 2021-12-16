
#include<stdio.h>
#include<math.h>
int main()
{
    char a[100],c; int i=0,t=1,temp=1,sum=0;
    while ((c = getchar() )!= '\n') {
	if(c=='#') break;
	if (c >= 65 && c <= 70 ){
	    a[i] = c-'A'+10;  i++;  t=0;    //十六进制字符a-f 10-15
	}
	if (c >= 97 && c <= 102) {
	    a[i] = c - 'a' + 10;  i++;  t=0;
	}
	if (c >= '0' && c <= '9') {
	    a[i] = c - '0';  i++;   t=0;
	}
	if(t && c=='-')  temp*=-1;
    }
    for (int j = i-1; j >= 0; j--)      //从第一位开始转换到最高位
	sum += pow(16, i - 1 - j) * a[j];
    printf("%d", sum*temp);
}
