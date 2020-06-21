#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include "BSTree.h"
using namespace std;

int main()
{
	BSTree<string, string> dict;
	dict.Insert("sort", "����");
	dict.Insert("string", "�ַ���");
	dict.Insert("tree", "��");
	dict.Insert("insert", "����");
	vector<string> strArr = { "����", "ƻ��", "����", "ƻ��", "����", "�㽶", "����", "ӣ��", "����", "����" };
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