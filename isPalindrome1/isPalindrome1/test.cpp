#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;




  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	ListNode* prev;
	bool _isPalindrome(ListNode* cur)
	{
		if (cur != NULL)
		{
			if (!_isPalindrome(cur->next))
				return false;
			if (cur->val != prev->val)
				return false;
			prev = prev->next;
		}
		return true;
	}
	bool isPalindrome(ListNode* head) {
		prev = head;
		return _isPalindrome(head);
	}
};


int main()
{
	return 0;
}