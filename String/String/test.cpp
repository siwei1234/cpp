#define _CRT_SECURE_NO_WARNINGS 1

//#include"String.hpp"
//#include"_string.hpp"
#include<iostream>
#include<string>
using namespace std;
//int main()
//{
//	string s("hello world");
//	cout << s.size() << endl;
//	cout << s.length() << endl;
//	cout << s.capacity() << endl;
//	s.clear();
//	s.resize(10, 'a');
//	s.resize(15);
//	s.resize(5);
//	return 0;
//}


//int main()
//{
//	string s1;
//	s1.reserve(100);
//	cout << s1.capacity() << endl;
//	s1.reserve(50);
//	cout << s1.capacity() << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	cout << s1 << endl;
//	s1[0] = 'w';
//	cout << s1 << endl;
//	return 0;
//}

int main()
{
	string s("hello world");

	for (size_t i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}

	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}

	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << endl;
		++rit;
	}

	string::const_iterator cit = s.begin();
	while (cit != s.end())
	{
		cout << *cit << endl;
		++cit;
	}

	for (auto e : s)
	{
		cout << e << endl;
	}
	return 0;
}

//int main()
//{
//	string s;
//	string s1("xyz");
//	s.push_back('a');
//	s.append("bcd");
//	s += 'e';
//	s += "fgh";
//	s.insert(0, s1);
//	//s.erase(0, 1);
//	cout << s << endl;
//	cout << s.c_str() << endl;
//	return 0;
//}

//int main()
//{
//	string s("test.txt");
//	size_t pos = s.rfind('.');
//	cout << s.substr(pos, s.size() - pos) << endl;
//	return 0;
//}

//int main()
//{
//	string s("http://www.cplusplus.com/reference/string/string/find/");
//	size_t pos = s.find("://");
//	pos += 3;
//	size_t pos1 = s.find('/', pos);
//	cout << s.substr(pos, pos1 - pos) << endl;
//	return 0;
//}


//int main()
//{
//	string s;
//	getline(cin, s);
//	cout << s;
//	/*cin >> s;
//	cout <<s;*/
//	/*string s1("baidu.com");
//	s = "www." + s1;
//	cout << s;*/
//	return 0;
//}