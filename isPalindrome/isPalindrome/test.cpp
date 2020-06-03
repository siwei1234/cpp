#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		vector<int> v;
		ListNode* cur = head;
		while (cur)
		{
			v.push_back(cur->val);
			cur = cur->next;
		}
		int left = 0;
		int right = v.size() - 1;
		while (left < right)
		{
			if (v[left] != v[right])
				return false;
			left++;
			right--;
		}
		return true;
	}
};

int main()
{
	return 0;
}