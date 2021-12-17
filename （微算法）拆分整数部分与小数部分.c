
#include <stdio.h>
void splitfloat( float x, int *intpart, float *fracpart );
int main()
{
    float x, fracpart;
    int intpart;
    scanf("%f", &x);
    splitfloat(x, &intpart, &fracpart);
    printf("The integer part is %d\n", intpart);
    printf("The fractional part is %g\n", fracpart);
    return 0;
}

//核心部分，无需多想，直接强制类型转换

void splitfloat( float x, int *intpart, float *fracpart ){
	*intpart = (int)x;
	*fracpart = x- (*intpart);	
}
 
