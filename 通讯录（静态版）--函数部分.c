#include"contact.h"
void menu() {
	printf("**********************************\n");
	printf("****  1.add     2. del     *******\n");
	printf("****  3.search  4. modify  *******\n");
	printf("****  5. sort   6.print    *******\n");
	printf("******      0. exit        *******\n");
	printf("**********************************\n");
}
void operate(int t, person* data) {
	printf("输入姓名：\n"); 
	scanf("%s",data[t].name);
	printf("输入性别：\n"); 
	scanf("%s", data[t].sex);
	printf("输入年龄：\n"); 
	scanf("%d", &data[t].age);
	printf("输入电话号码：\n");
	scanf("%s", data[t].phone);
	printf("输入地址：\n");
	scanf("%s", data[t].addr);
	printf("输入完成\n"); 
}
int finding(char *target, person* data, int number) {
	for (int i = 0; i < number; i++) 
		if (strcmp(data[i].name, target)==0) return i;
	return 0;
}
void print(person* data, int number) {
	printf("%-15s\t%-10s\t%-5s\t%-12s\t%-20s\n", "姓名", "性别", "年龄", "号码", "地址");
	for (int i = 0; i < number; i++)
		printf("%-15s\t%-10s\t%-5d\t%-12s\t%-20s\n", data[i].name, data[i].sex, data[i].age,
			data[i].phone, data[i].addr);
}
int compar(const void* e1, const void* e2) {
	return strcmp(((person*)e1)->name, ((person*)e2)->name);
}
