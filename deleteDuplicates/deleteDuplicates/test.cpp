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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* cur = head;
		while (cur && cur->next)
		{
			if (cur->val == cur->next->val)
				cur->next = cur->next->next;
			else
				cur = cur->next;
		}
		return head;
	}
};

int main()
{
	return 0;
}