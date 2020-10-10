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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* cur = head;
		ListNode* prev = NULL;
		while (cur)
		{
			if (cur->val == val)
			{
				if (prev == NULL)
					head = cur->next;
				else
					prev->next = cur->next;
				cur = cur->next;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
		return head;
	}
};

int main()
{
	return 0;
}