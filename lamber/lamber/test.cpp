#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

//int main()
//{
//	//�������ͱ���
//	int a1 = { 10 };
//	int a2(10);
//	int a3 = 1 + 1;
//	int a4 = { 1 + 1 };
//	int a5{ 1 + 1 };
//	//����
//	int arr1[5]{ 1,2,3,4,5 };
//	int arr2[]{ 1,2,3,4,5 };
//	//��̬����
//	int* arr3 = new int[5]{ 1,2,3,4,5 };
//	//��׼����
//	vector<int> v{ 1,2,3,4,5 };
//	map<int, int> m{ {1,1},{2,2},{3,3} };
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d{ 2020,1,1 };
//	return 0;
//}

#include <initializer_list>
//template<class T>
//class Vector
//{
//public:
//	Vector(initializer_list<T> l)
//		:_capacity(l.size())
//		,_size(0)
//	{
//		_array = new T[_capacity];
//		for (auto e : l)
//			_array[_size++] = e;
//	}
//
//	Vector<T>& operator=(initializer_list<T> l)
//	{
//		delete[] _array;
//		size_t i = 0;
//		for (auto e : l)
//			_array[i++] = e;
//		return *this;
//	}
//private:
//	T* _array;
//	size_t _size;
//	size_t _capacity;
//};
//
//int main()
//{
//	Vector<int> nums = { 1,2,3,4 };
//	nums = { 2,3,4 };
//	return 0;
//}

//int main()
//{
//	double a = 10;
//	int b = 10;
//	decltype(a + b) c;
//	cout << typeid(c).name() << endl;
//	return 0;
//}

//void* func(size_t n)
//{
//	return malloc(n);
//}
//
//int main()
//{
//	cout << typeid(decltype(func)).name() << endl;
//	cout << typeid(decltype(func(0))).name() << endl;
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//	//��ʽȱʡ���캯�����ɱ���������
//	A() = delete;
//
//	A& operator=(const A& a) = delete;
//private:
//	int _a;
//};
//
//int main()
//{
//	A a1(10);
//	//����ʧ�ܣ���Ϊû��Ĭ�Ϲ��캯��
//	//A a2;
//	//����ʧ�ܣ���Ϊû�и�ֵ���������
//	//a2 = a1;
//	return 0;
//}


//int add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int&& ra = 10;
//	int&& ret = add(1, 2);
//	return 0;
//}

//
//int g_a = 10;
//// �����ķ���ֵ���Ϊ����,����ֵ
//int& GetG_A()
//{
//	return g_a;
//}
//
////�����ķ���ֵ����ʱ����������ֵ
//int Get()
//{
//	return g_a;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	// a��b������ֵ��b�ȿ�����=����࣬Ҳ�����Ҳ࣬
//	// ˵������ֵ�ȿɷ���=����࣬Ҳ�ɷ���=���Ҳ�
//	a = b;
//	b = a;
//
//	const int c = 30;
//	// ����ʧ�ܣ�cΪconst������ֻ���������޸�
//	//c = a;
//	// ��Ϊ���Զ�cȡ��ַ�����c�ϸ���˵��������ֵ
//	cout << &c << endl;
//
//	// ����ʧ�ܣ���Ϊb+1�Ľ����һ����ʱ������û�о������ƣ�Ҳ����ȡ��ַ�����Ϊ��ֵ
//	//b + 1 = 20;
//
//	GetG_A() = 100;
//
//	int ret = Get();
//	return 0;
//}


int mian()
{
	int a = 10;

	return 0;
}

//int main()
//{
//	int x = 1, y = 2;
//	
//	// ��ֵ���õĶ���
//	int a = 0;
//	int& b = a;
//
//	// ��ֵ���ò���������ֵ, const��ֵ���ÿ���
//	//int& e = 10; 
//	//int& f = x + y;
//	const int& e = 10;
//	const int& f = x + y;
//
//
//	// ��ֵ���õĶ���
//	int&& c = 10;
//	int&& d = x + y;
//
//	// ��ֵ���ò���������ֵ�����ǿ�������move����ֵ
//	//int&& m = a;
//	int&& m = move(a);
//
//	return 0;
//}


