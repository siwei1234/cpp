#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<queue>
using namespace std;


class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		vector<int> ret;
		if (arr.empty() || k <= 0)
			return ret;
		priority_queue<int> pq;
		for (int i = 0; i < arr.size(); i++)
		{
			if (i < k)
				pq.push(arr[i]);
			else
			{
				if (arr[i] < pq.top())
				{
					pq.pop();
					pq.push(arr[i]);
				}
			}
		}
		while (!pq.empty())
		{
			ret.push_back(pq.top());
			pq.pop();
		}
		return ret;
	}
};

int main()
{

	vector<int> arr{ 0,1,2,1 };
	vector<int> ret = Solution().getLeastNumbers(arr, 1);
	for (auto& e : ret)
		cout << e << endl;
	return 0;
}
