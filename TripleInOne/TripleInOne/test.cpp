#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class TripleInOne {
private:
	int* _arr;
	int* _size;
	int _stackSize;
public:
	TripleInOne(int stackSize) {
		_arr = new int[3 * stackSize];
		_size = new int[3]{ 0,0,0 };
		_stackSize = stackSize;
	}

	void push(int stackNum, int value) {
		int len = _size[stackNum];
		if (len < _stackSize)
		{
			_arr[(stackNum*_stackSize) + len] = value;
			_size[stackNum]++;
		}
	}

	int pop(int stackNum) {
		int ret = peek(stackNum);
		if (_size[stackNum] > 0)
			_size[stackNum]--;
		return ret;
	}

	int peek(int stackNum) {
		if (_size[stackNum] == 0)
			return -1;
		return _arr[_stackSize * stackNum + _size[stackNum] - 1];
	}

	bool isEmpty(int stackNum) {
		if (_size[stackNum] == 0)
			return true;
		return false;
	}
};

int main()
{
	int stackSize = 3;
	TripleInOne* obj = new TripleInOne(stackSize);
    obj->push(0,1);
    int param_2 = obj->pop(0);
    int param_3 = obj->peek(0);
    bool param_4 = obj->isEmpty(0);
	return 0;
}