#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<mutex>
using namespace std;

class HeapOnly
{
public:
	HeapOnly(const HeapOnly&) = delete;
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly() {}
};



class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
private:
	StackOnly()
	{}
};

class CopyBan
{
	CopyBan(const CopyBan&) = delete;
	CopyBan& operator=(const CopyBan&) = delete;
};

class A final
{
	//...
};


//class singleton
//{
//public:
//	static singleton* GerInstance()
//	{
//		return &m_instance;
//	}
//	singleton(){}
//	singleton(const singleton&) = delete;
//	singleton& operator=(const singleton&) = delete;
//private:
//	static singleton m_instance;
//};
////在程序入口之前就完成单例对象的初始化
//singleton singleton::m_instance;


class singleton
{
public:
	static singleton* GerInstance()
	{
		if (m_instance == nullptr)
		{
			m_mtx.lock();
			if (m_instance == nullptr)
			{
				m_instance = new singleton();
			}
			m_mtx.unlock();
		}
		return m_instance;
	}

	//实现一个内嵌垃圾回收类
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (singleton::m_instance)
				delete singleton::m_instance;
		}
	};

	static CGarbo Garbo;

	singleton(const singleton&) = delete;
	singleton& operator=(const singleton&) = delete;
private:
	singleton() {}
	static singleton* m_instance;
	static mutex m_mtx;
};
singleton* singleton::m_instance = nullptr;
mutex singleton::m_mtx;
singleton::CGarbo Garbo;



int main()
{
	StackOnly s = StackOnly::CreateObject();
	return 0;
}