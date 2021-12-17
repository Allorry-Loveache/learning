#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAXN 20
void delchar(char* str, char c);
void ReadString(char s[]); /* 由裁判实现，略去不表 */
int main()
{
    char str[MAXN], c;
    scanf("%c\n", &c);
    ReadString(str);
    delchar(str, c);
    printf("%s\n", str);
    return 0;
}
void delchar(char* str, char c) {
    char* t = str;
    while (*str != '\0') {
        if (*str == c)
            str++;
        else {
            *t = *str;
            str++; t++;
        }
    }
    *t = '\0';
}
//a   b b b a a a b 