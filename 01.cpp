#include<iostream>
using namespace std;
#include<deque>

//�⺯��stack�ĵײ�ṹΪdeque
//ģ�����: T--��������    Container--�ײ����ݽṹ
template<class T, class Container = deque<T>>
class stack
{
public:
	stack()
		:con()
	{}

	void push(const T& x)
	{
		con.push_back(x);
	}
	void pop()
	{
		con.pop_back();
	}
	size_t size()
	{
		return con.size();
	}
	T& top()
	{
		return con.back();
	}
	const T& top()const
	{
		return con.back();
	}
	bool empty()
	{
		return con.empty();
	}
private:
	Container con;
};

void testStack()
{
	stack<int> s;
	if (s.empty())
	{
		cout << s.size() << endl;
	}
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	cout << s.size() << endl;

	cout << s.top() << endl;

	s.pop();
	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;

}

int main()
{
	testStack();
	return 0;
}
