#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<assert.h>
using namespace std;
namespace allorry {
	class string {
		//管理字符串的数组，可以增删查改
		//结尾带有'\0'
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
		void swap(string& s) {  //类内swap与模板swap合并
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		string(const char* str = "") {
			_capacity = _size = strlen(str);
			_str = new char[_capacity + 1]; 
			//空间多开一个存'\0'，后续也稍微注意些
			strcpy(_str, str);
		}
		string(const string& s):_str(nullptr)
		{    //不把_str置空，析构t随机值的时候会出现问题
			string t(s._str); //构造函数打造替代品
			swap(t);
		}
		~string() {
			delete[] _str, _str = nullptr;
		}
		size_t size() {
			return _size;
		}
		void reserve(int n) { //开辟新空间
			n = (n == 0) ? 1 : n;  //开辟0个空间会坏事
			if (n <= _capacity) return;
			char* t = new char[n + 1]; //多开，'\0'
			strcpy(t, _str);
			delete[] _str;
			_str = t;
			_capacity = n;
		}
		void resize(size_t n, char val='\0') {
	    //假设size=4，capacity=8，二者分了三种情况，一三种需要讨论
			if (n < _size) {
				_size = n;
				_str[_size] = '\0';
			}
			else {
				if (n > _capacity) 
					reserve(n);
				for (int i = _size; i < n; i++)
					_str[i] = val;
				_str[n] = '\0';
				_size = n;
			}
		}
		void push_back(char ch) {
			if (_size == _capacity) 
				reserve(_capacity * 2);
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			_size++;
		}
		void insert(size_t pos, char ch) {
			//坑点：size_t n=0, n-1 > 4e10
			assert(pos <= _size);
			if (_size == _capacity)
				reserve(2 * _capacity);
			char* end = _str + _size;
			while (end >= _str + pos) {
				*(end + 1) = *(end); end--;
			}
			_str[pos] = ch;
			_size++;
		}
		void insert(size_t pos, const char* str) {
			assert(pos <= _size);
			size_t len = strlen(str);
			if (len + _size > _capacity)
				reserve(len + _size);
			char* end = _str + _size;
			while (end >= _str + pos) {
				*(end + len) = *(end); end--;
			}
			strncpy(_str + pos, str, len); //防止str的\0覆盖有效数据
			_size += len;
		}
		void append(const char* str) {
			/*size_t len = _size + strlen(str);
			if (len > _capacity)
				reserve(len);
			strcpy(_str + _size, str);
			_size = len;*/

			insert(_size, str);
		}
		size_t find(char ch, size_t pos=0) {
			for (size_t i = pos; i < _size; i++)
				if (ch == _str[i]) return i;
			return -1;
		}
		size_t find(const char* str, size_t pos=0) {
			const char* ret = strstr(_str + pos, str);
			if (ret) return ret - _str;
			else return -1;
		}
		void erase(size_t pos, size_t len) {
			assert(pos < _size);
			if (len + pos >= _size) { //全部删完
				_str[pos] = '/0';
				_size -= len;
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
			return strcmp(c_str(), s.c_str()) < 0;
		}
		bool operator>(const string& s) {
			return strcmp(c_str(), s.c_str()) > 0;
		}
		bool operator==(const string& s) {
			return strcmp(c_str(), s.c_str())==0;
		}
		bool operator<=(const string& s) {
			return *this == s || *this < s;
		}
		bool operator>=(const string& s) {
			return *this == s || *this > s;
		}
		char& operator[](int i) const{ //返回引用
			assert(i < _size);
			return _str[i];
		}
		char* c_str() const {
			return _str;
		}
		void everyone() {
			for (iterator i = this->begin(); i < this->end(); i++) {
				cout << *i << ' ';
			}
		}
		void clear() {
			_size = 0;
			_str[0] = '\0';
		}
	};
	ostream& operator<<(ostream& out, const string& s) {
		//out << s.c_str();
		for (auto ch : s) out << ch;
		return out;
	}
	istream& operator>>(istream& in, string& s) {
		s.clear();
		char ch;
		//in >> ch;  //忽略' '等间隔符， 导致一直循环
		ch = in.get();
		while (ch!=' ' && ch!= '\r' && ch!='\n') {
			s += ch;
			ch=in.get();
		}
		return in;
	}
	istream& getline(istream& in, string& s) {
		s.clear();
		char ch;
		ch = in.get();
		while (ch != '\r' && ch != '\n') {
			s += ch;
			ch = in.get();
		}
		return in;
	}
}

