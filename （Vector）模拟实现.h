#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;
namespace allorry {
	template <class T>
	class vector {
	public:
		typedef T* iterator;
		void swap(vector<T>& x) {
			::swap(_start, x._start);
			::swap(_end, x._end);
			::swap(_finish, x._finish);
		}
		iterator begin() {
			return _start;
		}
		iterator end() {
			return _finish;
		}
		vector() :_start(nullptr), _finish(nullptr), _end(nullptr) {}
		vector(size_t x) :_start(nullptr), _finish(nullptr), _end(nullptr) {
			resize(x);
		}
		vector(iterator l, iterator r) :_start(nullptr), _finish(nullptr), _end(nullptr) {
			size_t sz = r - l;
			T* t = new T[sz];
			memcpy(t, l, sz*sizeof(T));
			_start = t, _end = _finish = _start + sz;
		}
		vector(vector<T>& x) :_start(nullptr), _finish(nullptr), _end(nullptr) {
			vector<T> t(x.begin(), x.end());
			swap(t);
		}
		~vector() {
			if (_start) delete[] _start;
			_start = _finish = _end = nullptr;
		}
		size_t size() {
			return _finish - _start;
		}
		size_t capacity() {
			return _end - _start;
		}
		void reserve(size_t n) {
			if (n <= capacity()) return;
			
			T* t = new T[n];
			size_t sz = size(); //先保留好原空间的大小
			if (_start) { //原空间有东西的话就拷过去，注意此处摧毁空间
				memcpy(t, _start, sz * sizeof(T));
				delete[] _start;
			}
			//以上运用memcpy只适用于浅拷贝，以下通用
			/*for (size_t i = 0; i < sz; i++) {
				t[i] = _start[i];
			}*/
			_start = t;
			//_finish = _start + size(); 错误写法，迭代器可能失效
			_finish = _start + sz;
			_end = _start + n;
		}
		void push_back(const T& x) {
			if (_finish == _end) {
				size_t newcapa = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapa);
			}
			*_finish = x;
			_finish++;
		}
		void resize(size_t n, T val = T()) {  //新的容量 与 填补值
			if (n < size()) {
				_finish = _start + n;
			}
			else {
				if (n > capacity()) {
					reserve(n);
				}
				while (_finish < _start + n) {
					*_finish++ = val;
				}
			}
		}
		void pop_back() {
			assert(size());
			--_finish;
		}
		void insert(iterator pos, const T& x) {
			size_t len = pos - _start;
			if (_finish == _end) {
				size_t newcapa = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcapa);
			}
			pos = _start + len;//防止pos因为扩容失效
			iterator tail = _finish - 1;
			while (tail >= pos) {
				*(tail + 1) = *tail;
				tail--;
			}
			*pos = x;
			_finish++;
			/*面试问：这里的pos是形参，而原先的实参已经因为扩容失效了，
			为了避免这个问题，你该怎么做？*/
			//改为：iterator& pos,  末尾添加：pos++;
		}
		iterator erase(iterator pos) {
			iterator cur = pos;
			while (cur != _finish) {
				*cur = *(cur + 1);
				cur++;
			}
			_finish--;
			return pos;
		}
		T& operator [](size_t i) {
			assert(i < size());
			return _start[i];
		}
		vector<T>& operator =(vector<T> t) {
			swap(t);
			return *this;
		}
		friend ostream& operator<<(ostream& out,vector<T>& x) {
			for (int i = 0; i < x.size(); i++) {
				out << x[i] << ' ';
			}
			out << endl;
			return out;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end;
	};

}

int main()
{
	allorry::vector<int> a(10);
	for (int i = 0; i < 10; ++i)  a[i] = i * i;
	allorry::vector<int> b(20);
	b = a;
	cout << a;
	cout << b;
}
