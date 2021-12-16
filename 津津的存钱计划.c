#include <stdio.h>
int main()
{
	int i,a,sum1=0,sum2=0,d,t;
	for(i=1;i<=12;i++) {
		scanf("%d", &a);
		sum1 += 300; 
		d = sum1 - a;
		if (d < 0) {
			printf("%d",-1*i );
			return 0;
			
		}
		t = d / 100 *100;
		sum2 += t;
		sum1 = d-t;
	}
	printf("%.0f", sum2 * 1.2+sum1);
	return 0;
}
