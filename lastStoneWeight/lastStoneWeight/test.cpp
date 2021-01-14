#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> q;
		for (int s : stones) {
			q.push(s);
		}

		while (q.size() > 1) {
			int a = q.top();
			q.pop();
			int b = q.top();
			q.pop();
			if (a > b) {
				q.push(a - b);
			}
		}
		return q.empty() ? 0 : q.top();
	}
};

int main()
{
	vector<int> nums = { 2,7,4,1,8,1 };
	cout << Solution().lastStoneWeight(nums) << endl;
	return 0;
}