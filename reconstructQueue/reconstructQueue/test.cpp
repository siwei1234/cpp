#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
			return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
		});
		vector<vector<int>> ans;
		for (const vector<int>& person : people) {
			ans.insert(ans.begin() + person[1], person);
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>> people = { {7, 0},{4, 4},{7, 1},{5, 0},{6, 1},{5, 2} };
	people = Solution().reconstructQueue(people);
	for (auto& i : people)
		cout << i[0] << " " << i[1] << endl;
	return 0;
}