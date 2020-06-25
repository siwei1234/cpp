#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<queue>
//#include<functional>
//using namespace std;
//#include "queue.h"
#include "priority_queue.h"
using namespace std;

//int main()
//{
//	/*queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//
//	q.pop();
//
//	cout << q.empty() << endl;
//	cout << q.size() << endl;
//	cout << q.front() << endl;
//	cout << q.back() << endl;*/
//
//	Queue::queue_test();
//	return 0;
//}
//
//int main()
//{
//	vector<int> v{ 2,5,9,7,5,7,9,6 };
//	priority_queue<int, vector<int>, greater<int>> pq;
//	for (auto& e : v)
//	{
//		pq.push(e);
//	}
//	pq.pop();
//	cout << pq.empty() << endl;
//	cout << pq.top() << endl;
//	return 0;
//}

//namespace func
//{
//	template<class T>
//	struct less
//	{
//		bool operator()(const T& left, const T& right)
//		{
//			return left < right;
//		}
//	};
//	template<class T>
//	struct greater
//	{
//		bool operator()(const T& left, const T& right)
//		{
//			return left > right;
//		}
//	};
//}
//
//int main()
//{
//	vector<int> v{ 2,5,9,7,5,7,9,6 };
//	priority_queue<int, vector<int>, func::greater<int>> pq;
//	for (auto& e : v)
//	{
//		pq.push(e);
//	}
//	pq.pop();
//	cout << pq.empty() << endl;
//	cout << pq.top() << endl;
//	return 0;
//}

int main()
{
	Priority_queue::test_priority_queue();
	return 0;
}