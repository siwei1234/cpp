#pragma once
#include<iostream>
#include<string>
using namespace std;
namespace Vector
{
	template<class T>
	class vector
	{
	public:
		// Vector的迭代器是一个原生指针
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}

		// construct and destroy
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endOfStorage(nullptr)
		{}
		vector(int n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			resize(n, value);
		}
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(v.capacity());
			for (auto e : v)
				push_back(e);
		}
		vector<T>& operator= (vector<T> v)
		{
			swap(v);
			return *this;
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
		// capacity
		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _endOfStorage - _start;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = tmp + sz;
				_endOfStorage = tmp + n;
			}
		}
		void resize(size_t n, const T& value = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
					reserve(n);
				while (_finish < _start + n)
				{
					*_finish = value;
					++_finish;
				}
			}

		}

		///////////////access///////////////////////////////
		T& operator[](size_t pos)
		{
			return _start[pos];
		}
		const T& operator[](size_t pos)const
		{
			return _start[pos];
		}

			///////////////modify/////////////////////////////
		void push_back(const T& x)
		{
			if (_finish == _endOfStorage)
			{
				size_t newcapaity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapaity);
			}
			*_finish = x;
			++_finish;
		}
		void pop_back()
		{
			--_finish;
		}
		void swap(vector<T>& v)
		{
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endOfStorage, v._endOfStorage);
		}
		iterator insert(iterator pos, const T& x)
		{
			if (_finish == _endOfStorage)
			{
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + n;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
			
		}
		iterator erase(iterator pos)
		{
			iterator it = pos;
			while (it < _finish)
			{
				*it = *(it + 1);
				++it;
			}
			--_finish;
			return pos;
		}
	private:
		iterator _start; // 指向数据块的开始
		iterator _finish; // 指向有效数据的尾
		iterator _endOfStorage; // 指向存储容量的尾
	};
	void print_vector(const vector<int>& v)
	{
		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			//*it += 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		print_vector(v);

		cout << v.size() << endl;
		cout << v.capacity() << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			*it += 1;
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto& e : v)
		{
			e -= 1;
			cout << e << " ";
		}
		cout << endl;

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}

	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		v.insert(v.begin(), 0);
		print_vector(v);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}

		print_vector(v);
	}

	void test_vector3()
	{
		vector<int> v;
		v.reserve(10);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);

		print_vector(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;

		v.resize(4);
		print_vector(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;

		v.resize(8, 8);
		print_vector(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;

		v.resize(12);
		print_vector(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;

		//int i = int();
		//int j = int(1);
		//double d = double();
		//double e = double(1.1);
	}

	void test_vector4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		vector<int> v2(v1);
		for (size_t i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		for (size_t i = 0; i < v2.size(); ++i)
		{
			cout << v2[i] << " ";
		}
		cout << endl;

		vector<int> v3;
		v3.push_back(10);
		v3.push_back(20);
		v3.push_back(30);
		v3.push_back(40);

		v1 = v3;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : v3)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector5()
	{
		vector<string> v;
		v.push_back("111111111111111111111111");
		v.push_back("222222222222222222222222");
		v.push_back("333333333333333333333333");
		v.push_back("444444444444444444444444");

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}