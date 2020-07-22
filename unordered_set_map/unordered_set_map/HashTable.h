#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;


template<class K>

struct SetKeyOfT
{
	const K& operator()(const K& key)
	{
		return key;
	}
};
namespace Close_Hash
{
	enum state
	{
		EMPTY,
		EXITS,
		DELETE,
	};

	template<class T>
	struct HashData
	{
		T _data;
		state _state;
	};
	template<class K, class T, class KeyOfT>
	class HashTable
	{
		typedef HashData<T> HashData;
	public:
		bool Insert(const T& d)
		{
			KeyOfT koft;
			if (_tables.size() == 0 || _num * 10 / _tables.size() >= 7)
			{
				HashTable<K, T, KeyOfT> newtable;
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				newtable._tables.resize(newsize);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._state == EXITS)
					{
						newtable.Insert(_tables[i]._data);
					}
				}
				_tables.swap(newtable._tables);
			}

			//线性探测
			size_t index = koft(d) % _tables.size();
			while (_tables[index]._state == EXITS)
			{
				if (koft(_tables[index]._data) == koft(d))
					return false;
				index++;
				if (index == _tables.size())
					index = 0;
			}
			_tables[index]._data = d;
			_tables[index]._state = EXITS;
			_num++;

			//二次探测
			//size_t  start = koft(d) % _tables.size();
			//size_t index = start;
			//int i = 1;
			//while (_tables[index]._state == EXITS)
			//{
			//	if (koft(_tables[index]._data) == koft(d))
			//	{
			//		return false;
			//	}

			//	index = start + i * i;
			//	++i;
			//	index %= _tables.size();
			//}

			//_tables[index]._data = d;
			//_tables[index]._state = EXITS;
			//_num++;

			return true;
		}

		HashData* Find(const K& key)
		{
			KeyOfT koft;
			size_t index = key % _tables.size();
			while (_tables[index]._state != EMPTY)
			{
				if (koft(_tables[index]._data) == key)
				{
					if (_tables[index]._state == EXITS)
						return &_tables[index];
					else if (_tables[index]._state == DELETE)
						return nullptr;
				}
				index++;
				if (index == _tables.size())
					index = 0;
			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			HashData* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				_num--;
				return true;
			}
			return false;
		}
	private:
		vector<HashData> _tables;
		size_t _num = 0;
	};

	void TestHashTable()
	{
		HashTable<int, int, SetKeyOfT<int>> ht;
		ht.Insert(4);
		ht.Insert(14);
		ht.Insert(24);
		ht.Insert(5);
		ht.Insert(15);
		ht.Insert(25);
		ht.Insert(6);
		ht.Insert(16);
	}
}

namespace Opeon_Hash
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;
		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};


	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template<class K, class T, class KeyOfT, class Hash>
	struct __HashTableIterator
	{
		typedef __HashTableIterator<K, T, KeyOfT, Hash> Self;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef HashNode<T> Node;
		Node* _node;
		HT* _pht;

		__HashTableIterator(Node* node, HT* pht)
			:_node(node)
			, _pht(pht)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		T* operator->()
		{
			return &_node->_data;
		}

		Self operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyOfT koft;
				size_t i = _pht->HashFunc(koft(_node->_data)) % _pht->_tables.size();
				++i;
				for (; i < _pht->_tables.size(); i++)
				{
					if (_pht->_tables[i])
					{
						_node = _pht->_tables[i];
						return *this;
					}
				}
				_node = nullptr;
			}
			return *this;
		}
		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
	};

	template<class K>
	struct _Hash
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
	template<>
	struct _Hash<string>
	{
		size_t operator()(const string& key)
		{
			size_t ret = 0;
			for (size_t i = 0; i < key.size(); i++)
			{
				ret *= 131;
				ret += key[i];
			}
			return ret;
		}
	};
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
		typedef HashNode<T> Node;
	public:
		friend struct __HashTableIterator<K, T, KeyOfT, Hash>;
		typedef __HashTableIterator<K, T, KeyOfT, Hash> iterator;


		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return iterator(_tables[i], this);
				}
			}
			return end();
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}

		~HashTable()
		{
			Clear();
		}
		void Clear()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		size_t HashFunc(const K& key)
		{
			Hash hash;
			return hash(key);
		}

		pair<iterator, bool> Insert(const T& data)
		{
			KeyOfT koft;
			if (_tables.size() == _num)
			{
				vector<Node*> newtables;
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				newtables.resize(newsize);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						int index = HashFunc(koft(cur->_data)) % newsize;
						cur->_next = newtables[index];
						newtables[index] = cur;
						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newtables);
			}

			size_t index = HashFunc(koft(data)) % _tables.size();
			Node* cur = _tables[index];
			while (cur)
			{
				if (koft(cur->_data) == koft(data))
					return make_pair(iterator(cur, this), false);
				else
					cur = cur->_next;
			}

			Node* newnode = new Node(data);
			newnode->_next = _tables[index];
			_tables[index] = newnode;
			++_num;
			return make_pair(iterator(newnode, this), true);
		}
		
		Node* Find(const K& key)
		{
			KeyOfT koft;
			size_t index = HashFunc(key) % _tables.size();
			Node* cur = _tables[index];
			while (cur)
			{
				if (koft(cur->_data) == key)
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			KeyOfT koft;
			size_t index = HashFunc(key) & _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[index];
			while (cur)
			{
				if (koft(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_tables[index] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}
	private:
		vector<Node*> _tables;
		size_t _num = 0;
	};

	void TestHashTable1()
	{
		HashTable<int, int, SetKeyOfT<int>, _Hash<int>> ht;
		ht.Insert(4);
		ht.Insert(14);
		ht.Insert(24);
		ht.Insert(5);
		ht.Insert(15);
		ht.Insert(25);
		ht.Insert(6);
		ht.Insert(16);
		ht.Insert(26);
		ht.Insert(36);
		ht.Insert(33);
		ht.Insert(44);

		ht.Erase(4);
		ht.Erase(44);
	}

	void TestHashTable2()
	{
		//HashTable<string, string, SetKeyOfT<string>, _HashString> ht;
		HashTable<string, string, SetKeyOfT<string>, _Hash<string>> ht;
		ht.Insert("sort");
		ht.Insert("string");
		ht.Insert("left");

		cout << ht.HashFunc("abcd") << endl;
		cout << ht.HashFunc("aadd") << endl;
	}
}