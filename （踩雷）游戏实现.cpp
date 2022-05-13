#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE   //用来应付loadimage的一些错误
#undef _UNICODE
#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<stdlib.h>



#define Row 10
#define Col 10
#define Count 15 //埋雷数目
#define SIZE 40   //图像长度
int map[Row][Col];
IMAGE img[12];
int flag = 0;  //判断输赢
int count = 0;   //判断依据

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
	//埋雷
	for (int i = 0; i < Count;) {
		int x = rand() % Row;
		int y = rand() % Col;
		if (map[x][y] == 0) {
			map[x][y] = -1; c++;
		}
		if (c == Count) break;
	}
	//处理雷周围的数字，让他们都加上1
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
			if (map[i][j] == -1)
				for (int k = i - 1; k < i + 2; k++)
					for (int l = j - 1; l < j + 2; l++)
						if (k >= 0 && k < Row && l >= 0 && l < Col && map[k][l] != -1)
							map[k][l]++;
	//加载图片
	for (int i = 0; i < 12; i++) {  //加载12张图片
		char filename[100] = "";
		sprintf_s(filename, "./image/%d.jpg", i);
		loadimage(img + i, filename, SIZE, SIZE);
	}
	//微型加密
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
			map[i][j] += 20;
}

void gameDraw() {
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			int x = j * SIZE;    //x轴对应j列，y轴对应i行，转换为加载图片需要的坐标
			int y = i * SIZE;
			if (map[i][j] >= 0 && map[i][j] <= 8)
				putimage(x, y, img + map[i][j]);//map[i][j]很方便的对应我们图片的序号
			else if (map[i][j] == -1)
				putimage(x, y, img + 9);  //对应地雷的图片
			else if (map[i][j] >= 19 && map[i][j] <= 28) //加密后，遮罩图
				putimage(x, y, img + 10);
			else if (map[i][j] >= 39)   //配合右键标记
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
	if (count == 0) MessageBox(NULL, "落地成盒！", "", MB_OK);
	else if (flag == 0)  MessageBox(NULL, "好死，开香槟！", "", MB_OK);
	else  MessageBox(NULL, "我超，逃兵！", "", MB_OK);
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
			if (map[i][j] >= 19 && map[i][j] <= 28)
				map[i][j] -= 20;
	gameDraw();
	Sleep(5000);
}

void mouse() {
	//先获取鼠标的消息，我们目前最需要相对x,y坐标
	MOUSEMSG msg = GetMouseMsg();
	int row = msg.y / SIZE;
	int col = msg.x / SIZE;
	//如果左键点击了格子，就打开,-=20
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
	//右键进行标记,+=20
	else if (msg.uMsg == WM_RBUTTONDOWN) {
		//排除已经被标记的 和 左键已经点开了的
		if (map[row][col] >= 19 && map[row][col] <= 28)
			map[row][col] += 20;
	}
}

int main()
{
	HWND hwnd = GetForegroundWindow(); 
	ShowWindow(hwnd, SW_HIDE); 

	//设置控制台
	initgraph(SIZE * Row, SIZE * Col, EW_SHOWCONSOLE);
	gameinit();
	show();
	MessageBox(NULL, "为祖国“献身”的时刻到了，去吧少年！", "", MB_OK);
	while (1) {
		gameDraw();
		mouse();
	}
}
