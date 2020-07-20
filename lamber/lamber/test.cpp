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
//	//内置类型变量
//	int a1 = { 10 };
//	int a2(10);
//	int a3 = 1 + 1;
//	int a4 = { 1 + 1 };
//	int a5{ 1 + 1 };
//	//数组
//	int arr1[5]{ 1,2,3,4,5 };
//	int arr2[]{ 1,2,3,4,5 };
//	//动态数组
//	int* arr3 = new int[5]{ 1,2,3,4,5 };
//	//标准容器
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
//	//显式缺省构造函数，由编译器生成
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
//	//编译失败，因为没有默认构造函数
//	//A a2;
//	//编译失败，因为没有赋值运算符重载
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
//// 函数的返回值结果为引用,是左值
//int& GetG_A()
//{
//	return g_a;
//}
//
////函数的返回值是临时变量，是右值
//int Get()
//{
//	return g_a;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	// a和b都是左值，b既可以在=的左侧，也可在右侧，
//	// 说明：左值既可放在=的左侧，也可放在=的右侧
//	a = b;
//	b = a;
//
//	const int c = 30;
//	// 编译失败，c为const常量，只读不允许被修改
//	//c = a;
//	// 因为可以对c取地址，因此c严格来说不算是左值
//	cout << &c << endl;
//
//	// 编译失败：因为b+1的结果是一个临时变量，没有具体名称，也不能取地址，因此为右值
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
//	// 左值引用的定义
//	int a = 0;
//	int& b = a;
//
//	// 左值引用不能引用右值, const左值引用可以
//	//int& e = 10; 
//	//int& f = x + y;
//	const int& e = 10;
//	const int& f = x + y;
//
//
//	// 右值引用的定义
//	int&& c = 10;
//	int&& d = x + y;
//
//	// 右值引用不能引用左值，但是可以引用move后左值
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
//		cout << "String(const String& s)-拷贝构造-效率低" << endl;
//
//		_str = new char[strlen(s._str) + 1];
//		strcpy(_str, s._str);
//	}
//
//	// s3(右值-将亡值)
//	String(String&& s)
//		:_str(nullptr)
//	{
//		// 传过来的是一个将亡值，反正你都要亡了，我的目的是跟你有一样大的空间，一样的值
//		// 不如把你的控制和只给我
//		cout << "String(String&& s)-移动构造-效率高" << endl;
//		swap(_str, s._str);
//	}
//
//	// s3 = s4
//	String& operator=(const String& s)
//	{
//		cout << "String& operator=(const String& s)-拷贝赋值-效率低" << endl;
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
//	// s3 = 右值-将亡值
//	String& operator=(String&& s)
//	{
//		cout << "String& operator=(String&& s)-移动赋值-效率高" << endl;
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
//		return ret;  // 返回的是右值
//	}
//
//	// s1 += s2
//	String& operator+=(const String& s2)
//	{
//		//this->append(s2);
//		return *this; // 返回是左值
//	}
//
//private:
//	char* _str;
//};
//String f(const char* str)
//{
//	String tmp(str);
//	return tmp; // 这里返回实际是拷贝tmp的临时对象
//}
//
//int main()
//{
//	String s1("左值");
//	String s2(s1);                      // 参数是左值
//	String s3(f("右值-将亡值"));        // 参数是右值-将亡值(传递给你用，用完我就析构了)
//
//	String s5("左值");
//	s5 = s1;
//	s5 = f("右值-将亡值");
//
//	return 0;
//}


//void Fun(int &x) { cout << "左值" << endl; }
//void Fun(const int &x) { cout << "const 左值" << endl; }
//void Fun(int &&x) { cout << "右值" << endl; }
//void Fun(const int&& x) { cout << "const 右值" << endl; }
//
//template<typename T>
//void func(T &&t)
//{
//	// 右值引用会第二次之后的参数传递过程中右值属性丢失,下一层调用会全部识别为左值
//	// 完美转发解决
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
//	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, {"菠萝", 1.5} };
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
//	//构造一个线程
//	thread t1(add, 100);
//	thread t2(add, 100);
//	//获取线程id
//	cout << t1.get_id() << endl;
//	cout << t2.get_id() << endl;
//	//线程分离，分离的线程变为后台线程，该线程的“死活”就与主线程无关
//	t2.detach();
//	//判断线程是否还在执行
//	if(t1.joinable())
//		//该函数会阻塞住线程，当该线程结束后，主线程继续执行
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
//	// 在线程函数中对a修改，不会影响外部实参，因为：线程函数参数虽然是引用方式，但其实际引用的是线程栈中的拷贝
//	thread t1(ThreadFunc1, a);
//	t1.join();
//	cout << a << endl;
//	// 如果想要通过形参改变外部实参时，必须借助std::ref()函数
//	thread t2(ThreadFunc2, ref(a));
//	t2.join();
//	cout << a << endl;
//	// 地址的拷贝
//	thread t3(ThreadFunc3, &a);
//	t3.join();
//	cout << a << endl;
//	return 0;
//}



//atomic_long sum = 0;
//void fun(size_t num) 
//{
//	for (size_t i = 0; i < num; ++i)
//		sum++; // 原子操作
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

