#pragma once

#include<iostream>
#include<mutex>
#include<queue>
#include<thread>
#include<vector>
#include<condition_variable>

using namespace std;


typedef void(*handler_t)(int);
class ThreadTask
{
public:
	void SetTask(handler_t handler, int data)
	{
		_handler = handler;
		_data = data;
	}
	void Run()
	{
		return _handler(_data);
	}
private:
	handler_t _handler;
	int _data;
};

class ThreadPool
{
public:
	ThreadPool(int max = 5)
		:_thr_max(max)
	{
		for (int i = 0; i < max; i++)
		{
			_vthreads.push_back(thread(thr_start, this));
			_vthreads[i].detach();
		}
	}
	~ThreadPool()
	{
		//for (int i = 0; i < _thr_max; i++)
		//{
		//	_vthreads[i].join();
		//}
	}
	bool TaskPush(ThreadTask& task)
	{
		mtx.lock();
		_queue.push(task);
		mtx.unlock();
		cv.notify_all();
		return true;
	}
	static void* thr_start(ThreadPool* p)
	{
		while (1)
		{
			unique_lock<mutex> lck(p->mtx);
			while (p->_queue.empty())
			{
				p->cv.wait(lck);
			}
			ThreadTask task = p->_queue.front();
			p->_queue.pop();
			lck.unlock();
			task.Run();
		}
		return NULL;
	}
private:
	mutex mtx;
	condition_variable cv;
	vector<thread> _vthreads;
	queue<ThreadTask> _queue;
	int _thr_max;
};