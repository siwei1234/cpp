#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int findString(vector<string>& words, string s) {
		int left = 0;
		int right = words.size() - 1;
		while (left <= right)
		{
			if (words[left].size() == 0)
			{
				left++;
				continue;
			}
			if (words[right].size() == 0)
			{
				right--;
				continue;
			}
			int mid = (left + right) >> 1;
			while (words[mid].size() == 0)
			{
				mid++;
				if (mid == right)
					right = (left + right) >> 1;
			}
			if (words[mid] == s)
				return mid;
			else if (words[mid] > s)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return -1;
	}
};
int main()
{
	vector<string> word = { "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", "" };
	string s("ball");
	cout << Solution().findString(word, s) << endl;
	return 0;
}