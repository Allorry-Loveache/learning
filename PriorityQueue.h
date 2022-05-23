#include<iostream>
#include<vector>
using namespace std;
namespace Allorry {

    template <class T>
	struct less {
		bool operator()(const T& a, const T& b) {
			return a < b;
		}
	};

	template <class T>
	struct greater {
		bool operator()(const T& a, const T& b) {
			return a > b;
		}
	};

	//��sort������ͬ��less��greater�ĺ��������仯
	//Ĭ����һ����ѣ�Ĭ�ϴ�����ȼ��� less��ȡֵ�����ǽ��򣨴�ѱ���������
	//�����С�ѣ�С�����ȼ��� greater��ȡֵ����������
	template<class T, class Container=vector<T>, class Compare=greater<T> >
	class priority_queue {
	private:
		Container con;
		Compare cmp;
	public:
		void AdjustUp(size_t child) {
			size_t parent = (child - 1) / 2;
			while (child > 0) {
				if (cmp(con[parent], con[child])) {
					swap(con[parent], con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else break;
			}
		}
		
		void push(const T& x) {
			con.push_back(x);
			AdjustUp(con.size() - 1);
		}

		void AdjustDown(int parent) {
			int child = parent * 2 + 1;
			while (child < con.size()) {
				if (child + 1 < con.size() && cmp(con[child], con[child + 1]))
					child++;
				if (cmp(con[parent], con[child])) {
					swap(con[parent], con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else break;
			}
		}

		void pop() {
			swap(con[0], con[con.size() - 1]);
			con.pop_back();
			AdjustDown(0);
		}

		T& top() {
			return con[0];
		}

		size_t size() {
			return con.size();
		}

		bool empty() {
			return con.empty();
		}
	};
} 

