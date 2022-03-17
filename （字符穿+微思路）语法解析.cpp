
//以‘=’为标节点，判断左边和右边
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int a[4] = { 0 };
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '=') {
            if (isdigit(s[i + 1]))  a[s[i - 2] - 'a'] = s[i + 1] - '0';
            else if (isalpha(s[i + 1]))  a[s[i - 2] - 'a'] = a[s[i + 1] - 'a'];
        }
    }
    printf("%d %d %d", a[0], a[1], a[2]);
}
