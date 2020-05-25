#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
class String
{
public:
	String(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}
	/*String(const String& s)
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}*/
	String(const String &s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}
	/*String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* tmp = new char[strlen(s._str) + 1];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
		}
		return *this;
	}*/
	/*String& operator=(const String& s)
	{
		if (this != &s)
		{
			String tmp(s._str);
			swap(_str, tmp._str);
		}
		return *this;
	}*/
	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	~String()
	{
		delete[] _str;
		_str = nullptr;
	}
	void testString()
	{
		String s1("hello");
		String s2 = s1;
		String s3;
		s3 = s1;
	}
private:
	char *_str;
};
