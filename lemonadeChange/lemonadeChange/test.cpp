#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int f = 0, t = 0;
		for (auto& i : bills)
		{
			if (i == 5)
				f++;
			else if (i == 10)
			{
				if (f == 0)
					return false;
				f--;
				t++;
			}
			else
			{
				if (f > 0 && t > 0)
				{
					f--;
					t--;
				}
				else if (f >= 3)
					f -= 3;
				else
					return false;
			}
		}
		return true;
	}
};


int main()
{
	vector<int> bills = { 5,5,5,10,20 };
	cout << Solution().lemonadeChange(bills) << endl;
	return 0;
}