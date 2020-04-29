#include<iostream>
using namespace std;
//int a = 0;
//static int b = 0;
//int main()
//{
//	static int c = 0;
//	int d = 0;
//	int e[10] = { 1,2,3 };
//	char f[] = "abcd";
//	char* g = "abcd";
//	int* h = (int*)malloc(sizeof(int) * 10);
//	free(h);
//	return 0;
//}

//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int) * 4);
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	free(p1);
//	free(p3);
//}

//int main()
//{
//	int* ptr1 = new int;
//	int* ptr2 = new int(10);
//	int* ptr3 = new int[10];
//	delete ptr1;
//	delete ptr2;
//	delete[] ptr3;
//	return 0;
//}

class Test
{
public:
	Test(int a = 10)
		:_data(a)
	{
		cout << _data << endl;
	}
	~Test()
	{
		_data = 0;
		cout << _data << endl;
	}
private:
	int _data;
};

int main()
{
	Test* p = (Test*)malloc(sizeof(Test));
	new(p)Test(100);
	return 0;
}
//
//int main()
//{
//	Test* t1 = new Test;
//	Test* p1 = (Test*)malloc(sizeof(Test));
//	Test* t2 = new Test[10];
//	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
//	delete t1;
//	free(p1);
//	delete[] t2;
//	free(p2);
//	return 0;
//}