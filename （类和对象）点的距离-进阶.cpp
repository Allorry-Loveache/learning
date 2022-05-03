#include<iostream>
using namespace std;
class Point
{
    friend int L1Distance(Point p1, Point p2);
public:
    void move(int x, int y) {
        this->x = x, this->y = y;
    }
private:
    int x;
    int y;
};
class ArrayofPoints
{
    Point* p;
public:
    ArrayofPoints(int nothing = 0) {
        p = new Point[2];
    }
    ArrayofPoints(ArrayofPoints& d) {
        p = new Point[2];
    }
    ~ArrayofPoints() {
        delete[] p;
    }
    Point& element(int n) {
        return p[n];
    }
};
int L1Distance(Point p1, Point p2) {
    return(abs(p1.x - p2.x) + abs(p1.y - p2.y));
}


/* 请在这里填写答案 */
int main()
{
    ArrayofPoints ArrPoints1(2);
    ArrayofPoints ArrPoints2(ArrPoints1);
    //很难理解，根据调试，是先用完element 返回引用，再让引用去做move
    //这个过程不是倒着来的，是顺序的
    ArrPoints1.element(0).move(5, 10);
    ArrPoints1.element(1).move(15, 20);
    cout << "The distance is" << endl;
    cout << L1Distance(ArrPoints1.element(0), ArrPoints1.element(1)) << endl;
    ArrPoints2.element(0).move(0, 0);
    ArrPoints2.element(1).move(10, 20);
    cout << "The distance is" << endl;
    cout << L1Distance(ArrPoints2.element(0), ArrPoints2.element(1)) << endl;
    return 0;
}
