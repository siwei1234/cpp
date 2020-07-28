#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;

//int main()
//{
//	int i = 10;
//	double d = 6.66;
//
//	i = d;
//	cout << i << endl;
//
//	int* p = nullptr;
//	p = (int*)i;
//
//	cout << p << endl;
//	return 0;
//}


//int main()
//{
//	double d = 6.66;
//
//	int i = static_cast<int>(d);
//	cout << i << endl;
//
//	return 0;
//}


//int main()
//{
//	const int i = 6;
//	int* p = const_cast<int*> (&i);
//	*p = 20;
//
//	cout << i << endl;
//	cout << *p << endl;
//	return 0;
//}


class A
{
public:
	virtual void func()
	{
		cout << "A::func()" << endl;
	}
	int a;
};

class B : public A
{
public:
	void func()
	{
		cout << "B::func()" << endl;
	}
};

void f_cast(A* pa)
{
	B* pb = dynamic_cast<B*>(pa);
	if (pb != nullptr)
	{
		pb->a = 10;
		cout << "转换成功" << endl;
	}
	else
		cout << "转换失败" << endl;
}

int main()
{
	A a;
	B b;

	A* pa = &a;
	f_cast(pa);

	pa = &b;
	f_cast(pa);
	return 0;
}