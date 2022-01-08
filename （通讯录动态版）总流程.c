#include"contact.h"
int main()
{
	con contact;
	initialize(&contact);
	while (1) {
		menu();
		char target[max];
		int n,i,t;
		printf("你想干什么？\n");
		scanf("%d", &n);
		switch (n) {
		case EXIT: {
			printf("拜拜了您嘞\n");
			free(contact.data);
			return 0;
		}
		case ADD: 
			if (contact.number == contact.capacity) {
				printf("存储空间不足，请扩容\n");
				break;
			}
			operate(contact.number,&contact); contact.number++; break;
		case DEL:
			printf("输入要删除的姓名：\n");
			scanf("%s", target);
			t = finding(target,&contact);
			if (t == 0) printf("没这个人，傻缺\n");
			else {
				for (i = t; i < contact.number - 1; i++) 
					contact.data[i] = contact.data[i + 1];
				contact.number--;
				printf("删除完成\n");
			}
			break;
		case SEARCH: 
			printf("输入要查找的姓名：\n");
			scanf("%s", target);
			t = finding(target,&contact);
			if (t == 0) printf("没这个人，傻缺\n");
			else {
				printf("%-15s\t%-10s\t%-5s\t%-12s\t%-20s\n", "姓名", "性别", "年龄", "号码", "地址");
				printf("%-15s\t%-10s\t%-5d\t%-12s\t%-20s\n", contact.data[t].name, contact.data[t].sex, 
					contact.data[t].age, contact.data[t].phone, contact.data[t].addr);
			}
			break;
		case MODIFY: 
			printf("输入要修改的姓名：\n");
			scanf("%s", target);
			t = finding(target,&contact);
			if (t == 0) printf("没这个人，傻缺\n");
			else {
				printf("接下来开始修改\n");
				operate(t,&contact);
			}
			break;
		case SORT:
			qsort(contact.data, contact.number, sizeof(person), compar);
			break;
		case PRINT: print(&contact); break;
		case ADDCAP: addcap(&contact); printf("扩容完成\n");  contact.capacity+=addsize;  break;
		}
		if (n == 0) break;
	}
}
