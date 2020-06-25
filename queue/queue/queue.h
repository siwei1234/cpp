#pragma once
#include<list>
namespace Queue
{
	template<class T, class Container = std::list<int>>
	class queue
	{
	public:
		bool empty() { return _q.empty(); }
		void pop() { _q.pop_front(); }
		void push(T a) { _q.push_back(a); }
		int size() { return _q.size(); }
		T back() { return _q.back(); }
		T front() { return _q.front(); }
	private:
		Container _q;
	};
	void queue_test()
	{
		queue<int, list<int>> q;
		q.push(1);
		q.push(2);
		q.push(3);

		q.pop();

		cout << q.empty() << endl;
		cout << q.size() << endl;
		cout << q.front() << endl;
		cout << q.back() << endl;
	}
}
