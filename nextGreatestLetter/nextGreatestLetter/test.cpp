#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		int left = 0, right = letters.size();
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (letters[mid] <= target)
				left = mid + 1;
			else
				right = mid;
		}
		return letters[left%letters.size()];
	}
};


int main()
{
	vector<char> l = { 'c', 'f', 'j' };
	cout << Solution().nextGreatestLetter(l, 'a');
	return 0;
}