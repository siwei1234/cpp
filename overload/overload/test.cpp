#include<iostream>
using namespace std;

//void func(int a = 0)
//{
//	cout << a << endl;
//}
//
//void func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//
//}
//int main()
//{
//	func();
//	func(10);
//	func1();
//	func1(1);
//	func1(1, 2);
//	func1(1, 2, 3);
//	return 0;
//}



int add(int a, int b)
{
	return a + b;
}
int add(int a, int b, int c)
{
	return a + b + c;
}
double add(int a, double b)
{
	return a + b;
}
double add(double a, int b)
{
	return a + b;
}
int main()
{
	cout << add(1, 2) << endl;
	cout << add(1, 2, 3) << endl;
	cout << add(1, 2.2) << endl;
	cout << add(1.1, 2) << endl;
	return 0;
}
