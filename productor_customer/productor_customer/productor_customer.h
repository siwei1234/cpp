#pragma once

#include<iostream>
#include<cstdio>
#include<mutex>
#include<vector>
#include<condition_variable>
#include<thread>
#include<queue>
using namespace std;


class BlockQueue
{
public:
	BlockQueue(int max = 5)
		:_capacity(max)
	{}
	bool Push(int data)
	{
		unique_lock<mutex> lck(_mtx);
		while (_queue.size() == _capacity)
		{
			_pro.wait(lck);
		}
		_queue.push(data);
		lck.unlock();
		_cus.notify_one();
		return true;
	}
	bool Pop(int* data)
	{
		unique_lock<mutex> lck(_mtx);
		while (_queue.empty())
		{
			_cus.wait(lck);
		}
		*data = _queue.front();
		_queue.pop();
		lck.unlock();
		_pro.notify_one();
		return true;
	}
private:
	queue<int> _queue;
	int _capacity;
	condition_variable _pro;
	condition_variable _cus;
	mutex _mtx;
};
