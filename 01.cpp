#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
typedef struct {
    int num;
    int c, m, e;
    int sum;
}stu;
bool cmp(stu a, stu b)
{
    if (a.sum > b.sum) return 1;//总分大于b就返回1
    else if (a.sum < b.sum) return 0;//否则返回0
    else//相等
    {
        if (a.c > b.c) return 1;//比较语文
        else if (a.c < b.c) return 0;
        else//语文也相等
        {
            if (a.num > b.num) return 0;//比较编号
            else return 1;
        }
    }
}
int main()
{
    stu a[400];
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        a[i].num = i;
        scanf("%d %d %d", &a[i].c, &a[i].m, &a[i].e);
        a[i].sum = a[i].c + a[i].m + a[i].e;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (i = 1; i <= 5; i++) {
        printf("%d %d\n", a[i].num, a[i].sum);
    }
}


//bool cmp(int a, int b) {
//    int sum1 = 0, sum2 = 0;
//    while (a) {
//        sum1 += pow(a % 10, 2); a /= 10;
//    }
//    while (b) {
//        sum2 += pow(b % 10, 2); b /= 10;
//    }
//    return sum1 < sum2;
//}
//int main()
//{
//    vector<int> v;
//    int t;
//    while (cin >> t) {
//        v.push_back(t);
//    }
//    sort(v.begin(), v.end(), cmp);
//    for (vector<int>::iterator it = v.begin(); it < v.end(); it++) {
//        printf("%d ", *it);
//    }
//
//}



//#define ADD 5
//typedef struct person {
//    string name;
//}person;
//typedef struct contact {
//    person* data;
//    int size;
//    int capacity;
//}contact;
//
//
//void Init(contact& con) {
//    con.data = new person[5];
//    con.capacity = ADD;
//    con.size = 0;
//}
//
//bool cmp(person a, person b) {
//    if (a.name < b.name) return 1;
//    else return 0;
//}
//
//int main() {
//    contact con;
//    Init(con);
//    con.data[0].name = "vsd";
//    con.data[1].name = "acvc";
//    con.data[2].name = "fvsc";
//    con.data[3].name = "bffs";
//    con.data[4].name = "kilf";
//    sort(con.data, con.data + 5, cmp);
//    for (int i = 0; i < 5; i++) {
//        cout << con.data[i].name << endl;
//    }
//}
