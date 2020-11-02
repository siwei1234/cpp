#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	int _romanToInt(char s)
	{
		switch (s)
		{
		case 'I':return 1; break;
		case 'V':return 5; break;
		case 'X':return 10; break;
		case 'L':return 50; break;
		case 'C':return 100; break;
		case 'D':return 500; break;
		case 'M':return 1000; break;
		}
		return 0;
	}
	int romanToInt(string s) {
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int tmp = _romanToInt(s[i]);
			if (_romanToInt(s[i + 1]) > tmp)
				tmp = -tmp;
			sum += tmp;
		}
		return sum;
	}
};



int main()
{
	string s = "MCMXCIV";
	cout << Solution().romanToInt(s) << endl;
	return 0;
}