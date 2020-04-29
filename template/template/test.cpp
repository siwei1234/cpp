#include<iostream>
using namespace std;

//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void Swap(double& a, double b)
//{
//	double tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void Swap(char& a, char& b)
//{
//	char tmp = a;
//	a = b;
//	b = tmp;
//}

//template <class T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}

//int main()
//{
//	int a = 1, b = 2;
//	Add(a, b);
//	double c = 1.1, d = 2.2;
//	Add(c, d);
//	Add(a, (int)c);
//	return 0;
//}


//template <class T1, class T2>
//T1 Add(const T1& a, const T2& b)
//{
//	return a + b;
//}
//
//int Add(const int& a, const int& b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	double c = 1.1;
//	Add(a, b);
//	Add(a, c);
//	return 0;
//}

//template <class T>
//class Vecotr
//{
//public:
//	Vecotr(size_t capacity = 10)
//		:_a(new T[capacity])
//		,_size(0)
//		,_capacity(capacity)
//	{}
//	~Vecotr();
//	void PushBack(const T& data);
//private:
//	T* _a;
//	size_t _size;
//	size_t _capacity;
//};
//
//template <class T>
//Vecotr<T>::~Vecotr()
//{
//	if (_a)
//		delete[] _a;
//	_size = _capacity = 0;
//}

//int main()
//{
//	Vecotr<int> s1;
//	Vecotr<double> s2;
//	return 0;
//}

template <class A>
A Add(A a, A b)
{
	return a + b;
}
template <class A, class A1>
A Add(A a, A1 b)
{
	return a + b;
}

template <class A>
class Vecotr
{
public:
	Vecotr(size_t capacity = 10)
		:_a(new A[capacity])
		, _size(0)
		, _capacity(capacity)
	{}
	~Vecotr();
	void PushBack(const A& data);
private:
	A* _a;
	size_t _size;
	size_t _capacity;
};

template <class A>
Vecotr<A>::~Vecotr()
{
	if (_a)
		delete[] _a;
	_size = _capacity = 0;
}

int main()
{
	Add(1, 2);
	Add(1, 1.1);
	Vecotr<int> s1;
	return 0;
}

