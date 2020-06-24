#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include "AVLTree.h"
using namespace std;

int main()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}

	t.InOrder();
	cout << t.IsBalance() << endl;
	return 0;
}