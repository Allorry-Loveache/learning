#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int ans;
string a;
int num[26] = { 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4 };        //26����ĸ�����Ҫ������ 
int main()
{
    getline(cin, a);
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z') ans += num[a[i] - 'a'];        //����дa[i]!=' ',��Ϊ����'\n'��'\r' 
        if (a[i] == ' ') ans++;    //����дelse��ΪҲ��'\n'��'\r'������������Ŀӵ㣬�ҽ��˺ü��Σ��������� 
    }
    printf("%d", ans);
    return 0;
}



#include"iostream"
#include"cstdio"
#include"cstring"//Ϊ��strchr���Һ���
using namespace std;
char s1[] = { " adgjmptw" }, s2[] = { "behknqux" }, s3[] = { "cfilorvy" }, s4[] = { "sz" };//�����������壬�ֱ𿪰�1~4�μ��̵ĳ�������
int main()
{
    char c;
    int s = 0;
    while ((c = getchar()) != EOF) //��=EOF��ʾ��û�������  
    {
        //��s1~s4�������ң��ҵ��ͼ���1~4
        if (strchr(s1, c)) s++;
        else if (strchr(s2, c)) s += 2;
        else if (strchr(s3, c)) s += 3;
        else if (strchr(s4, c)) s += 4; //ע�����ﲻ��д��else����Ϊ������\n���ַ�                       
    }
    cout << s << endl;
    return 0;
}