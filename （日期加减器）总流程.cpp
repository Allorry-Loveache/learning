#include"Date.h"
int main()
{
	printf("哎哟我的妈耶改了一下午的bug人麻了\n");
	printf("温馨提示：\n日期输入格式为 x y z，输入合法日期，你要是搞事情，出了Bug不关我事\n");
	system("pause");
	system("cls");

	Date d1;
	while (1) {
		d1.menu();
		printf("请输入你的操作\n");
		int n;
		scanf("%d", &n);
		if (n <= 0 || n > 5) {
			printf("您是不是有什么大病？\n");
			system("pause");
			system("cls");
			continue;
		}

		if (n == 5) {
			return 0;
		}

		if (n == 1) {
			printf("请输入你想输入的\"合理\"日期\n");
			cin >> d1;
		}
		
		if (n == 2) {
			int x;
			printf("输入你要加上的天数,爱多大多大\n");
			scanf("%d", &x);
			d1 += x;
			cout << d1;
		}

		if (n == 3) {
			int y;
			printf("输入你要减去的天数，爱多大多大\n");
			scanf("%d", &y);
			d1 -= y;
			cout << d1;
		}

		if (n == 4) {
			int x, y, z;
			printf("输入你要与之比较的日期\n");
			scanf("%d %d %d", &x, &y, &z);
			int sum=0;
			Date d2(d1);
			if (d2.cmp(x, y, z)==1) {
				while (1) {
					d2 += 1; sum--;
					if (d2.judge(x, y, z)) {
						printf("%d\n", sum);
						break;
					}
				}
			}
			else if (d2.cmp(x, y, z) == 2) {
				printf("0\n"); 
			}
			else {
				while (1) {
					d2 -= 1; sum++;
					if (d2.judge(x, y, z)) {
						printf("%d\n", sum);
						break;
					}
				}
			}
		}
			system("pause");
			system("cls");
	}
}