//int func(int& a)
//{
//	return a;
//}
//
//int func(int&& a)
//{
//	return a;
//}
//int main()
//{
//	int a = 10;
//	func(a);
//	func(10);
//	return 0;
//}


//class String
//{
//public:
//	String(const char* str = "")
//	{
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	// s2(s1)
//	String(const String& s)
//	{
//		cout << "String(const String& s)-��������-Ч�ʵ�" << endl;
//
//		_str = new char[strlen(s._str) + 1];
//		strcpy(_str, s._str);
//	}
//
//	// s3(��ֵ-����ֵ)
//	String(String&& s)
//		:_str(nullptr)
//	{
//		// ����������һ������ֵ�������㶼Ҫ���ˣ��ҵ�Ŀ���Ǹ�����һ����Ŀռ䣬һ����ֵ
//		// �������Ŀ��ƺ�ֻ����
//		cout << "String(String&& s)-�ƶ�����-Ч�ʸ�" << endl;
//		swap(_str, s._str);
//	}
//
//	// s3 = s4
//	String& operator=(const String& s)
//	{
//		cout << "String& operator=(const String& s)-������ֵ-Ч�ʵ�" << endl;
//
//		if (this != &s)
//		{
//			char* newstr = new char[strlen(s._str) + 1];
//			strcpy(newstr, s._str);
//
//			delete[] _str;
//			_str = newstr;
//		}
//
//		return *this;
//	}
//
//	// s3 = ��ֵ-����ֵ
//	String& operator=(String&& s)
//	{
//		cout << "String& operator=(String&& s)-�ƶ���ֵ-Ч�ʸ�" << endl;
//		swap(_str, s._str);
//
//		return *this;
//	}
//
//
//	~String()
//	{
//		delete[] _str;
//	}
//
//	// s1 + s2
//	String operator+(const String& s2)
//	{
//		String ret(*this);
//		//ret.append(s2);
//
//		return ret;  // ���ص�����ֵ
//	}
//
//	// s1 += s2
//	String& operator+=(const String& s2)
//	{
//		//this->append(s2);
//		return *this; // ��������ֵ
//	}
//
//private:
//	char* _str;
//};
//String f(const char* str)
//{
//	String tmp(str);
//	return tmp; // ���ﷵ��ʵ���ǿ���tmp����ʱ����
//}
//
//int main()
//{
//	String s1("��ֵ");
//	String s2(s1);                      // ��������ֵ
//	String s3(f("��ֵ-����ֵ"));        // ��������ֵ-����ֵ(���ݸ����ã������Ҿ�������)
//
//	String s5("��ֵ");
//	s5 = s1;
//	s5 = f("��ֵ-����ֵ");
//
//	return 0;
//}


//void Fun(int &x) { cout << "��ֵ" << endl; }
//void Fun(const int &x) { cout << "const ��ֵ" << endl; }
//void Fun(int &&x) { cout << "��ֵ" << endl; }
//void Fun(const int&& x) { cout << "const ��ֵ" << endl; }
//
//template<typename T>
//void func(T &&t)
//{
//	// ��ֵ���û�ڶ���֮��Ĳ������ݹ�������ֵ���Զ�ʧ,��һ����û�ȫ��ʶ��Ϊ��ֵ
//	// ����ת�����
//	Fun(t);
//}
//
//int main()
//{
//	func(10); // rvalue ref
//
//	int a;
//	func(a); // lvalue ref
//	func(move(a)); // rvalue ref
//
//	const int b = 8;
//	func(b); // const lvalue ref
//	func(std::move(b)); // const rvalue ref
//
//
//	return 0;
//}

//struct Goods
//{
//	string _name;
//	double _price;
//};
//
//
//
//int main()
//{
//	Goods gds[] = { { "ƻ��", 2.1 }, { "�ཻ", 3 }, { "����", 2.2 }, {"����", 1.5} };
//	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods& g1, const Goods& g2)->bool
//		{
//		return g1._price < g2._price;
//		});
//	return 0;
//}


