#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//class student
//{
//public:
//	void Init(const char* name, const int age)
//	{
//		strcpy(_name, name);
//		_age = age;
//	}
//	void Print();
//private:
//	char _name[10];
//	int _age;
//};
//void student::Print()
//{
//	cout << _name << " " << _age << endl;
//}
//int main()
//{
//	student s;
//	s.Init("jack", 18);
//	s.Print();
//	return 0;
//}


//class A1
//{
//public:
//	void f();
//private:
//	int _a;
//};
//
//class A2
//{
//public:
//	void f();
//};
//
//class A3
//{};
//int main()
//{
//	cout << sizeof(A1) << endl;
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour = 10)
//	{
//		_hour = hour;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << endl;
//		cout << _month << endl;
//		cout << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	d1.Print();
//	return 0;
//}

//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		_a = (int*)malloc(sizeof(int)*capacity);
//		_capacity = capacity;
//		_size = 0;
//	}
//	~SeqList()
//	{
//		free(_a);
//		_a = nullptr;
//		_capacity = 0;
//		_size = 0;
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	SeqList s;
//	return 0;
//}



//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	bool operator>(const Date& d)
//	{
//		if (_year > d._year)
//			return true;
//		if (_year == d._year && _month > d._month)
//			return true;
//		if (_year == d._year && _month == d._month && _day > d._day)
//			return true;
//		return false;
//	}
//	bool operator==(const Date& d)
//	{
//		return _year == d._year && _month == d._month && _day == d._day;
//	}
//	bool operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._year;
//		_day = d._day;
//	}
//	void Print()
//	{
//		cout << _year << endl;
//		cout << _month << endl;
//		cout << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
//}
//int main()
//{
//	Date d1;
//	Date d2 = d1;
//	cout << (d1 == d2) << endl;
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	bool operator>(const Date& d)
//	{
//		if (_year > d._year)
//			return true;
//		if (_year == d._year && _month > d._month)
//			return true;
//		if (_year == d._year && _month == d._month && _day > d._day)
//			return true;
//		return false;
//	}
//	void Print() const
//	{
//		cout << _year << '-' << _month << '-' << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//
//int main()
//{
//	const Date d1;
//	d1.Print();
//	return 0;
//}

//class Date
//{
//public:
//	/*Date* operator&()
//	{
//		return this;
//	}*/
//	const Date* operator&() const
//	{
//		return this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	const Date d2;
//	cout << &d1 << endl;
//	cout << &d2 << endl;
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class B
//{
//public:
//	B(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//class A
//{
//public:
//	A(int a, int b, int c)
//		:_a(a)
//		,_b(b)
//		,_c(c)
//	{}
//private:
//	B _a;
//	const int _b;
//	int& _c;
//};

//int main()
//{
//	A a(1, 2, 3);
//	return 0;
//}

//class Date
//{
//public:
//	explicit Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d = 10;
//	return 0;
//}

//class Date
//{
//public:
//	static int GetN()
//	{
//		return _n;
//	}
//private:
//	static int _n;
//};
//int Date::_n = 0;
//
//int main()
//{
//	Date d;
//	cout << d.GetN() << endl;
//	cout << Date::GetN() << endl;
//	return 0;
//}


//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//private:
//	int _b;
//};
//class A
//{
//private:
//	int _a = 1;
//	B _b = 2;
//};
//
//int main()
//{
//	A a;
//	return 0;
//}


//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << '-' << d._month << '-' << d._day << endl;
//	return out;
//}
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d;
//	return 0;
//}


//class Time
//{
//	friend class Date;
//public:
//	Time(int hour = 10)
//		:_hour(hour)
//	{}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTime(int hour)
//	{
//		_t._hour = hour;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};


//class A
//{
//private:
//	static int _n;
//	int _a;
//public:
//	A(int a = 10)
//		:_a(a)
//	{}
//	class B
//	{
//	public:
//		void func(const A& a)
//		{
//			cout << _n << endl;
//			cout << a._a << endl;
//		}
//	};
//};
//int A::_n = 1;
//int main()
//{
//	A c(100);
//	A::B b;
//	b.func(A());
//	return 0;
//}



class A
{
public:
	int sum(int n)
	{
		cout << n << endl;
		return n;
	}
};
int main()
{
	A a;
	a.sum(20);
	A().sum(10);
	return 0;
}

