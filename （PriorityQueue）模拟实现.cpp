#include"PriorityQueue.h"

int main() {
	Allorry::priority_queue<int> q;
	q.push(10);
	q.push(1);
	q.push(3);
	q.push(20);
	q.push(2);
	q.push(124);
	q.push(31);
	q.push(91);
	q.push(1);
	q.push(30);
	q.push(20);
	while (!q.empty()) {
		cout << q.top() << ' ';
		q.pop();
	}
}
