#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
#define speed 10
int index3;   //����ģʽ
int score;   //�÷�
int die = 3; //����
char s[5];   //�ַ�����ʽ�÷�
char d[5];   //�ַ�����ʽ����


enum {
	UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77
};
void BGM() {
	mciSendString("open  ./one-b-boy.mp3  alias bgm", 0, 0, 0);
	mciSendString("play  bgm  repeat", 0, 0, 0);
}
IMAGE bk;
IMAGE Bullet[2];
IMAGE Him[2];
IMAGE Her[2];
IMAGE Me[2];

struct bull {  //�ӵ�����
	int x, y;
	int flag;
}myb[100], herbull[3][10];  //�ҵ��ӵ���3����ֵ��ӵ�

struct plane { //����������
	int x, y;
	int flag;  //�Ƿ���
}my, him[6], her[3];  //�ң�һ��С�ִ��

void menu() {
	setbkcolor(WHITE);
	settextcolor(BLUE);
	cleardevice();
	settextstyle(40, 20, "����");
	outtextxy(200, 270, "wsad�ƶ����ո����");
	outtextxy(200, 470, "����ƶ���������");
	while (1) {
		MOUSEMSG msg = GetMouseMsg();
		int x = msg.x, y = msg.y;
		if (x >= 200 && x <= 560 && y >= 270 && y <= 310) {
			setlinecolor(RED);
			rectangle(190, 260, 560, 320);
		}
		else {
			setlinecolor(WHITE);
			rectangle(190, 260, 560, 320);
		}
		if (x >= 200 && x <= 560 && y >= 470 && y <= 510) {
			setlinecolor(RED);
			rectangle(190, 460, 560, 520);
		}
		else {
			setlinecolor(WHITE);
			rectangle(190, 460, 560, 520);
		}
		if (msg.uMsg == WM_LBUTTONDOWN) {
			if (x >= 200 && x <= 560 && y >= 270 && y <= 310) {
				index3 = 1; break;
			}
			if (x >= 200 && x <= 560 && y >= 470 && y <= 510) {
				index3 = 2; break;
			}
		}
	}
}

void load() {
	loadimage(&bk, "./image/bk.jpg", 591, 864);
	loadimage(Bullet, "./image/bullet1.jpg", 19, 24);
	loadimage(Bullet + 1, "./image/bullet2.jpg", 19, 24);
	loadimage(Him, "./image/enemy_1.jpg", 52, 39);
	loadimage(Him + 1, "./image/enemy_2.jpg", 52, 39);
	loadimage(Her, "./image/enemyPlane1.jpg", 104, 148);
	loadimage(Her + 1, "./image/enemyPlane2.jpg", 104, 148);
	loadimage(Me, "./image/planeNormal_1.jpg", 117, 120);
	loadimage(Me + 1, "./image/planeNormal_2.jpg", 117, 120);
}

void initGame() {
	initgraph(800, 864);
	load();
	my.x = 240, my.y = 700;
}

void mymove2() {  //��귽ʽ
	MOUSEMSG msg = GetMouseMsg();
	my.x = msg.x, my.y = msg.y;
	static int i = 0;
	if (msg.uMsg==WM_LBUTTONDOWN) {
		if (myb[i].flag == 0) {
			myb[i].x = my.x + 50, myb[i].y = my.y;
			myb[i].flag = 1;
			i++;
			i %= 100;
		}
	}
}

void mymove() {  
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) //�����д��ĸ
		if (my.y - speed >= 0)  my.y -= speed;
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) 
		if (my.y + speed <= 750)  my.y += speed;
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) 
		if (my.x - speed >= 0 )  my.x -= speed;
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) 
		if (my.x + speed <= 500)  my.x += speed;
}

void initbull() {
	//�ӵ���һ��ʱ������ʼ��
	static DWORD t1 = 0, t2 = 0, i = 0;
	if (GetAsyncKeyState(VK_SPACE) && t1 - t2 > 100) {
		if (myb[i].flag == 0) {
			myb[i].x = my.x + 50, myb[i].y = my.y;
			myb[i].flag = 1;
			i++;
			i %= 100;
		}
		t2 = t1;
	}
	t1 = GetTickCount();
}

void bullmove() {
	initbull();
	for (int i = 0; i < 100; i++) {
		if (myb[i].flag)
			myb[i].y -= 10;
	}
}

