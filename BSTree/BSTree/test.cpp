#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include "BSTree.h"
using namespace std;

int main()
{
	BSTree<string, string> dict;
	dict.Insert("sort", "ÅÅÐò");
	dict.Insert("string", "×Ö·û´®");
	dict.Insert("tree", "Ê÷");
	dict.Insert("insert", "²åÈë");
	vector<string> strArr = { "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Ïã½¶", "Î÷¹Ï", "Ó£ÌÒ", "Î÷¹Ï", "Î÷¹Ï" };
	BSTree<string, int> countTree;
	for (auto str : strArr)
	{
		BSTreeNode<string, int>* ret = countTree.Find(str);
		if (ret == nullptr)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}

	countTree.InOrder();
	return 0;
}