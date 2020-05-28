#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;

//int main()
//{
//	vector<int> v1;	//无参构造
//	vector<int> v2(5, 1);	//构造并初始化5个1
//	vector<int> v3(v2.begin(), v2.end());	//使用迭代器进行初始化化构造
//	vector<int> v4(v3);	//拷贝构造
//	return 0;
//}

//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i];
//	}
//	cout << endl;
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it;
//		it++;
//	}
//	cout << endl;
//
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit;
//		rit++;
//	}
//	cout << endl;
//
//	vector<int>::const_iterator cit = v.begin();
//	while (cit != v.end())
//	{
//		cout << *cit;
//		cit++;
//	}
//	cout << endl;
//
//	for (auto e : v)
//	{
//		cout << e;
//	}
//	return 0;
//}

//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//	cout << v.empty() << endl;
//
//	v.resize(10);
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;	
//
//	v.reserve(100);
//	cout << v.size() << endl;
//	cout << v.capacity() << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//
//	v.pop_back();
//
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//
//	v.insert(pos, 20);
//
//	pos = find(v.begin(), v.end(), 20);
//	v.erase(pos);
//
//	return 0;
//}

//int main()
//{
//	vector<int> v{ 1,2,3,4,5,6 };
//	vector<int>::iterator it = v.begin();
//
//	v.push_back(7);
//	/*
//	while (it != v.end())
//	{
//		cout << *it;
//		it++;
//	}*/
//
//	it = v.begin();
//
//	while (it != v.end())
//	{
//		cout << *it;
//		it++;
//	}
//	return 0;
//}

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8 };
	/*auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			v.erase(it);
		else
			it++;
	}*/

	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			it++;
	}
	return 0;
}