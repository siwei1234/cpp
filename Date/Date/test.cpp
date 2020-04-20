#include "Date.h"
int main()
{
	Date d1(2020, 4, 18);
	Date d2(2021, 2, 12);
	int ret = d1 - d2;
	cout << ret << endl;
	/*d1 += 300;
	d1.Print();
	d1 -= 300;
	d1.Print();
	++d1;
	d1.Print();
	Date d2(2020, 4, 18);
	d2 = d1 + 300;
	d2.Print();
	d2 = d1 - 300;
	d2.Print();*/
	
	return 0;
}