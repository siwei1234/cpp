#define _CRT_SECURE_NO_WARNINGS 1

#include "RBTree.h"
int main()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RETree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	t.InOrder();
	auto ret = t.Find(4);
	cout << (ret)->_kv.first << ":" << (ret)->_kv.second << endl;
	return 0;
}