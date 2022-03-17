
//根据打印自上而下的局限性，先求出各个字母的个数，设置最高的高度
//然后一层一层往下打印


#include<iostream>
#include<string>
using namespace std;
int a[26];
int main()
{
    string s;
    int n = 4, max = 0, i, j;
    while (n--) {
        getline(cin, s);
        for (i = 0; i < s.length(); i++) {
            if (isalpha(s[i]))  a[s[i] - 65]++;
        }
    }
    for (i = 0; i < 26; i++) {
        if (max < a[i]) max = a[i];
    }
    for (i = max; i > 0; i--) {
        for (j = 0; j < 26; j++) {
            if (a[j] < i) cout << "  ";
            else {
                cout << "*";
                if (j != 25) cout << ' '; //最后一列不留空格
            }
        }
        puts("");
    }
    for (i = 0; i < 26; i++) {
        printf("%c", i + 65);
        if (i != 25) cout << ' ';
    }

}