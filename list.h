#pragma once //Ϊ�˱���ͬһ��ͷ�ļ���������include�����

#include<cassert>
#include<iostream>
namespace allorry {

	template <class T>
	struct _list_node {
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _val;

		_list_node(const T& x = T()) :
			_next(nullptr), _prev(nullptr), _val(x) {}
	};


	template <class T, class Ref, class Ptr>
	struct _list_iterator {
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr> self;

		node* _node;

		_list_iterator(node* x) :_node(x) {}

		Ref operator*() {   // *it
			return _node->_val;
		}

		self& operator++() {   // ++it
			_node = _node->_next;
			return *this;
		}

		self operator++(int) {  // it++
			self t(*this);
			++(*this);
			return t;
		}

		self& operator--() {   // --it
			_node = _node->_prev;
			return *this;
		}

		self operator--(int) {  // it--
			self t(*this);
			--(*this);
			return t;
		}

		bool operator!=(const self& x) {  // !=
			return _node != x._node;
		}

		Ptr operator->() {  // ->    �������ͣ� T*  or  const T*
			return &_node->_val;
		}
	};

	template <class T>
	class list {
		typedef _list_node<T> node;

	public:
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		//���ݴ����������͵Ĳ�ͬ����ȷ�����ĸ�iterator

		iterator begin() {
			return iterator(_head->_next);
		}
		iterator end() {
			return iterator(_head);
		}
		const_iterator begin() const{
			return const_iterator(_head->_next);
		}
		const_iterator end() const{
			return const_iterator(_head);
		}

		list() {
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list(const list<T>& x) {
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			const_iterator i = x.begin();
			while (i != x.end()) {
				push_back(*i);
				++i;
			}
		}

		void push_back(const T& x) {
			//�Ϸ�����ϲ���ּ���newnode����
			insert(end(), x);
		}

		void insert(iterator pos, const T& x) {
			//left  newnode  pos(right) 
			
			node* right = pos._node;  //������. ����->, _node����ָ��
			node* left = right->_prev;
			node* newnode = new node(x);

			left->_next = newnode;
			newnode->_prev = left;
			newnode->_next = right;
			right->_prev = newnode;
		}

		~list() {
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear() {
			iterator it = begin();
			while (it != end()) {
				erase(it++);
			}
		}

		void erase(iterator pos) {
			assert(pos != end()); //ͷ��㣺Ī������
			//left  pos(t)  right
			node* t = pos._node;
			node* left = t->_prev;
			node* right = t->_next;

			delete t;
			left->_next = right;
			right->_prev = left;
		}

		void pop_back() {
			//erase(iterator(_head->_prev));
			erase(--end());  //��λ����β��ָ�봫��erase
		}

		void push_front(const T& x) {
			insert(begin(), x);
		}

		void pop_front() {
			erase(begin());
		}

		void print() {
			iterator i = begin();
			while (i!=end()) {
				std::cout << *i << ' ';
				++i;
			}
			std::cout << std::endl;
		}

		list<T>& operator=(const list<T>& it)//��ֵ������������Լ���ͷ���
		{
			if (this != &it)//�����Լ����Լ���ֵ
			{
				clear();
				for (auto& i : it)
				{
					push_back(i);
				}
			}
			return *this;
		}
		//��д��
		list<T>& operator=(list<T>& it)
		{
			swap(_head, it._head);
			return *this;
		}

	private:
		node* _head;
	};

	void test()
	{
		list<int>l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.print();

		l.push_front(0);
		l.print();
		l.insert(l.begin(), 2);
		l.print();

		l.pop_back();
		l.print();
		l.pop_front();
		l.print();
		l.erase(l.begin());
		l.print();

		list<int>i(l);
		i.push_back(10);
		i.push_back(20);
		i.push_back(30);
		l.print();
	}

}

