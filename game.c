#include "game.h"
void menu() {
	printf("*****************\n");
	printf("**** 1. play ****\n");
	printf("**** 0. exit ****\n");
	printf("*****************\n");
}
void initboard(char board[row][col]) {
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			board[i][j] = ' ';

}
void display(char board[row][col]) {
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) printf("|");
		}
		printf("\n");
		if (i < row - 1)
			for (k = 0; k < col; k++) {
				printf("---");
				if (k < col - 1) printf("|");
			}
		printf("\n");
	}
}
void human(char board[row][col]) {
	while (1) {
		printf("请输入你的坐标:\n");
		int a, b;
		scanf("%d %d", &a, &b);
		if (a <= row && b <= col && a >= 1 && b >= 1 && board[a-1][b-1] == ' ') {
			board[a-1][b-1] = '*'; 
			display(board);  break;
		}
		else printf("无效坐标，没长大脑？\n");
	}
}
void robot(char board[row][col]) {
	srand((unsigned int)time(NULL));
	while (1) {
		a = rand() % row;
		b = rand() % col;
		if (board[a][b] == ' ') {
			board[a][b] = '#';
			printf("你的伞兵对手干的好事:\n");
			display(board);  break;
		}
	}
}
char judgement(char board[row][col]) {
	for (i = 0; i < row; i++) {
		for (j = 0; j < col - 1; j++)
			if (board[i][j] == ' ' || board[i][j] != board[i][j + 1])
				break;
		if (j == col - 1) return board[i][j];
	}
	for (j = 0; j < col; j++) {
		for (i = 0; i < row - 1; i++)
			if (board[i][j] == ' ' || board[i][j] != board[i + 1][j])
				break;
		if (i == row - 1) return board[i][j];
	}
	for (i = 0; i < row-1; i++)
		if (board[i][i] == ' ' || board[i][i] != board[i+1][i + 1])
				break;
		if (i == row - 1) return board[i][i];
	for (i = 0; i < row -1; i++) 
		if (board[i][row-i-1] == ' ' || board[i][row-i-1] != board[i + 1][row-i-2])
			break;
		if (i == row - 1) return board[i][row-i-1];
	int t = 1;
	for (i = 0; i < row; i++) 
		for (j = 0; j < col; j++)
			if (board[i][j] == ' ') {
				t = 0; break;
			}
	if (t) return '$';
	return 0;
}
int s (a) {
	switch(a){
    case '$': printf("平局"); return 1; break;
    case '#': printf("Loser!!!"); return 1; break;
    case '*': printf("敢不敢再来？"); return 1; break;
    default: return 0;  break;
}
}
void game(char board[row][col]) {
	initboard(board);
	display(board);
	while (1) {
		human(board);
		if (s(judgement(board))) break;
		robot(board);
		if (s(judgement(board))) break;
		
	}
}
