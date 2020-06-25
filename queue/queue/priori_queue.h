#pragma once
#include<iostream>
#include<vector>
#include<functional>
using namespace std;
namespace Priority_queue
{
	template<class T>
	struct less
	{
		bool operator()(const T& left, const T& right)
		{
			return left < right;
		}
	};
	template<class T>
	struct greater
	{
		bool operator()(const T& left, const T& right)
		{
			return left > right;
		}
	};
	template<class T, class Container = std::vector<int>, class Compare = less<T>>
	class priority_queue
	{
	public:
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_pq[parent], _pq[child]))
				{
					swap(_pq[parent], _pq[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void AdjustDwon(int parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _pq.size())
			{
				if (child + 1 < _pq.size() && com(_pq[child], _pq[child + 1]))
				{
					++child;
				}
				if (com(_pq[parent], _pq[child]))
				{
					swap(_pq[parent], _pq[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		bool empty() const { return _pq.empty(); }
		size_t size() const { return _pq.size(); }
		T top() const { return _pq[0]; }
		void push(const T& x)
		{
			_pq.push_back(x);
			AdjustUp(_pq.size() - 1);
		}
		void pop()
		{
			swap(_pq[0], _pq[_pq.size() - 1]);
			_pq.pop_back();
			AdjustDwon(0);
		}
	private:
		Container _pq;
	};

	void test_priority_queue()
	{
		//priority_queue<int> pq;
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(3);
		pq.push(1);
		pq.push(9);
		pq.push(4);
		pq.push(2);

		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
}