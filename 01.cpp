
#include<iostream>
#include<string>
using namespace std;
int main() {
    string a;
    cin >> a;
    int dot = a.length();  //Ĭ��Ϊ���鳤��
    int i, len = a.length();
    for (i = 0; i < dot; i++) {
        if (a[i] < '0' || a[i] > '9') {
            dot = i;   //�������ڵ��±�
            break;
        }
    }
    int tail = dot - 1;
    while (a[tail] == '0' && tail > 0)  tail--;  //��������֮ǰ�Ķ���0,��ൽ���±�0
    for (i = tail; i >= 0; i--) putchar(a[i]);  //������0Ҳ���������ʡ��

    if (dot == len) return 0;  //���û�з��ţ�ֱ������
    if (a[dot] == '%') { putchar('%'); return 0; } //�����������������
    else {
        putchar(a[dot++]);   //�������
        while (a[dot] == '0' && dot < a.length()) dot++;
        if (dot == len) putchar('0');  //����ǰ��0������֮�󲿷����ȫ��0��Ҳ�����һ��0
        tail = len - 1;
        while (a[tail] == '0' && tail > dot) tail--;  //��������0
        for (i = tail; i >= dot; i--) {
            putchar(a[i]);
        }
    }
}