//int main()
//{
//	int a = 5, b = 7;
//	auto add1 = [a, b]()->int {return a + b; };
//	int ret1 = add1();
//	auto add2 = [=]()->int {return a + b; };
//	int ret2 = add2();
//	auto swap1 = [&a, &b]() {int z = a; a = b; b = z; };
//	swap1();
//	auto swap2 = [&]() {int z = a; a = b; b = z; };
//	swap2();
//	auto swap3 = [](int& x, int& y) {int t = x; x = y; y = t; };
//	swap3(a, b);
//	return 0;
//}

#include<thread>
#include<mutex>
#include<atomic>


//mutex mtx;
//int x = 0;
//
//void add(int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		++x;
//	}
//}
//int main()
//{
//	//����һ���߳�
//	thread t1(add, 100);
//	thread t2(add, 100);
//	//��ȡ�߳�id
//	cout << t1.get_id() << endl;
//	cout << t2.get_id() << endl;
//	//�̷߳��룬������̱߳�Ϊ��̨�̣߳����̵߳ġ�����������߳��޹�
//	t2.detach();
//	//�ж��߳��Ƿ���ִ��
//	if(t1.joinable())
//		//�ú���������ס�̣߳������߳̽��������̼߳���ִ��
//		t1.join();
//	cout << x << endl;
//	return 0;
//}



//void threadfunc(int n)
//{
//	cout << "thread1" << n << endl;
//}
//class TF
//{
//public:
//	void operator()(int n)
//	{
//		cout << "thread2" << n << endl;
//	}
//};
//int main()
//{
//	thread t1(threadfunc, 10);
//	thread t2(TF(), 10);
//	thread t3([](int n) {cout << "thread2" << n << endl; }, 10);
//
//	t1.join();
//	t2.join();
//	t3.join();
//	return 0;
//}

//void ThreadFunc1(int x)
//{
//	x += 10;
//}
//void ThreadFunc2(int& x)
//{
//	x += 10;
//}
//void ThreadFunc3(int* x)
//{
//	*x += 10;
//}
//int main()
//{
//	int a = 10;
//	// ���̺߳����ж�a�޸ģ�����Ӱ���ⲿʵ�Σ���Ϊ���̺߳���������Ȼ�����÷�ʽ������ʵ�����õ����߳�ջ�еĿ���
//	thread t1(ThreadFunc1, a);
//	t1.join();
//	cout << a << endl;
//	// �����Ҫͨ���βθı��ⲿʵ��ʱ���������std::ref()����
//	thread t2(ThreadFunc2, ref(a));
//	t2.join();
//	cout << a << endl;
//	// ��ַ�Ŀ���
//	thread t3(ThreadFunc3, &a);
//	t3.join();
//	cout << a << endl;
//	return 0;
//}



//atomic_long sum = 0;
//void fun(size_t num) 
//{
//	for (size_t i = 0; i < num; ++i)
//		sum++; // ԭ�Ӳ���
//}
//int main()
//{
//	thread t1(fun, 1000000);
//	thread t2(fun, 1000000);
//	t1.join();
//	t2.join();
//	cout << sum << std::endl;
//	return 0;
//}

//mutex mtx;
//int x = 0;
//
//void add(int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		mtx.lock();
//		++x;
//		mtx.unlock();
//	}
//}
//int main()
//{
//	thread t1(add, 100);
//	thread t2(add, 100);
//	t1.join();
//	t2.join();
//	cout << x << endl;
//	return 0;
//}

#include <condition_variable>

condition_variable cv1;
condition_variable cv2;
mutex mtx1, mtx2;

void p1(int n)
{
	for (int i = 0; i < n; i += 2)
	{
		if (i != 0)
		{
			unique_lock<mutex> lck(mtx1);
			cv1.wait(lck);
		}
		cout << this_thread::get_id()  << " : "<< i << endl;
		cv2.notify_one();
	}
}

void p2(int n)
{
	for (int i = 1; i < n; i += 2)
	{
		unique_lock<mutex> lck(mtx2);
		cv2.wait(lck);
		cout << this_thread::get_id() << " : " << i << endl;
		cv1.notify_one();
	}
}

int main()
{
	thread t1(p1, 100);
	thread t2(p2, 100);
	t1.join();
	t2.join();
	return 0;
}