void himmove() {  //���ݳ�ʼ��
	for (int i = 0; i < 6; i++) {
		if (him[i].flag == 0) {
			him[i].x = rand() % 550;
			him[i].y = 0 - rand() % 200;
			him[i].flag = 1;
		}
		him[i].y += 3;
	}
}

void hermove() {  //���ݳ�ʼ��
	for (int i = 0; i < 3; i++) {
		if (her[i].flag == 0) {
			her[i].x = rand() % 500;
			her[i].y = 0 - rand() % 200;
			her[i].flag = 5;
		}
		her[i].y += 1;
	}
}

void initbull_her() {
	static DWORD t1 = 0, t2 = 0, i[3] = { 0 };
	if (t1 - t2 > 1000) {
		for (int j = 0; j < 3; j++) {
			if (herbull[j][i[j]].flag == 0) {
				herbull[j][i[j]].x = her[j].x + 50;
				herbull[j][i[j]].y = her[j].y + 75;
				herbull[j][i[j]].flag = 1;
				i[j]++;
				i[j] %= 10;
			}
		}
		t2 = t1;
	}
	t1 = GetTickCount();
}

void bullmove_her() {
	initbull_her();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			if (herbull[i][j].flag == 1) {
				if(her[i].x>=400) herbull[i][j].x -= 3;
				else if (her[i].x <= 200) herbull[i][j].x += 3;
				herbull[i][j].y += 4;
			}
		}
	}
}

void himdie() {   //�����ӵ���ʧ
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 6; j++) {
			if (myb[i].x >= him[j].x && myb[i].x <= him[j].x + 52 &&
				myb[i].y <= him[j].y)
			{   //���˾�ȫ����ʼ���������꣬��Ȼ��bug
				him[j].flag = 0, him[j].x = 1200, him[j].y = 1200;
				myb[i].flag = 0, myb[i].x = 1200, myb[i].y = 1200;
				score += 10;
			}

			if (him[j].y >= 860) {  //���˳���
				him[j].flag = 0, him[j].x = 1200, him[j].y = 1200;
			}
		}
		if (myb[i].y <= 0)  //�ӵ�����
			myb[i].flag = 0, myb[i].x = 1200, myb[i].y = 1200;
	}
}

void herdie() {   //�����ӵ���ʧ
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 3; j++) {
			if (myb[i].x >= her[j].x && myb[i].x <= her[j].x + 104 &&
				myb[i].y <= her[j].y + 100)
			{   //���˾�ȫ����ʼ���������꣬��Ȼ��bug
				her[j].flag--;
				myb[i].flag=0, myb[i].x = 1300, myb[i].y = 1300;
				if (her[j].flag == 0) {
					her[j].x = 1300, her[j].y = 1300;
					score += 50;
				}
			}

			if (her[j].y >= 860) {  //���˳���
				her[j].flag = 0, her[j].x = 1300, her[j].y = 1300;
			}
		}
		if (myb[i].y <= 0) {   //�ӵ�����
			myb[i].flag = 0, myb[i].x = 1300, myb[i].y = 1300;
		}
	}
}


void medie() {  //���ݵз��ӵ���ʧ
	for (int i = 0; i < 6; i++) {  //��С�ִ�
		if (him[i].y - 20 >= my.y && him[i].y <= my.y + 80 &&
			him[i].x + 30 >= my.x && him[i].x <= my.x + 30)
			die = 0;
	}
	for (int i = 0; i < 3; i++) {  //����ִ�
		if (her[i].y + 100 >= my.y && her[i].y <= my.y + 80 &&
			her[i].x + 50 >= my.x && her[i].x <= my.x + 30)
			die = 0;
	}
	for (int i = 0; i < 3; i++) {  //���ӵ���
		for (int j = 0; j < 10; j++) {
			if (herbull[i][j].y >= my.y && herbull[i][j].y <= my.y + 50 &&
				herbull[i][j].x >= my.x && herbull[i][j].x <= my.x + 40)
			{
				die--;
				herbull[i][j].flag = 0, herbull[i][j].x = 1400, herbull[i][j].y = 1400;
			}
		}
	}
	for (int i = 0; i < 3; i++) {  //�з��ӵ�����
		for (int j = 0; j < 10; j++) {
			if (herbull[i][j].x <= 0 || herbull[i][j].x >= 580 ||
				herbull[i][j].y <= 0 || herbull[i][j].y >= 860)
			{
				herbull[i][j].flag = 0, herbull[i][j].x = 1400, herbull[i][j].y = 1400;
			}
		}
	}
	if (die==0) {
		settextcolor(RED);
		setbkmode(TRANSPARENT);  //ȥ�����ֱ���
		settextstyle(200, 200, "����");
		outtextxy(100, 350, "��");
		FlushBatchDraw();
		getchar();
	}
}

