#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE   //����Ӧ��loadimage��һЩ����
#undef _UNICODE
#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<stdlib.h>



#define Row 10
#define Col 10
#define Count 15 //������Ŀ
#define SIZE 40   //ͼ�񳤶�
int map[Row][Col];
IMAGE img[12];
int flag = 0;  //�ж���Ӯ
int count = 0;   //�ж�����

void show() {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++)
			printf("%2d ", map[i][j]);
		putchar('\n');
	}
}
void gameinit() {
	srand(time(0));
	int c = 0;
	//����
	for (int i = 0; i < Count;) {
		int x = rand() % Row;
		int y = rand() % Col;
		if (map[x][y] == 0) {
			map[x][y] = -1; c++;
		}
		if (c == Count) break;
	}
	//��������Χ�����֣������Ƕ�����1
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
			if (map[i][j] == -1)
				for (int k = i - 1; k < i + 2; k++)
					for (int l = j - 1; l < j + 2; l++)
						if (k >= 0 && k < Row && l >= 0 && l < Col && map[k][l] != -1)
							map[k][l]++;
	//����ͼƬ
	for (int i = 0; i < 12; i++) {  //����12��ͼƬ
		char filename[100] = "";
		sprintf_s(filename, "./image/%d.jpg", i);
		loadimage(img + i, filename, SIZE, SIZE);
	}
	//΢�ͼ���
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
			map[i][j] += 20;
}

void gameDraw() {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			int x = j * SIZE;    //x���Ӧj�У�y���Ӧi�У�ת��Ϊ����ͼƬ��Ҫ������
			int y = i * SIZE;
			if (map[i][j] >= 0 && map[i][j] <= 8)
				putimage(x, y, img + map[i][j]);//map[i][j]�ܷ���Ķ�Ӧ����ͼƬ�����
			else if (map[i][j] == -1)
				putimage(x, y, img + 9);  //��Ӧ���׵�ͼƬ
			else if (map[i][j] >= 19 && map[i][j] <= 28) //���ܺ�����ͼ
				putimage(x, y, img + 10);
			else if (map[i][j] >= 39)   //����Ҽ����
				putimage(x, y, img + 11);
		}
	}
}
void blank(int row, int col) {
	count++;
	for (int i = row - 1; i < row + 2; i++)
		for (int j = col - 1; j < col + 2; j++)
			if (i >= 0 && i < Row && j >= 0 && j < Col)
				if (map[i][j] >= 21 && map[i][j] <= 28)
					map[i][j] -= 20, count++;
				else if (map[i][j] == 20)
					map[i][j] -= 20, blank(i, j);

}

void loser() {
	if (count == 0) MessageBox(NULL, "��سɺУ�", "", MB_OK);
	else if (flag == 0)  MessageBox(NULL, "�����������ģ�", "", MB_OK);
	else  MessageBox(NULL, "�ҳ����ӱ���", "", MB_OK);
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
			if (map[i][j] >= 19 && map[i][j] <= 28)
				map[i][j] -= 20;
	gameDraw();
	Sleep(5000);
}

void mouse() {
	//�Ȼ�ȡ������Ϣ������Ŀǰ����Ҫ���x,y����
	MOUSEMSG msg = GetMouseMsg();
	int row = msg.y / SIZE;
	int col = msg.x / SIZE;
	//����������˸��ӣ��ʹ�,-=20
	if (msg.uMsg == WM_LBUTTONDOWN) {
		if (map[row][col] >= 19) {
			map[row][col] -= 20;
			if (map[row][col] == 0) {
				blank(row, col);
			}
			else if (map[row][col] == -1) {
				loser();
				return;
			}
			else if (map[row][col] >= 1 && map[row][col] <= 8)
				count++;
			if (count == Row * Col - Count) {
				flag = 1;
				loser();
				return;
			}
		}
	}
	//�Ҽ����б��,+=20
	else if (msg.uMsg == WM_RBUTTONDOWN) {
		//�ų��Ѿ�����ǵ� �� ����Ѿ��㿪�˵�
		if (map[row][col] >= 19 && map[row][col] <= 28)
			map[row][col] += 20;
	}
}

int main()
{
	HWND hwnd = GetForegroundWindow(); 
	ShowWindow(hwnd, SW_HIDE); 

	//���ÿ���̨
	initgraph(SIZE * Row, SIZE * Col, EW_SHOWCONSOLE);
	gameinit();
	show();
	MessageBox(NULL, "Ϊ�����������ʱ�̵��ˣ�ȥ�����꣡", "", MB_OK);
	while (1) {
		gameDraw();
		mouse();
	}
}
