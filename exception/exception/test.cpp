#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//try
//{
//	//保护的标识代码
//}
//catch(ExceptionName e1)
//{
//	//catch 块
//}
//
//catch (ExceptionName e1)
//{
//	//catch 块
//}

//int func(int m, int n)
//{
//	if (n == 0)
//	{
//		throw string("除0错误");
//	}
//	return m / n;
//}
//int main()
//{
//	try
//	{
//		int m = 10, n = 0;
//		cout << func(m, n) << endl;
//	}
//	catch (const string& e)
//	{
//		cout << e << endl;
//	}
//	catch (...)
//	{
//		cout << "未知错误" << endl;
//	}
//	return 0;
//}

//int func1(int m, int n) throw(string, int)
//{
//	if (n == 0)
//	{
//		throw string("除0错误");
//	}
//	return m / n;
//}
//
//int func2()
//{
//	int* a = new int[10];
//	try
//	{
//		int m = 10, n = 0;
//		cout << func1(m, n) << endl;
//	}
//	catch(...)
//	{
//		delete[] a;
//		throw;
//	}
//}
//
//int main()
//{
//	try
//	{
//		func2();
//	}
//	catch (string& e)
//	{
//		cout << e << endl;
//	}
//	return 0;
//}


class Exception
{
public:
	Exception(const char* errmsg, int errid)
		: _errmsg(errmsg)
		, _errid(errid)
	{}

	virtual string what() = 0;
protected:
	int _errid;       // 错误码
	string _errmsg;   // 错误描述
};

class SqlException : public Exception
{
public:
	SqlException(const char* errmsg, int errid)
		:Exception(errmsg, errid)
	{}

	virtual string what()
	{
		return "数据库错误:" + _errmsg;
	}
};

class NetworkException : public Exception
{
public:
	NetworkException(const char* errmsg, int errid)
		:Exception(errmsg, errid)
	{}

	virtual string what()
	{
		return "网络错误:" + _errmsg;
	}
};

void ServerStart(int i)
{
	if (i % 3 == 0)
		throw SqlException("数据库启动失败", 1);

	if (i % 3 == 1)
		throw NetworkException("网络连接失败", 3);

	cout << "正常运行" << endl;
}

int main()
{
	for (size_t i = 0; i < 100; i++)
	{
		try
		{
			ServerStart(i);
		}
		catch (Exception& e)
		{
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "未知异常" << endl;
		}
	}
	return 0;
}