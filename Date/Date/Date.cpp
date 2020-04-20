#include "Date.h"
// ��ȡĳ��ĳ�µ�����
int Date::GetMonthDay(int year, int month)
{
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		a[2] = 29;
	}
	return a[month];
}
// ȫȱʡ�Ĺ��캯��
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
// �������캯��
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
// ��ֵ���������
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
// ��������
Date::~Date()
{
	_year = 0;
	_month = 0;
	_day = 0;
}
// ����+=����
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
// ����+����
Date Date::operator+(int day)
{
	Date d(*this);
	d += day;
	return d;
}
// ����-=����
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
// ����-����
Date Date::operator-(int day)
{
	Date d(*this);
	d -= day;
	return d;
}
// ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
// ����++
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}
// ����--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
// ǰ��--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
// >���������
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
// ==���������
bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}
// >=���������
bool Date::operator >= (const Date& d)
{
	return *this > d || *this == d;
}
// <���������
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}
// <=���������
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}
// !=���������
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}
// ����-���� ��������
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