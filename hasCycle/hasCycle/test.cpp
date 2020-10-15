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
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return false;
		ListNode* first = head;
		ListNode* second = head->next;
		while (first && second)
		{
			if (second->next == NULL)
				return false;
			first = first->next;
			second = second->next->next;
			if (first == second)
				return true;
		}
		return false;
	}
};

int main()
{
	return 0;
}