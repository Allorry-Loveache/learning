//代码展示
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
const int NUM = 5;
const string country[] = { "chinese", "japan", "korea", "india", "american" }; //猜的单词

int printMan(int guesses) {
    if (guesses < 6)
        cout << "----------" << endl;
    if (guesses < 5)
        cout << "|-----|---" << endl;
    if (guesses < 4)
        cout << "|-----0---" << endl;
    if (guesses < 3)
        cout << "|----/|\\--" << endl;
    if (guesses < 2)
        cout << "|----/ \\--" << endl;
    if (guesses < 1)
        cout << "|__________" << endl;
}

int main() {
    // 随机数
    srand(time(0));
    string target = country[rand() % NUM];
    int length = target.length();
    string attempt(length, '-');
    int guesses = 6;
    cout << "[" << attempt << "]" << endl;
    while (guesses > 0 && attempt != target) {
        char letter;
        cout << "输入你猜的字母:";
        cin >> letter;
        int loc = target.find(letter);
        if (loc == string::npos) {
            --guesses;
        }
        else {
            attempt[loc] = letter;
            loc = target.find(letter, loc + 1);
            while (loc != string::npos) {
                attempt[loc] = letter;
                loc = target.find(letter, loc + 1);
            }
        }
        system("cls");
        cout << "[" << attempt << "]" << endl;
        printMan(guesses);
    }

    if (guesses > 0) cout << "恭喜你猜对了，游戏胜利" << endl;
    else cout << "小人已经死了... 正确的单词是" << target << endl;
    return 0;
}