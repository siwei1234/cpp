#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
namespace bit
{
	class string
	{
		friend ostream& operator<<(ostream& _cout, const bit::string& s);
		friend istream& operator>>(istream& _cin, bit::string& s);
	public:
		typedef char* iterator;
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
			_size = _capacity = strlen(str);
		}
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);
			swap(tmp);
		}
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		// iterator
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		// modify
		void PushBack(char c)
		{
			if (_size == _capacity)
			{
				size_t n = _capacity == 0 ? 2 : _capacity * 2;
				reserve(n);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		string& operator+=(char c)
		{
			this->PushBack(c);
			return *this;
		}
		void Append(const char* str)
		{
			size_t len = strlen(str);
			if ((_size + len) > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		string& operator+=(const char* str)
		{
			this->Append(str);
			return *this;
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		void swap(string& s)
		{
			char* tmp = _str;
			_str = s._str;
			s._str = tmp;
			
			size_t size = _size;
			_size = s._size;
			s._size = size;
			
			size_t capacity = _capacity;
			_capacity = s._capacity;
			s._capacity = capacity;
		}
		const char* c_str()const
		{
			return _str;
		}

		// capacity
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		bool empty()const
		{
			if (_size == 0)
				return true;
			return false;
		}
		void resize(size_t newSize, char c = '\0')
		{
			if (newSize < _size)
			{
				_str[newSize] = '\0';
				_size = newSize;
			}
			else
			{
				if (newSize > _capacity)
				{
					reserve(newSize);
				}
				for (size_t i = _size; i < newSize; i++)
				{
					_str[i] = c;
				}
				_size = newSize;
				_str[newSize] = '\0';
			}
		}
		void reserve(size_t newCapacity)
		{
			if (newCapacity > _capacity)
			{
				char* tmp = new char[newCapacity + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = newCapacity;
			}
		}

		// access
		char& operator[](size_t index)
		{
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			return _str[index];
		}

		//relational operators
		bool operator<(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret < 0;
		}
		bool operator<=(const string& s)
		{
			return *this < s || *this == s;
		}
		bool operator>(const string& s)
		{
			return !(*this <= s);
		}
		bool operator>=(const string& s)
		{
			return !(*this < s);
		}
		bool operator==(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret == 0;
		}
		bool operator!=(const string& s)
		{
			return !(*this == s);
		}

		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == c)
				{
					return i;
				}
			}
			return npos;
		}
		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const
		{
			char* p = strstr(_str, s);
			if (p == nullptr)
				return npos;
			return p - _str;
		}
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c)
		{
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}
			int end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				end--;
			}
			_str[pos] = c;
			++_size;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			int end = _size;
			while (end >= (int)pos)
			{
				_str[end + len] = _str[end];
				--end;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}

		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len)
		{
			if (len > _size - pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				for (size_t i = pos + len; i <= _size; i++)
				{
					_str[i - len] = _str[i];
				}
				_size -= len;
			}
			return *this;
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
		static size_t npos;
	};
	size_t string::npos = -1;
	ostream& operator<<(ostream& _cout, const string& s)
	{
		for (size_t i = 0; i < s.size(); i++)
		{
			_cout << s[i];
		}
		return _cout;
	}
	istream& operator>>(istream& _cin, string& s)
	{
		while (1)
		{
			char ch;
			ch = _cin.get();
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			else
			{
				s += ch;
			}
		}
		return _cin;
	}
	void test_string1()
	{
		string s1;
		string s2("hello");
		cout << s1 << endl;
		cout << s2 << endl;
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		// 三种遍历方式
		for (size_t i = 0; i < s2.size(); ++i)
		{
			s2[i] += 1;
			cout << s2[i] << " ";
		}
		cout << endl;

		string::iterator it2 = s2.begin();
		while (it2 != s2.end())
		{
			*it2 -= 1;
			cout << *it2 << " ";
			++it2;
		}
		cout << endl;

		// 范围for是由迭代器支持的，也就是说这段代码最终会被编译器替换成迭代器
		// iterator begin() end()
		for (auto e : s2)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_string2()
	{
		string s1("hello");
		s1.PushBack(' ');
		s1.PushBack('w');
		s1.PushBack('o');
		s1.Append("rld xxxxxxxxxxxxxxxxxxxxxxxxx");
		cout << s1 << endl;

		string s2;
		s2 += "hello";
		s2 += ' ';
		s2 += "world";
		cout << s2 << endl;
	}

	void test_string3()
	{
		string s1("hello");
		s1.insert(1, 'x');
		s1.insert(1, "xyz");
		//cout << s1 << endl;

		string s2("hello");
		s2.reserve(10);
		cout << s2 << endl;
		cout << s2.size() << endl;
		cout << s2.capacity() << endl << endl;

		s2.resize(8, 'x');
		cout << s2 << endl;
		cout << s2.size() << endl;
		cout << s2.capacity() << endl << endl;;

		s2.resize(18, 'a');
		cout << s2 << endl;
		cout << s2.size() << endl;
		cout << s2.capacity() << endl << endl;

		s2.resize(2);
		cout << s2 << endl;
		cout << s2.size() << endl;
		cout << s2.capacity() << endl << endl;
	}

	void test_string4()
	{
		string s1("helloworld");
		s1.erase(5, 2);
		cout << s1 << endl;

		s1.erase(5, 4);
		cout << s1 << endl;

		string s2("abcdabcdef");
		cout << s2.find("cde") << endl;
		cout << s2.find("cdex") << endl;
	}
};
