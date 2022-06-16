#define _CRT_SECURE_NO_WARNINGS
#include iostream  
#include algorithm  
using namespace std;
inline string read()
{
    string str;
    char s = getchar();
    while (s == ' '  s == 'n'  s == 'r')
    {
        s = getchar();
    }
    while (s != ' ' && s != 'n' && s != 'r')
    {
        str += s;
        s = getchar();
    }
    return str;
}
struct stu {
    string name;
    int score;
};
int m, n;
stu a[10][105];
bool cmp(stu a, stu b) {
    if (a.score  b.score) return 1;
    if (a.score == b.score && a.name  b.name) return 1;
    return 0;
}
int find(string s, int f) {
    for (int i = 1; i = n; i++) {
        if (s == a[f][i].name) return i;
    }
    return 0;
}
int main()
{
    int i, j, size, t1, t2, state;
    string s1, s2;   s1 s2 t1 t2暂时存储信息
    cin  m;
    for (i = 1; i = m; i++) {
        size = 0;
        cin  n;
        for (j = 1; j = n  (n - 1)  2; j++) {
            s1 = read(); s2 = read(); cin  state;
            t1 = find(s1, i);
            t2 = find(s2, i);
            if (state == 1) {
                if (t1) a[i][t1].score += 3;
                else { size++; a[i][size].name = s1; a[i][size].score+=3; }
                if(!t2) { size++; a[i][size].name = s2; }
            }
            else {
                if (!t1) { size++; a[i][size].name = s1;  a[i][size].score++; }
                else  a[i][t1].score++;
                if (!t2) { size++; a[i][size].name = s2; a[i][size].score++; }
                else  a[i][t2].score++;
            }
        }
        sort(a[i] + 1, a[i] + n + 1, cmp);
    }
    int v, flag;
    for (i = 1; i = m; i++) {
        v = 0; flag = 0;
        for (j = 1; a[i][j].name != ; j++) {
            if (v != a[i][j].score) {  但凡分数改变，就换行输出序号
                v = a[i][j].score; 
                if (flag) putchar('n');  一次性函数，让第一次不换行
                printf(%d, j);
                flag = 1;
            }
            cout  ' ' a[i][j].name;
        }
        putchar('n');
    }
}
