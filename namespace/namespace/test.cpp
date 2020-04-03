//#include<stdio.h>
//namespace N
//{
//	int a = 10;
//	//int printf = 100;
//	int add(int m, int n)
//	{
//		return m + n;
//	}
//}
//namespace N2
//{
//	int a = 20;
//	namespace N3
//	{
//		int a = 0;
//	}
//}
//int main()
//{
//	printf("%d\n", N::a);
//	printf("%d\n", N::printf);
//	printf("%d\n", N::add(10, 20));
//	printf("%d\n", N2::a);
//	printf("%d\n", N2::N3::a);
//	return 0;
//}


//using N::a;
//int main()
//{
//	printf("%d\n", a);
//	printf("%d\n", N::a);
//	return 0;
//}

//using namespace N;
//int main()
//{
//	printf("%d\n", a);
//	printf("%d\n", add(10, 20));
//	printf("%d\n", N::a);
//	printf("%d\n", N::add(10, 20));
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}


//#include<iostream>
//using std::cout;
//using std::endl;
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}


//#include<iostream>
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	return 0;
//}


#include<iostream>
using namespace std;
int main()
{
	int a;
	double b;
	char c;
	cin >> a;
	cin >> b >> c;
	cout << a << endl;
	cout << b << "	" << c << endl;
	return 0;
}