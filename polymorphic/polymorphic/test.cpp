#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;



//class person
//{
//public:
//	virtual person* Buy()
//	{
//		cout << "��ͨ��ȫ��" << endl;
//		return new person;
//	}
//};
//
//class student : public person
//{
//public:
//	virtual student* Buy()
//	{
//		cout << "ѧ�����" << endl;
//		return new student;
//	}
//};
//
//
//void value(person& p)
//{
//	p.Buy();
//}
//int main()
//{
//	person p;
//	student s;
//	value(p);
//	value(s);
//	return 0;
//}


//class person
//{
//public:
//	virtual ~person()
//	{
//		cout << "~person()" << endl;
//	}
//};
//
//class student : public person
//{
//public:
//	~student()
//	{
//		cout << "~student()" << endl;
//	}
//};

//int main()
//{
//	person* p = new person;
//	person* s = new student;
//	delete p;
//	delete s;
//	return 0;
//}

//class person
//{
//public:
//	virtual void Buy() final
//	{
//		cout << "��ͨ��ȫ��" << endl;
//	}
//};
//
//class student : public person
//{
//public:
//	//virtual void Buy()
//	//{
//	//	cout << "ѧ�����" << endl;
//	//}
//};
//
//class person
//{
//public:
//	//virtual void Buy()
//	//{
//	//	cout << "��ͨ��ȫ��" << endl;
//	//}
//};
//
//class student : public person
//{
//public:
//	virtual void Buy() override
//	{
//		cout << "ѧ�����" << endl;
//	}
//};

//class person
//{
//public:
//	virtual void Buy() = 0;
//};

//class student : public person
//{
//public:
//	virtual void Buy()
//	{
//		cout << "ѧ�����" << endl;
//	}
//};
//
//class soldier : public person
//{
//public:
//	virtual void Buy()
//	{
//		cout << "��������-���" << endl;
//	}
//};

//class person
//{
//public:
//	virtual void Buy()
//	{
//		cout << "��ͨ��ȫ��" << endl;
//	}
//};
//
//class student : public person
//{
//public:
//	virtual void Buy()
//	{
//		cout << "ѧ�����" << endl;
//	}
//};
//
//int main()
//{
//	person p;
//	student s;
//	return 0;
//}

//int main()
//{
//	person* s = new student;
//	person* s1 = new soldier;
//	s->Buy();
//	s1->Buy();
//	return 0;
//}

//class A
//{
//public:
//	virtual void func1()
//	{}
//	virtual void func2()
//	{}
//};
//
//class B : public A
//{
//public:
//	virtual void func1()
//	{}	
//	virtual void func3()
//	{}	
//	virtual void func4()
//	{}
//};
//
//int main()
//{
//	A a;
//	B b;
//	return 0;
//}


class A
{
public:
	virtual void func1()
	{}
	virtual void func2()
	{}
};

class B
{
public:
	virtual void func1()
	{}
	virtual void func2()
	{}
};

class C : public A, public B
{
	virtual void func1()
	{}
	virtual void func3()
	{}
};


int main()
{
	C c;
	return 0;
}