#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 30
typedef struct person {
	char name[max];
	char sex[max];
	int age;
	char phone[max];
	char addr[max];
}person;
//typedef struct con {
//	person data[1000];
//	int num;
//};
enum c {
	EXIT,  ADD,  DEL,  SEARCH,
	MODIFY,  SORT,  PRINT
};
void menu();
void operate(int t,person*data);
int finding(char *target, person* data, int number);
void print(person* data, int number);
int compar(const void*e1, const void*e2);
