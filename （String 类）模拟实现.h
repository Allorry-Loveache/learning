#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include<algorithm>
using namespace std;


namespace allorry {

	class string {
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		typedef char* iterator;
		iterator begin() const{
			return _str;
		}
		iterator end() const{
			return _str + _size;
		}
		void swap(string& s) {
			::swap(_str, s._str);
			::swap(_capacity, s._capacity);
			::swap(_size, s._size);
		}
		string(const char* t="") {
			_capacity = _size = strlen(t);
			_str = new char[_size + 1];
			strcpy(_str, t);
		}
		string(const string& s) :_str(nullptr) {
			string t(s._str);
			swap(t);
		}
		~string() {
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
		size_t size() const{
			return _size;
		}
		size_t capacity() const{
			return _capacity;
		}
		void reserve(size_t n) {
			n = n == 0 ? 1 : n;
			if (n <= _capacity) return;

			char* t = new char[n + 1];
			strcpy(t, _str);
			delete[] _str; _str = t;
			_capacity = n;
		}
		void resize(size_t n, char ch = '\0') {
			assert(n >= 0);
			if (n < _size) return;   //别缩小了，不好玩
			else {
				if (n > _capacity) reserve(n);
				for (int i = _size; i < n; i++) 
					_str[i] = ch;
				_size = n;
				_str[n] = '\0';
			}
		}
		void insert(size_t pos, const char* s) {
			assert(pos <= _size);
			size_t len = strlen(s);
			if (len + _size > _capacity) reserve(len + _size);

			char* tail = _str + _size;
			while (tail != _str + pos) {
				*(tail + len) = *tail;
				tail--;
			}
			strncpy(_str + pos, s, len);
			_size += len;
		}
		void check() {
			if (_size == _capacity) reserve(_capacity * 2);
		}
		void push_back(const char ch) {
			check();
			_str[_size] = ch;
			_str[++_size] = '\0';
		}
		void append(const char* s) {
			insert(_size, s);
		}
		size_t find(const char ch, size_t pos) {
			for (int i = pos; i < _size; i++) {
				if (_str[i] == ch) return i;
			}
			return -1;
		}
		size_t find(const char* s, size_t pos) {
			const char* t = strstr(_str + pos, s);
			if (t) return t - _str;
			return -1;
		}
		void erase(size_t pos, size_t len) {
			assert(pos < _size);
			if (len + pos > _size) {
				_str[pos] = '\0';
				_size = pos + 1;
			}
			else {
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}
		string& operator+=(const char ch) {
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str) {
			append(str);
			return *this;
		}
		string& operator+=(const string& s) {
			append(s._str);
			return *this;
		}
		string& operator=(string s) { //s是临时构造的，用完就析构
			swap(s);
			return *this;
		}
		bool operator<(const string& s) {
			return strcmp(_str, s._str) < 0;
		}
		bool operator>(const string& s) {
			return strcmp(_str, s._str) > 0;
		}
		bool operator==(const string& s) {
			return strcmp(_str, s._str) == 0;
		}
		bool operator<=(const string& s) {
			return *this == s || *this < s;
		}
		bool operator>=(const string& s) {
			return *this == s || *this > s;
		}
		char& operator[](int i) const{
			assert(i < _size);
			return _str[i];
		}
		void everyone() {
			for (iterator i = begin(); i < end(); i++) {
				cout << *i << ' ';
			}
		}
		void clear() {
			_size = 0;
			_str[0] = '\0';
		}
		//错误示例：直接按照固有思维输入，没有考虑增容，直接暴毙
		/*friend istream& operator>>(istream& in, const string& s) {
			in >> s._str;
			return in;
		}*/

		friend istream& operator>>(istream& in, string& s) {
			s.clear();
			char ch;
			//in >> ch;  //忽略' '等间隔符， 导致一直循环
			ch = in.get();
			while (ch != ' ' && ch != '\r' && ch != '\n') {
				s += ch;
				ch = in.get();
			}
			return in;
		}

		//错误示例：按照string的思维输出，但模拟的时候要用char*的思维
		/*friend ostream& operator<<(ostream& out, const string& s) {
			out << s._str;
			return out;
		}*/
		friend ostream& operator<<(ostream& out, const string& s) {
			//out << s.c_str();
			for (auto ch : s) out << ch;
			return out;
		}

		istream& getline(istream& in, string& s) {   //差别只在getline可以输入空格
			s.clear();
			char ch;
			ch = in.get();
			while (ch != '\r' && ch != '\n') {
				s += ch;
				ch = in.get();
			}
			return in;
		}
	};
}
