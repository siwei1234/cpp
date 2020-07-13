#pragma once

#include<vector>
#include<cstdio>
using namespace std;

namespace BitSet
{
	class bitset
	{
	public:
		bitset(size_t n)
		{
			_bit.resize(n / 32 + 1, 0);
			_num = 0;
		}
		void set(size_t x)
		{
			size_t index = x / 32;
			size_t pos = x % 32;
			_bit[index] |= (1 << pos);
			++_num;
		}
		void reset(size_t x)
		{
			size_t index = x / 32;
			size_t pos = x % 32;
			_bit[index] &= ~(1 << pos);
			--_num;
		}
		bool test(size_t x)
		{
			size_t index = x / 32;
			size_t pos = x % 32;
			return _bit[index] & (1 << pos);
		}
	private:
		vector<int> _bit;
		size_t _num;
	};

	void test_bitset()
	{
		bitset bs(100);
		bs.set(99);
		bs.set(98);
		bs.set(97);
		bs.set(5);
		bs.reset(98);

		for (size_t i = 0; i < 100; ++i)
		{
			printf("[%d]:%d\n", i, bs.test(i));
		}

		//bitset bs(-1);
		//bitset bs(pow());
		//bitset bs(0xffffffff);

	}
}
