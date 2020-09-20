#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<memory>
#include "shared_ptr.h"
using namespace std;

//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//private:
//	T* _ptr;
//};
//
//int main()
//{
//
//	int* p = new int;
//	SmartPtr<int> sp(p);
//
//	cout << *sp << endl;
//	return 0;
//}


//int main()
//{
//	auto_ptr<int> ap(new int);
//	auto_ptr<int> cap = ap;
//
//	cout << *ap << endl;
//
//	return 0;
//}

int x1()
{
	ptr::auto_ptr<int> ap1(new int);
	ptr::auto_ptr<int> ap2 = ap1;

	cout << *ap2 << endl;
	return 0;
}

//int main()
//{
//	ptr::shared_ptr<int> up1(new int);
//	ptr::shared_ptr<int> up2 = up1;
//
//
//	cout << up1.use_count() << endl;
//	cout << up2.use_count() << endl;
//	return 0;
//}


//struct ListNode
//{
//	ptr::weak_ptr<ListNode> _prev;
//	ptr::weak_ptr<ListNode> _next;
//
//	~ListNode()
//	{
//		cout << "delete" << endl;
//	}
//};
//
//int main()
//{
//	ptr::shared_ptr<ListNode> node1(new ListNode);
//	ptr::shared_ptr<ListNode> node2(new ListNode);
//
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//
//	node1->_next = node2;
//	node2->_prev = node1;
//
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	return 0;
//}

//template<class T>
//struct Free
//{
//	void operator()(T* ptr)
//	{
//		free(ptr);
//	}
//};
//
//template<class T>
//struct DeleteArray
//{
//	void operator()(T* ptr)
//	{
//		delete[] ptr;
//	}
//};
//
//struct Close
//{
//	void operator()(FILE* ptr)
//	{
//		fclose(ptr);
//	}
//};
//
//int main()
//{
//	shared_ptr<int> sp1((int*)malloc(4), Free<int>());
//	shared_ptr<int> sp2(new int[10], DeleteArray<int>());
//	shared_ptr<FILE> sp3(fopen("t.txt", "w+"), Close());
//	return 0;
//}

#include<mutex>
#include<thread>
using namespace std;


template<class Mutex>
class LockGuard
{
public:
	LockGuard(Mutex& mtx)
		:_mtx(mtx)
	{
		_mtx.lock();
	}

	~LockGuard()
	{
		_mtx.unlock();
	}

	LockGuard(const LockGuard<Mutex>&) = delete;
private:
	//使用引用，锁的就是一个互斥量对象
	Mutex& _mtx;
};


int n = 0;
mutex mtx;
void func()
{
	for (int i = 0; i < 1000000; i++)
	{
		LockGuard<mutex> lock(mtx);
		++n;
	}
}
int main()
{
	thread t1(func);
	thread t2(func);

	t1.join();
	t2.join();
	cout << n << endl;

}