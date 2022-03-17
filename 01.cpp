#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


int credit[15];  //学分总数
typedef struct stu {
	int grade[15];   //各科成绩
	double goal[15]; //各科学分
	double get;      //学分总数
	string name;
}stu;

typedef struct classes {
	stu s[55];
}classes;
classes c[25];

bool cmp(stu a1, stu a2) {
	if (a1.get > a2.get) return 1;
	else return 0;
}

int main()
{
	int n, m, g, i, j, k;   // n m g 是 班级数 科目数 学生数
	 //i j k 分别是 随性 学生编号 班级编号
	cin >> n;
	cin >> m;
	for (i = 0; i < m; i++) {     //i控制科目
		cin >> credit[i];
	}

	for (k = 1; k <= n; k++) {
		cin >> g;
		for (j = 0; j < g; j++) {      //每个学生
			double sum = 0;
			cin >> c[k].s[j].name;
			for (i = 0; i < m; i++) {    //i控制科目
				cin >> c[k].s[j].grade[i];
				if (c[k].s[j].grade[i] >= 60) {
					c[k].s[j].goal[i] = (c[k].s[j].grade[i] - 50) * 1.0 / 10 * credit[i];
					sum += c[k].s[j].goal[i];
				}
				c[k].s[j].get = sum / 10;
			}
		}
		sort(c[k].s, c[k].s + g, cmp);
	}


	puts("");
	for (k = 1; k <= n; k++) {
		printf("Class %d:\n\n", k);
		for (i = 0; i < j; i++) {
			printf("NO.%d : ", i + 1);
			cout << c[k].s[i].name;
			printf("\n各科成绩 :");
			for (int z = 0; z < m; z++) printf("%-3d ", c[k].s[i].grade[z]);
			printf("\n");
			printf("各科学分: ");
			for (int z = 0; z < m; z++) printf("%-3.2lf ", c[k].s[i].goal[z]);
			printf("\n总绩点： %.2lf\n", c[k].s[i].get);
			printf("\n");
		}
		puts("");
	}
}