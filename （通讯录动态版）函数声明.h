#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define max 30
#define addsize 3
typedef struct person {
	char name[max];
	char sex[max];
	int age;
	char phone[max];
	char addr[max];
}person;
typedef struct con {
	person *data;
	int number;
	int capacity;
}con;
enum c {
	EXIT,  ADD,  DEL,  SEARCH,
	MODIFY,  SORT,  PRINT, ADDCAP
};
void menu();
void initialize(con *contact);
void operate(int t,con*contact);
int finding(char *target, con*contact);
void print(con*contact);
int compar(const void*e1, const void*e2);
void addcap(con*contact);

