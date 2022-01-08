#include"contact.h"
int main()
{
	person data[1000] = {0,0,0,0,0,};
	int number=0;
	while (1) {
		menu();
		char target[max];
		int n,i,t;
		printf("你想干什么？\n");
		scanf("%d", &n);
		switch (n) {
		case EXIT: printf("拜拜了您嘞\n"); return 0;
		case ADD: 
			operate(number,data); number++; break;
		case DEL:
			printf("输入要删除的姓名：\n");
			scanf("%s", target);
			t = finding(target,data,number);
			if (t == 0) printf("没这个人，傻缺\n");
			else {
				for (i = t; i < number; i++) 
					data[i] = data[i + 1];
				number--;
				printf("删除完成\n");
			}
			break;
		case SEARCH: 
			printf("输入要查找的姓名：\n");
			scanf("%s", target);
			t = finding(target,data,number);
			if (t == 0) printf("没这个人，傻缺\n");
			else {
				printf("%-15s\t%-10s\t%-5s\t%-12s\t%-20s\n", "姓名", "性别", "年龄", "号码", "地址");
				printf("%-15s\t%-10s\t%-5d\t%-12s\t%-20s\n", data[t].name, data[t].sex, data[t].age,
					data[t].phone, data[t].addr);
			}
			break;
		case MODIFY: 
			printf("输入要修改的姓名：\n");
			scanf("%s", target);
			t = finding(target,data,number);
			if (t == 0) printf("没这个人，傻缺\n");
			else {
				printf("接下来开始修改\n");
				operate(t,data);
			}
			break;
		case SORT:
			qsort(data, number, sizeof(data[0]), compar);
			break;
		case PRINT: print(data,number); break;
		}
		if (n == 0) break;
	}
}
