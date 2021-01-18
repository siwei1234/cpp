#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool checkStraightLine(vector<vector<int>> &coordinates) {
		int deltaX = coordinates[0][0], deltaY = coordinates[0][1];
		int n = coordinates.size();
		for (int i = 0; i < n; ++i) {
			coordinates[i][0] -= deltaX;
			coordinates[i][1] -= deltaY;
		}
		int A = coordinates[1][1], B = -coordinates[1][0];
		for (int i = 2; i < n; ++i) {
			int x = coordinates[i][0], y = coordinates[i][1];
			if (A * x + B * y != 0) {
				return false;
			}
		}
		return true;
	}
};

int main()
{
	vector<vector<int>> coordinates = { {1, 2},{2, 3},{3, 4},{4, 5},{5, 6},{6, 7} };
	cout << Solution().checkStraightLine(coordinates) << endl;
	return 0;
}