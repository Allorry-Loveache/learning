
#include<iostream>
#include<string>
using namespace std;
int main() {
    string a;
    cin >> a;
    int dot = a.length();  //默认为数组长度
    int i, len = a.length();
    for (i = 0; i < dot; i++) {
        if (a[i] < '0' || a[i] > '9') {
            dot = i;   //符号所在的下标
            break;
        }
    }
    int tail = dot - 1;
    while (a[tail] == '0' && tail > 0)  tail--;  //消除符号之前的多余0,最多到达下标0
    for (i = tail; i >= 0; i--) putchar(a[i]);  //就算是0也会输出，很省事

    if (dot == len) return 0;  //如果没有符号，直接走人
    if (a[dot] == '%') { putchar('%'); return 0; } //这个符号输出完就走人
    else {
        putchar(a[dot++]);   //输出符号
        while (a[dot] == '0' && dot < a.length()) dot++;
        if (dot == len) putchar('0');  //消除前置0，符号之后部分如果全是0，也得输出一个0
        tail = len - 1;
        while (a[tail] == '0' && tail > dot) tail--;  //消除后置0
        for (i = tail; i >= dot; i--) {
            putchar(a[i]);
        }
    }
}



