#include<iostream>
using namespace std;

//int main()
//{
//	int a = 10;
//	int& ra = a;	//���ö�������
//	printf("%p\n", &a);
//	printf("%p\n", &ra);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	//int &ra;	ʹ���������ᱨ��
//	int ra = a;
//	int rra = a;
//	int rrra = a;
//	return 0;
//}


//int main()
//{
//	const int a = 40;
//	//int &re = a;	ʹ���������ᱨ��
//	const int& re = a;
//	//int& b = 10;	ʹ���������ᱨ��
//	double d = 11.1;
//	//int& rd = d;	ʹ���������ᱨ��
//	const int& rd = d;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	const int* cp = &a;
//	int* p = cp;
//	return 0;
//}

//
//void swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int a = 0;
//	int b = 10;
//	swap(a, b);
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}

//int& count()
//{
//	int n = 0;
//	n++;
//	return n;
//}
//int main()
//{
//	int& i = count();
//	return 0;
//}


inline void Print()
{
	printf("hehe\n");
}

int& count(int a, int b)
{
	static int c = 1;
	c = a + b;
	return c;
}
int main()
{
	int& i = count(1, 2);
	printf("%d\n", i);
	Print();
	return 0;
}