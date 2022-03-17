#include "game.h"
int main()
{
	int a; char board[row][col];
	do {
		menu();
		scanf("%d", &a);
		switch (a) {
		case 1:  printf("请开始你的表演\n"); game(board);
			break;
		case 0:  printf("有多远滚多远\n");
			a = 0;
			break;
		default: printf("我再给你一次机会，给爷好好选\n");
			break;
		}
	} while (a);
}

