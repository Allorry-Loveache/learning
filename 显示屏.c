
#include<stdio.h>
char a[10][5][4] = {
	"XXX","X.X","X.X","X.X","XXX",//0
	"..X","..X","..X","..X","..X",//1
	"XXX","..X","XXX","X..","XXX",//2
	"XXX","..X","XXX","..X","XXX",//3
	"X.X","X.X","XXX","..X","..X",//4
	"XXX","X..","XXX","..X","XXX",//5
	"XXX","X..","XXX","X.X","XXX",//6
	"XXX","..X","..X","..X","..X",//7
	"XXX","X.X","XXX","X.X","XXX",//8
	"XXX","X.X","XXX","..X","XXX",//9
};
int b[100];
int main()
{
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) 
		scanf("%1d", &b[i]);
	for (j = 0; j < 5; j++) {
		for (i = 0; i < n; i++) {
			printf("%s", a[b[i]][j]);
			if (i != n - 1) printf(".");
		}
		puts(" ");
	}
	return 0;
}
