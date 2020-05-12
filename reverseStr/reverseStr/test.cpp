#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		int len = s.size();
		for (int i = 0; i < len; i += 2 * k)
		{
			int left = i;
			int right;
			if ((len - i) > k)
				right = i + k - 1;
			else
				right = len - 1;
			while (left < right)
			{
				char tmp = s[left];
				s[left] = s[right];
				s[right] = tmp;
				left++;
				right--;
			}
		}
		return s;
	}
};


int main()
{
	cout << (Solution().reverseStr("abcdefg", 2)) << endl;
	return 0;
}