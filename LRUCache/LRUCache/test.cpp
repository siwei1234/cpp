#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;


class LRUCache {
public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
		auto ret = _hashmap.find(key);
		if (ret == _hashmap.end())
			return -1;
		auto cur = ret->second;
		auto pos = *cur;
		_lrulist.erase(cur);
		_lrulist.push_front(pos);
		_hashmap[key] = _lrulist.begin();
		return pos.second;
	}

	void put(int key, int value) {
		auto ret = _hashmap.find(key);
		if (ret != _hashmap.end())
		{
			auto cur = ret->second;
			_lrulist.erase(cur);
			_lrulist.push_front(make_pair(key, value));
			_hashmap[key] = _lrulist.begin();
		}
		else
		{
			if (_lrulist.size() == _capacity)
			{
				auto back = _lrulist.back();
				_hashmap.erase(back.first);
				_lrulist.pop_back();
			}
			_lrulist.push_front(make_pair(key, value));
			_hashmap.insert(make_pair(key, _lrulist.begin()));
		}
	}
private:
	unordered_map<int, list<pair<int, int>>::iterator> _hashmap;
	list<pair<int, int>> _lrulist;
	int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
	LRUCache cache(2);

	cache.put(1, 1);
	cache.put(2, 2);
	cache.get(1);       // 返回  1
	cache.put(3, 3);    // 该操作会使得关键字 2 作废
	cache.get(2);       // 返回 -1 (未找到)
	cache.put(4, 4);    // 该操作会使得关键字 1 作废
	cache.get(1);       // 返回 -1 (未找到)
	cache.get(3);       // 返回  3
	cache.get(4);       // 返回  4

	return 0;
}