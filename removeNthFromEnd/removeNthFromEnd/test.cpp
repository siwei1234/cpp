#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* newhead = new ListNode(0, head);
		ListNode* first = head;
		ListNode* second = newhead;
		for (int i = 0; i < n; i++)
			first = first->next;
		while (first)
		{
			first = first->next;
			second = second->next;
		}
		second->next = second->next->next;
		return newhead->next;
	}
};


int main()
{
	return 0;
}
