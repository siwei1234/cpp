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
//	//�������
//	s.insert(1);
//	s.insert(4);
//	s.insert(2);
//	s.insert(5);
//	//ɾ��ֵΪ1��Ԫ��
//	s.erase(1);
//	//��ЧԪ�ظ���
//	s.size();
//	//����ֵΪ4��Ԫ��
//	unordered_set<int>::iterator ret = s.find(4);
//	cout << *ret << endl;
//	//��ռ���
//	s.clear();
//	//�пղ���
//	s.empty();
//
//
//	unordered_set<int> s1{ 1,2,3,4,5,6 };
//	//���������
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
	//�Լ���ʾ����pair����
	m.insert(pair<int, int>(1, 12));
	m.insert(pair<int, int>(2, 12));
	//ʹ��make_pair��������
	m.insert(make_pair(3, 15));
	m.insert(make_pair(4, 102));
	//ɾ��keyֵΪ1��Ԫ��
	m.erase(1);
	//��ЧԪ�ظ���
	m.size();
	//����keyֵΪ4��Ԫ��
	unordered_map<int, int>::iterator ret = m.find(4);
	cout << ret->first << ":" << ret->second << endl;
	//��ռ���
	m.clear();
	//�пղ���
	m.empty();


	unordered_map<int, int> m1;
	m1.insert(make_pair(1, 12));
	m1.insert(make_pair(2, 12));
	m1.insert(make_pair(3, 15));
	m1.insert(make_pair(4, 102));
	//���������
	unordered_map<int, int>::iterator it = m1.begin();
	while (it != m1.end())
	{
		cout << it->first << ":" << it->second << endl;
		it++;
	}
	cout << endl;
	return 0;
}