void drawALL() {
	//�����Լ�
	putimage(my.x, my.y, Me, NOTSRCERASE);
	putimage(my.x, my.y, Me + 1, SRCINVERT);
	for (int i = 0; i < 6; i++) {  //����С����
		if (him[i].flag) {
			putimage(him[i].x, him[i].y, Him, NOTSRCERASE);
			putimage(him[i].x, him[i].y, Him + 1, SRCINVERT);
		}
	}
	for (int i = 0; i < 3; i++) {  //���������
		if (her[i].flag) {
			putimage(her[i].x, her[i].y, Her, NOTSRCERASE);
			putimage(her[i].x, her[i].y, Her + 1, SRCINVERT);
		}
	}
	for (int i = 0; i < 100; i++) {//�����ҵ��ӵ�
		if (myb[i].flag) {
			putimage(myb[i].x, myb[i].y, Bullet, NOTSRCERASE);
			putimage(myb[i].x, myb[i].y, Bullet + 1, SRCINVERT);
		}
	}
	for (int i = 0; i < 3; i++) {//���������ӵ�
		for (int j = 0; j < 10; j++) {
			if (herbull[i][j].flag && her[i].flag) {
				putimage(herbull[i][j].x, herbull[i][j].y, Bullet, NOTSRCERASE);
				putimage(herbull[i][j].x, herbull[i][j].y, Bullet + 1, SRCINVERT);
			}
		}
	}
	settextcolor(GREEN);
	sprintf(s, "%d", score);
	sprintf(d, "%d", die);
	settextstyle(20, 10, "����");
	outtextxy(650, 10, "�÷�:");
	outtextxy(650, 35, s);
	outtextxy(650, 60, "����:");
	outtextxy(650, 85, d);
}

void drawGame() {
	while (1) {
		BeginBatchDraw();
		putimage(0, 0, &bk);
		//����������ƶ�
		if (index3 == 1) mymove();
		else mymove2();
		himmove(); bullmove(); hermove(); bullmove_her();
		herdie(); himdie(); medie();//������û�����˵�
		drawALL();
		EndBatchDraw();
		Sleep(10);
	}
}

void game333()
{
	srand((unsigned int)time(NULL));
	initGame();
	BGM();
	menu();
	drawGame();
	getchar();
}











void BGM222() {
	//alias ���� 
	mciSendString("open  ./��-����.mp3   alias bgm", NULL, 0, NULL);
	mciSendString("play  bgm    repeat", NULL, 0, NULL);
}
#define MAX 500    //�ߵ���󳤶�
#define LENGTH 10   //������ͷ�ĳ���
int index;   //ģʽѡ��
int grade;  //��ҷ���
char Grade[5];  //�������ַ�����ʽ��ʾ��ҷ���

//enum Orient {   //��ʾ�ߵķ���
//	UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77
//};

struct Snake {
	int size;    //����
	int orient;     //����
	POINT coor[MAX];//����
}snake;

struct Food {
	int flag;   //ʳ���Ƿ����
	int x, y;
}food;

