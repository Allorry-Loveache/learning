
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n, a, b, c, ans;
    char ch;
    cin >> n;
    while (n--) {
        a = 0; b = 0;
        cin >> ch;
        if (isdigit(ch)) {   //上来就是数字，一直往后读入
            while (ch != ' ') {
                a = a * 10 + ch - '0';
                ch = getchar();
            }
            cin >> b;
        }
        else {
            c = ch;
            cin >> a >> b;
        }
        if (c == 'a') cout << a << "+" << b << "=" << a + b << endl, ans = a + b;
        if (c == 'b') cout << a << "-" << b << "=" << a - b << endl, ans = a - b;
        if (c == 'c') cout << a << "*" << b << "=" << a * b << endl, ans = a * b;

        int count = 0;
        if (a == 0) count++;    //0也要算一位
        else while (a) a /= 10, count++;
        if (b == 0) count++;
        else while (b) b /= 10, count++;
        if (ans == 0) count++;
        else if (ans < 0) count++, ans *= -1;  //有可能负数，负号占一位
        while (ans) ans /= 10, count++;
        cout << count + 2 << endl;   //最后别忘了两个符号
    }
}
