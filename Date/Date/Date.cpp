#include "Date.h"
// 获取某年某月的天数
int Date::GetMonthDay(int year, int month)
{
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		a[2] = 29;
	}
	return a[month];
}
// 全缺省的构造函数
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
// 拷贝构造函数
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
// 赋值运算符重载
// d2 = d3 -> d2.operator=(&d2, d3)
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
// 析构函数
Date::~Date()
{
	_year = 0;
	_month = 0;
	_day = 0;
}
// 日期+=天数
Date& Date::operator+=(int day)
{
	if (day < 0)
		return *this -= (-day);
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}
// 日期+天数
Date Date::operator+(int day)
{
	Date d(*this);
	d += day;
	return d;
}
// 日期-=天数
Date& Date::operator-=(int day)
{
	if (day < 0)
		return (*this) += (-day);
	_day -= day;
	while (_day <= 0)
	{
		if (--_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
// 日期-天数
Date Date::operator-(int day)
{
	Date d(*this);
	d -= day;
	return d;
}
// 前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
// 后置++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}
// 后置--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
// 前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
// >运算符重载
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	if (_year == d._year && _month > d._month)
		return true;
	if (_year == d._year && _month == d._month && _day > d._day)
		return true;
	return false;
}
// ==运算符重载
bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}
// >=运算符重载
bool Date::operator >= (const Date& d)
{
	return *this > d || *this == d;
}
// <运算符重载
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}
// <=运算符重载
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}
// !=运算符重载
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}
// 日期-日期 返回天数
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	int n = 0;
	if (min > max)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	while (max != min)
	{
		min++;
		n++;
	}
	return n;
}
void Date::Print()
{
	cout << _year << '-' << _month << '-' << _day << endl;
}