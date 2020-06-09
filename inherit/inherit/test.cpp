#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//class Person
//{
//protected:
//	string _name = "jack";
//	int _age = 20;
//};
//
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//		cout << _age << endl;
//	}
//protected:
//	int _age = 21;
//};

//int main()
//{
//	Student s;
//	s.Print();
//	return 0;
//}

//int main()
//{
//	Student s;
//	Person p1 = s;
//	Person* p2 = &s;
//	Person& p3 = s;
//
//	Student* s1 = (Student*)p2;
//	return 0;
//}

//int main()
//{
//	Student s;
//	s.Print();
//	return 0;
//}

//class A
//{
//public:
//	void func()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void func(int i)
//	{
//		A::func();
//		cout << "func(int)" << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	b.func(1);
//	return 0;
//}

//class Person
//{
//public:
//	Person(const char* name = "jack")
//		:_name(name)
//	{}
//	Person(const Person& p)
//		:_name(p._name)
//	{}
//	Person& operator=(const Person& p)
//	{
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//	~Person()
//	{
//		_name = "";
//	}
//protected:
//	string _name;
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name = "jack", int id = 111)
//		:Person(name)
//		, _id(id)
//	{}
//	Student(const Student& s)
//		:Person(s)
//		, _id(s._id)
//	{}
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			_id = s._id;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		_id = 0;
//	}
//protected:
//	int _id;
//};

//class Person
//{
//public:
//	static int _num;
//protected:
//	string _name;
//};
//int Person::_num = 0;
//
//class Student : public Person
//{
//protected:
//	int _id;
//};
//
//int main()
//{
//	Student s;
//	Student::_num = 10;
//	cout << Person::_num << endl;
//}


//class A
//{
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d._a = 10;
//	return 0;
//}


class A
{
public:
	int _a;
};

class B : public A
{
public:
	int _b;
};

class C
{
public:
	int _c;
};

class D
{
public:
	int _d;
	C _c;
};