#include<iostream>
using namespace std;

//int test()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'c';
//	auto d = test();
//
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	return 0;
//}


//int main()
//{
//	int x = 10;
//	auto pa = &x;
//	auto* pb = &x;
//	auto& rx = x;
//	cout << typeid(pa).name() << endl;
//	cout << typeid(pb).name() << endl;
//	cout << typeid(rx).name() << endl;
//
//	return 0;
//}

//int main()
//{
//	auto a = 1, b = 2;
//	//auto c = 1, d = 1.1;	这一行会报错
//	return 0;
//}

//void tesr(int arr[])
//{
//	for (auto& e : arr)
//		e *= 2;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	for (auto& e : arr)
//		e *= 2;
//	for (auto e : arr)
//		cout << e << endl;
//	return 0;
//}


void f(int)
{
	cout << "int" << endl;
}

void f(int*)
{
	cout << "int*" << endl;
}

int main()
{
	f(0);
	f(NULL);
	f(nullptr);
	return 0;
}