#include "game.h"
int main()
{
	int a; char board[row][col];
	do {
		menu();
		scanf("%d", &a);
		switch (a) {
		case 1:  printf("�뿪ʼ��ı���\n"); game(board);
			break;
		case 0:  printf("�ж�Զ����Զ\n");
			a = 0;
			break;
		default: printf("���ٸ���һ�λ��ᣬ��ү�ú�ѡ\n");
			break;
		}
	} while (a);
}