void initGame222() {
	//���ô��ڱ����� �����ɫ�� �߿���ɫ�� �ı���ɫ
	initgraph(650, 480);
	BGM222();
	setbkcolor(RGB(255, 255, 255));
	setfillcolor(GREEN);
	setlinecolor(BLACK);
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);  //ȥ�����ֱ���
	cleardevice();
	//���ò�������ʼѡ�����
	fillrectangle(100, 170, 200, 270);
	fillrectangle(300, 170, 400, 270);
	fillrectangle(500, 170, 600, 270);
	fillrectangle(250, 300, 480, 400);
	outtextxy(120, 210, "����һ��");
	outtextxy(320, 210, "��תģʽ");
	outtextxy(520, 210, "�������");
	outtextxy(330, 350, "���Ƶ�Ѫѹ");
	while (1) {
		MOUSEMSG msg = GetMouseMsg();
		int x = msg.x, y = msg.y;
		if (x >= 100 && x <= 200 && y >= 170 && y <= 270) {
			setlinecolor(RED);
			rectangle(90, 160, 210, 280);
		}
		else {
			setlinecolor(WHITE);
			rectangle(90, 160, 210, 280);
		}
		if (x >= 300 && x <= 400 && y >= 170 && y <= 270) {
			setlinecolor(RED);
			rectangle(290, 160, 410, 280);
		}
		else {
			setlinecolor(WHITE);
			rectangle(290, 160, 410, 280);
		}
		if (x >= 500 && x <= 600 && y >= 170 && y <= 270) {
			setlinecolor(RED);
			rectangle(490, 160, 610, 280);
		}
		else {
			setlinecolor(WHITE);
			rectangle(490, 160, 610, 280);
		}
		if (x >= 250 && x <= 480 && y >= 300 && y <= 400) {
			setlinecolor(RED);
			rectangle(240, 290, 490, 410);
		}
		else {
			setlinecolor(WHITE);
			rectangle(240, 290, 490, 410);
		}
		if (msg.uMsg == WM_LBUTTONDOWN) {
			if (x >= 100 && x <= 200 && y >= 170 && y <= 270) index = 30;
			else if (x >= 300 && x <= 400 && y >= 170 && y <= 270) index = 50;
			else if (x >= 500 && x <= 600 && y >= 170 && y <= 270) index = 35;
			else if (x >= 250 && x <= 480 && y >= 300 && y <= 400) index = 20;
			else continue;
			cleardevice();
			break;
		}
	}

	//������
	snake.size = 3;
	snake.orient = RIGHT;
	snake.coor[0].x = 40, snake.coor[0].y = 40;
}

void drawGame222() {
	BeginBatchDraw();   //��������
	//������
	if (index == 35) {    //�������ɫ
		int x = rand() % 255, y = rand() % 255, z = rand() % 255;
		setfillcolor(RGB(x, y, z));
	}
	for (int i = 0; i < snake.size; i++) {
		fillrectangle(snake.coor[i].x, snake.coor[i].y,
			snake.coor[i].x + LENGTH, snake.coor[i].y + LENGTH);
	}
	//�������
	sprintf(Grade, "%d", grade);
	outtextxy(550, 0, "��ķ���:");
	outtextxy(580, 20, Grade);

	EndBatchDraw();
}


void move() {
	for (int i = snake.size - 1; i > 0; i--) {
		snake.coor[i] = snake.coor[i - 1];
	}

	if (snake.orient == UP)    snake.coor[0].y -= LENGTH;
	else if (snake.orient == DOWN)  snake.coor[0].y += LENGTH;
	else if (snake.orient == LEFT) snake.coor[0].x -= LENGTH;
	else if (snake.orient == RIGHT) snake.coor[0].x += LENGTH;
}

void keyControl1() {    //���̲���
	switch (_getch()) {
	case UP:
		if (snake.orient != DOWN)
			snake.orient = UP; break;
	case DOWN:
		if (snake.orient != UP)
			snake.orient = DOWN; break;
	case LEFT:
		if (snake.orient != RIGHT)
			snake.orient = LEFT; break;
	case RIGHT:
		if (snake.orient != LEFT)
			snake.orient = RIGHT; break;
	default: break;
	}
}

void keyControl2() {
	switch (_getch()) {
	case UP:
		if (snake.orient != UP)
			snake.orient = DOWN; break;
	case DOWN:
		if (snake.orient != DOWN)
			snake.orient = UP; break;
	case LEFT:
		if (snake.orient != LEFT)
			snake.orient = RIGHT; break;
	case RIGHT:
		if (snake.orient != RIGHT)
			snake.orient = LEFT; break;
	default: break;
	}
}

void initFood() {
	food.x = rand() % 65 * 10;  //��֤������640���ڣ�����ȫΪ10�ı���
	food.y = rand() % 48 * 10;
	if (food.x == 0 || food.x == 640) food.x = 100;
	if (food.y == 0 || food.y == 470) food.y = 100;
	food.flag = 1;   //ʳ�����
}

void drawFood1() {
	fillrectangle(food.x, food.y, food.x + 20, food.y + 20);
}

void drawFood2() {
	fillrectangle(food.x, food.y, food.x + 10, food.y + 10);
}

void eat1() {
	if (snake.coor[0].x == food.x && snake.coor[0].y == food.y ||
		snake.coor[0].x == food.x + 10 && snake.coor[0].y == food.y ||
		snake.coor[0].x == food.x && snake.coor[0].y == food.y + 10 ||
		snake.coor[0].x == food.x + 10 && snake.coor[0].y == food.y + 10) {

		snake.size++; grade += 10; food.flag = 0;
	}
}

