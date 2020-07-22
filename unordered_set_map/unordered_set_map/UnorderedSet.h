#pragma once

#include"HashTable.h"

using namespace Opeon_Hash;
namespace UnorderedSet
{
	template<class K, class Hash = Opeon_Hash::_Hash<K>>
	class unorderedset
	{
	private:
		struct SetKOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
		HashTable<K, K, SetKOfT, Hash> _ht;
	public:
		typedef typename HashTable<K, K, SetKOfT, Hash>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		pair<iterator, bool> insert(const K& k)
		{
			return _ht.Insert(k);
		}
	};
	void test_unordered_set()
	{
		unorderedset<int> s;
		s.insert(1);
		s.insert(5);
		s.insert(4);
		s.insert(2);

		unorderedset<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}