#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//try
//{
//	//�����ı�ʶ����
//}
//catch(ExceptionName e1)
//{
//	//catch ��
//}
//
//catch (ExceptionName e1)
//{
//	//catch ��
//}

//int func(int m, int n)
//{
//	if (n == 0)
//	{
//		throw string("��0����");
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
//		cout << "δ֪����" << endl;
//	}
//	return 0;
//}

//int func1(int m, int n) throw(string, int)
//{
//	if (n == 0)
//	{
//		throw string("��0����");
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
	int _errid;       // ������
	string _errmsg;   // ��������
};

class SqlException : public Exception
{
public:
	SqlException(const char* errmsg, int errid)
		:Exception(errmsg, errid)
	{}

	virtual string what()
	{
		return "���ݿ����:" + _errmsg;
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
		return "�������:" + _errmsg;
	}
};

void ServerStart(int i)
{
	if (i % 3 == 0)
		throw SqlException("���ݿ�����ʧ��", 1);

	if (i % 3 == 1)
		throw NetworkException("��������ʧ��", 3);

	cout << "��������" << endl;
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
			cout << "δ֪�쳣" << endl;
		}
	}
	return 0;
}