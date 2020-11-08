#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
using namespace std;



class Solution {
public:
	string countAndSay(int n) {
		if (n == 1)
			return "1";
		string prev = countAndSay(n - 1);
		string ret;
		int count = 1;
		for (int i = 0; i < prev.size(); i++)
		{
			if (prev[i] == prev[i + 1])
				count++;
			else
			{
				ret += to_string(count) + prev[i];
				count = 1;
			}
		}
		return ret;
	}
};
int main()
{
	cout << Solution().countAndSay(6) << endl;
	return 0;
}