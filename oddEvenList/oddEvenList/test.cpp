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
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr)
			return head;
		ListNode* cur = head;
		ListNode* evenHead = head->next;
		ListNode* even = evenHead;
		while (even != nullptr && even->next != nullptr)
		{
			cur->next = even->next;
			cur = cur->next;
			even->next = cur->next;
			even = even->next;
		}
		cur->next = evenHead;
		return head;
	}
};


int main()
{
	return 0;
}