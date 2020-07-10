#define _CRT_SECURE_NO_WARNINGS 1

//#include"set.h"
//#include"map.h"

#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;

//int main()
//{
//	Map::test_map();
//	return 0;
//}

//template <class K, class V>
//struct pair
//{
//	K first;
//	V second;
//	pair()
//		:first(K())
//		,second(V())
//	{}
//	pair(const K& a, cosnt V& b)
//		:first(a)
//		, second(b)
//	{}
//};

//int main()
//{
//	set<int> s1;
//	set<int> s2{ 1,2,3,4,5,6 };
//	set<int> s3(s2);
//	return 0;
//}


//int main()
//{
//	set<int> s{ 1,2,3,4,5,6 };
//	set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	
//	set<int>::const_iterator cit = s.cbegin();
//	while (cit != s.cend())
//	{
//		cout << *cit << endl;
//		cit++;
//	}
//
//	set<int>::reverse_iterator rit = s.rbegin();
//	while (rit != s.rend())
//	{
//		cout << *rit << endl;
//		rit++;
//	}
//	return 0;
//}


//int main()
//{
//	set<int> s;
//	s.insert(1);
//	s.insert(4);
//	s.insert(2);
//	s.insert(5);
//
//	s.erase(1);
//
//	s.size();
//	set<int>::iterator ret = s.find(4);
//	cout << *ret << endl;
//	s.clear();
//
//	s.empty();
//	return 0;
//}

//int main()
//{
//	map<int, int> m;
//	m.insert(make_pair(1, 12));
//	m.insert(make_pair(2, 12));
//	m.insert(make_pair(3, 15));
//	m.insert(make_pair(4, 102));
//	
//	map<int, int>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		cout << it->first << ":" << it->second << endl;
//		it++;
//	}
//	cout << endl;
//
//	map<int, int>::const_iterator cit = m.cbegin();
//	while (cit != m.cend())
//	{
//		cout << cit->first << ":" << cit->second << endl;
//		cit++;
//	}
//	cout << endl;
//
//	map<int, int>::reverse_iterator rit = m.rbegin();
//	while (rit != m.rend())
//	{
//		cout << rit->first << ":" << rit->second << endl;
//		rit++;
//	}
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	map<int, int> m;
//	m.insert(pair<int, int>(1, 12));
//	m.insert(pair<int, int>(2, 12));
//	m.insert(make_pair(3, 15));
//	m.insert(make_pair(4, 102));
//
//	m.erase(1);
//	m.size();
//	map<int, int>::iterator ret = m.find(4);
//	cout << ret->first << ":" << ret->second << endl;
//	m.clear();
//	m.empty();
//	return 0;
//}