void eat2() {
	if (snake.coor[0].x == food.x && snake.coor[0].y == food.y)
	{
		snake.size++; grade += 10; food.flag = 0;
	}
}

int die222() {
	if (snake.coor[0].x == 0 || snake.coor[0].y == 0 ||
		snake.coor[0].x == 640 || snake.coor[0].y == 470) {
		outtextxy(200, 200, "��ײ���ˡ��ʵ۵���ǽ��");
		MessageBox(NULL, "����?", "", MB_OK);
		system("pause");
		return 1;
	}
	for (int i = 1; i < snake.size; i++) {
		if (snake.coor[0].x == snake.coor[i].x && snake.coor[0].y == snake.coor[i].y) {
			outtextxy(200, 200, "�� �� �� �� ��");
			MessageBox(NULL, "�� �� �� �� ��", "", MB_OK);
			system("pause");
			return 1;
		}
	}
	return 0;
}


void game222()
{
	srand((unsigned int)time(NULL));
	initGame222();
	while (1) {
		cleardevice();   //����
		if (food.flag == 0)  initFood(), food.flag = 1; //ʳ��û�˾ͳ�ʼ��
		if (index == 20) drawFood2();      //����ʳ��
		else drawFood1();
		drawGame222();      //�����ߺͻ���
		move();          //���ƶ�
		if (die222()) break;     //�ж���Ϸ����
		if (index == 20) eat2();           //���꣬�����Բ���
		else eat1();
		if (_kbhit()) {  //������������룬׼���ķ���
			if (index == 30 || index == 35 || index == 20) keyControl1();
			else keyControl2();
		}
		else if (index != 20)Sleep(index);    //�ȴ�ʱ��

		if (index == 20) Sleep(13);  //ǿ���ӳ�
	}
	getchar();
	closegraph();
}








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

void game111()
{
	//���ÿ���̨
	initgraph(SIZE * Row, SIZE * Col);
	gameinit();
	show();
	MessageBox(NULL, "Ϊ�����������ʱ�̵��ˣ�ȥ�����꣡", "", MB_OK);
	while (1) {
		gameDraw();
		mouse();
	}
}









int main()
{
	int choice = 0;
	initgraph(600,600);
	setbkcolor(RGB(255, 255, 255));
	setfillcolor(YELLOW);
	setlinecolor(BLACK);
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);  //ȥ�����ֱ���
	cleardevice();
	fillrectangle(100, 100, 250, 200);
	fillrectangle(350, 100, 500, 200);
	fillrectangle(100, 300, 250, 400);
	fillrectangle(350, 300, 500, 400);
	outtextxy(150, 140, "����");
	outtextxy(400, 140, "̰����");
	outtextxy(150, 340, "�һ���ս");
	outtextxy(400, 340, "��������");
	while (1) {
		MOUSEMSG msg = GetMouseMsg();
		int x = msg.x, y = msg.y;
		if (x >= 90 && x <= 260 && y >= 90 && y <= 210) {
			setlinecolor(RED);
			rectangle(90, 90, 260, 210);
		}
		else {
			setlinecolor(WHITE);
			rectangle(90, 90, 260, 210);
		}
		if (x >= 340 && x <= 510 && y >= 90 && y <= 210) {
			setlinecolor(RED);
			rectangle(340, 90, 510, 210);
		}
		else {
			setlinecolor(WHITE);
			rectangle(340, 510, 90, 210);
		}
		if (x >= 90 && x <= 260 && y >= 290 && y <= 410) {
			setlinecolor(RED);
			rectangle(90, 290, 260, 410);
		}
		else {
			setlinecolor(WHITE);
			rectangle(90, 290, 260, 410);
		}
		if (x >= 340 && x <= 510 && y >= 290 && y <= 410) {
			setlinecolor(RED);
			rectangle(340, 290, 510, 410);
		}
		else {
			setlinecolor(WHITE);
			rectangle(340, 290, 510, 410);
		}
		if (msg.uMsg == WM_LBUTTONDOWN) {
			if (x >= 90 && x <= 260 && y >= 90 && y <= 210) game111();
			if (x >= 340 && x <= 510 && y >= 90 && y <= 210) game222();
			if (x >= 90 && x <= 260 && y >= 290 && y <= 410) game333();
			if (x >= 340 && x <= 510 && y >= 290 && y <= 410) break;
			cleardevice();
		}
	}
}


