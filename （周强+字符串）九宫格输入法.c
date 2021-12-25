
#include <stdio.h>
char a[10][10] = { "0 ","1,.?!","2ABC","3DEF","4GHI","5JKL","6MNO","7PQRS",
                 "8TUV","9WXYZ" };
char b[1000];
int main() 
{
    gets(b);  
    b[strlen(b)] = ' ';  //空格键象征输入结束，开始统计连续打了几次键盘
    int i,k, j = 0;
    for (i = 0; b[i] != '\0'; i++) {
        switch (b[i]) {
            //k存储输的什么数；j用来模运算；读到空格就统计并输出
        case'0': k = b[i] - '0'; j++; if (j == 3) j %= 2; break;
        case'1': k = b[i] - '0'; j++; if (j == 6) j %= 5; break;
        case'2': k = b[i] - '0'; j++; if (j == 5) j %= 4; break;
        case'3': k = b[i] - '0'; j++; if (j == 5) j %= 4; break;
        case'4': k = b[i] - '0'; j++; if (j == 5) j %= 4; break;
        case'5': k = b[i] - '0'; j++; if (j == 5) j %= 4; break;
        case'6': k = b[i] - '0'; j++; if (j == 5) j %= 4; break;
        case'7': k = b[i] - '0'; j++; if (j == 6) j %= 5; break;
        case'8': k = b[i] - '0'; j++; if (j == 5) j %= 4; break;
        case'9': k = b[i] - '0'; j++; if (j == 6) j %= 5; break;
        case' ': printf("%c", a[k][j-1]); j = 0; break;
        default:break;
        }
    }
}
