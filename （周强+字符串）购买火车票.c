


#include <stdio.h>
#include <string.h>
int main()
{
	int N, S, m;
	scanf("%d %d", &N, &S);
	char station[51][32];
	int Seat[201];
	for (int i = 0; i < N; i++)
		scanf("%s", station[i]);
	for (int i = 0; i < N - 1; i++)
		Seat[i] = S;  //N-1段座位 
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int ticket, j, k;
		char site1[100], site2[100];
		scanf("%s %s %d", site1, site2, &ticket);
		for (j = 0; strcmp(station[j], site1) != 0; j++);//station[j]=site1 
		for (k = 0; strcmp(station[k], site2) != 0; k++);//station[k]=site2 
		int min = 10000;
		for (int h = j; h < k; h++)
			if (min >= Seat[h])
				min = Seat[h];//找到这一段路程其中座位最少的情况 
		if (min >= ticket)//如果最少的大于等于ticket就能做的下 
		{
			printf("%d YES\n", min);
			for (int h = j; h < k; h++)
				Seat[h] -= ticket;//买下之后每一段都减去票数 
		}
		else
			printf("%d NO\n", min);
	}
}
