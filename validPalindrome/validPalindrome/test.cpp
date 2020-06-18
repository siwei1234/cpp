#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool isture(string& s, int left, int right)
	{
		while (left < right)
		{
			if (s[left] == s[right])
			{
				left++;
				right--;
			}
			else
				return false;
		}
		return true;
	}
	bool validPalindrome(string s) {
		int left = 0;
		int right = s.size() - 1;
		int flag = 0;
		while (left < right)
		{
			if (s[left] == s[right])
			{
				left++;
				right--;
			}
			else
			{
				return isture(s, left + 1, right) || isture(s, left, right - 1);
			}
		}
		return true;
	}
};

int main()
{
	string s("aabbccbebaa");
	cout << Solution().validPalindrome(s) << endl;
	return 0;
}