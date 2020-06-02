#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<vector>
#include "List.h"
using namespace std;

//int main()
//{
//	list<int> l1;
//	list<int> l2(4, 100);
//	list<int> l3(l2.begin(), l2.end());
//	list<int> l4(l3);
//	int nums[] = { 5,4,9,6,10 };
//	list<int> l5(nums, nums + sizeof(nums)/sizeof(int));
//	return 0;
//}

//int main()
//{
//	int nums[] = { 1,2,3,4,5,6,7,8,9 };
//	list<int> l(nums, nums + sizeof(nums) / sizeof(int));
//
//	list<int>::iterator it = l.begin();
//	while(it != l.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	list<int>::reverse_iterator rit = l.rbegin();
//	while (rit != l.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//
//	list<int>::const_iterator cit = l.begin();
//	while (cit != l.end())
//	{
//		cout << *cit << " ";
//		cit++;
//	}
//	cout << endl;
//	return 0;
//}


//int main()
//{
//	list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.size();
//	l.front();
//	l.back();
//
//	l.push_front(0);
//	l.push_front(-1);
//
//	l.pop_back();
//
//	l.pop_front();
//
//	auto pos = ++l.begin();
//	l.insert(pos, 10);
//	vector<int> v{ 1,2,3 };
//	l.insert(pos, v.begin(), v.end());
//
//	l.erase(pos);
//	l.erase(l.begin(), l.end());
//
//	list<int> l2(4, 1);
//	l2.swap(l);
//
//	l2.clear();
//
//	l2.empty();
//	return 0;
//}


int main()
{
	int nums[] = { 1,2,3,4,5,6,7,8,9 };
	list<int> l(nums, nums + sizeof(nums) / sizeof(int));

	/*auto it = l.begin();
	while (it != l.end())
	{
		l.erase(it);
		it++;
	}*/

	auto it = l.begin();
	while (it != l.end())
	{
		l.erase(it++);
	}
	return 0;
}