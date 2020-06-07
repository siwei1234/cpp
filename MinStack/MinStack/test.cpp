#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
		_st.push(x);
		if (_min.empty() || _min.top() > x)
			_min.push(x);
		else
			_min.push(_min.top());
	}

	void pop() {
		_st.pop();
		_min.pop();
	}

	int top() {
		return _st.top();
	}

	int getMin() {
		return _min.top();
	}
	stack<int> _st;
	stack<int> _min;
};

int main()
{
	MinStack* obj = new MinStack();
	obj->push(5);
	obj->push(4);
	obj->pop();
	cout << obj->top() << endl;
	cout << obj->getMin() << endl;
}
