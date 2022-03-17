//����չʾ
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
const int NUM = 5;
const string country[] = { "chinese", "japan", "korea", "india", "american" }; //�µĵ���

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
    // �����
    srand(time(0));
    string target = country[rand() % NUM];
    int length = target.length();
    string attempt(length, '-');
    int guesses = 6;
    cout << "[" << attempt << "]" << endl;
    while (guesses > 0 && attempt != target) {
        char letter;
        cout << "������µ���ĸ:";
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

    if (guesses > 0) cout << "��ϲ��¶��ˣ���Ϸʤ��" << endl;
    else cout << "С���Ѿ�����... ��ȷ�ĵ�����" << target << endl;
    return 0;
}