#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num)
{
	return 1;
}

class Solution {
public:
	int guessNumber(int n) {
		int left = 1, right = n;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			int ret = guess(mid);
			if (ret == 0)
				return mid;
			else if (ret == 1)
				left = mid + 1;
			else if (ret == -1)
				right = mid - 1;
		}
		return -1;
	}
};

int main()
{
	cout << Solution().guessNumber(5) << endl;
	return 0;
}