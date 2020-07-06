#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


/*template <class T, size_t N = 10>
class array
{

private:
	T _array[N];
};*/

//template<class T>
//bool isequal(T& left, T& right)
//{
//	return left == right;
//}
//template<>
//bool isequal<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) == 0)
//		return true;
//	return false;
//}
//bool isequal(char*& left, char*& right)
//{
//	if (strcmp(left, right) == 0)
//		return true;
//	return false;
//}
//int main()
//{
//	char* p1 = new char[6]{ "hello" };
//	char* p2 = new char[6]{ "hello" };
//	cout << isequal(p1, p2) << endl;
//	return 0;
//}

//template<class T1, class T2>
//class A
//{
//public:
//	A()
//	{
//		cout << "A<T1£¬ T2>" << endl;
//	}
//private:
//	T1 _a;
//	T2 _b;
//};
//
//template<class T1, class T2>
//class A<T1*, T2*>
//{
//public:
//	A()
//	{
//		cout << "A<T1*£¬ T2*>" << endl;
//	}
//private:
//	T1* _a;
//	T2* _b;
//};
//
//template<class T1, class T2>
//class A<T1&, T2&>
//{
//public:
//	A()
//	{
//		cout << "A<T1&£¬ T2&>" << endl;
//	}
//private:
//	T1& _a;
//	T2& _b;
//};

//template<class T1>
//class A<T1, int>
//{
//public:
//	A()
//	{
//		cout << "A<T1£¬ int>" << endl;
//	}
//private:
//	T1 _a;
//	int _b;
//};
//
//template<class T2>
//class A<int, T2>
//{
//public:
//	A()
//	{
//		cout << "A<int£¬ T2>" << endl;
//	}
//private:
//	class _a;
//	T2 _b;
//};

//template<> 
//class A<int, int>
//{
//public:
//	A()
//	{
//		cout << "A<int£¬ int>" << endl;
//	}
//private:
//	int _a;
//	int _b;
//};
//
//int main()
//{
//	/*A<char, int> d1;
//	A<int, char> d2;*/
//
//	A<char*, char*> d;
//	return 0;
//
//}

template<class T>
bool isequal(T& left, T& right);


template<class T>
bool isequal(T& left, T& right)
{
	return left == right;
}


int main()
{
	int a = 0;
	int b = 0;
	isequal(a, b);
}