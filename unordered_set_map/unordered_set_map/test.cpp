#define _CRT_SECURE_NO_WARNINGS 1
//#include"HashTable.h"
//#include"UnorderedSet.h"
//#include"UnorderedMap.h"
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//int main()
//{
//	
//	UnorderedMap::test_unordered_map();
//	return 0;
//}


//int main()
//{
//	unordered_set<int> s;
//	//插入操作
//	s.insert(1);
//	s.insert(4);
//	s.insert(2);
//	s.insert(5);
//	//删除值为1的元素
//	s.erase(1);
//	//有效元素个数
//	s.size();
//	//查找值为4的元素
//	unordered_set<int>::iterator ret = s.find(4);
//	cout << *ret << endl;
//	//清空集合
//	s.clear();
//	//判空操作
//	s.empty();
//
//
//	unordered_set<int> s1{ 1,2,3,4,5,6 };
//	//正向迭代器
//	unordered_set<int>::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	return 0;
//}


int main()
{
	unordered_map<int, int> m;
	//自己显示定义pair插入
	m.insert(pair<int, int>(1, 12));
	m.insert(pair<int, int>(2, 12));
	//使用make_pair函数插入
	m.insert(make_pair(3, 15));
	m.insert(make_pair(4, 102));
	//删除key值为1的元素
	m.erase(1);
	//有效元素个数
	m.size();
	//查找key值为4的元素
	unordered_map<int, int>::iterator ret = m.find(4);
	cout << ret->first << ":" << ret->second << endl;
	//清空集合
	m.clear();
	//判空操作
	m.empty();


	unordered_map<int, int> m1;
	m1.insert(make_pair(1, 12));
	m1.insert(make_pair(2, 12));
	m1.insert(make_pair(3, 15));
	m1.insert(make_pair(4, 102));
	//正向迭代器
	unordered_map<int, int>::iterator it = m1.begin();
	while (it != m1.end())
	{
		cout << it->first << ":" << it->second << endl;
		it++;
	}
	cout << endl;
	return 0;
}
