#pragma once

#include"bitset.h"
#include<string>
#include<iostream>
using namespace BitSet;
namespace BloomFilter
{
	struct HashStr1
	{
		size_t operator()(const string &s)
		{
			size_t ret = 0;
			for (size_t i = 0; i < s.size(); i++)
			{
				ret *= 131;
				ret += s[i];
			}
			return ret;
		}
	};
	struct HashStr2
	{
		size_t operator()(const string& s)
		{
			size_t ret = 0;
			size_t magic = 63689;
			for (size_t i = 0; i < s.size(); i++)
			{
				ret *= magic;
				ret += s[i];
				magic *= 378551;
			}
			return ret;
		}
	};
	struct HashStr3
	{
		size_t operator()(const string& s)
		{
			size_t ret = 0;
			for (size_t i = 0; i < s.size(); i++)
			{
				ret *= 65599;
				ret += s[i];
			}
			return ret;
		}
	};
	template<class K = string, class Hash1 = HashStr1, class Hash2 = HashStr2, class Hash3 = HashStr3>
	class bloomfilter
	{
	public:
		bloomfilter(size_t num)
			:_bs(5 * num)
			, _num(5 * num)
		{}
		void set(K key)
		{
			size_t index1 = Hash1()(key) % _num;
			size_t index2 = Hash2()(key) % _num;
			size_t index3 = Hash3()(key) % _num;
			_bs.set(index1);
			_bs.set(index2);
			_bs.set(index3);
		}
		bool test(K key)
		{
			size_t index1 = Hash1()(key) % _num;
			if (_bs.test(index1) == false)
				return false;
			size_t index2 = Hash2()(key) % _num;
			if (_bs.test(index2) == false)
				return false;
			size_t index3 = Hash3()(key) % _num;
			if (_bs.test(index3) == false)
				return false;
			return true;
		}
	private:
		bitset _bs;
		size_t _num;
	};

	void test_bloomfilter()
	{
		bloomfilter<std::string> bf(100);
		bf.set("abcd");
		bf.set("aadd");
		bf.set("bcad");

		cout << bf.test("abcd") << endl;
		cout << bf.test("aadd") << endl;
		cout << bf.test("bcad") << endl;
		cout << bf.test("cbad") << endl;
	}
}