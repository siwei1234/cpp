#pragma once
#include<vector>
namespace Stack
{
	template<class T, class Container = std::vector<int>>
	class stack
	{
	public:
		bool empty() { return _st.empty(); }
		void pop() { _st.pop_back(); }
		void push(T a) { _st.push_back(a); }
		int size() { return _st.size(); }
		T top() { return _st.back(); }
	private:
		Container _st;
	};
	void stack_test()
	{
		stack<int, vector<int>> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);

		st.pop();
		cout << st.empty() << endl;
		cout << st.size() << endl;
		cout << st.top() << endl;
	}
}
