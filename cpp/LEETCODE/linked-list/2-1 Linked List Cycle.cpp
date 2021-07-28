#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode hasCycle(ListNode *head) {
		if (head == NULL)
			return null;

		ListNode* fast = head;
		ListNode* slow = head;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow) return &slow;
		}
		return null;
	}
};

bool hasCycle(ListNode *head) {
	ListNode* hare = head;
	ListNode* tortoise = head;

	while (tortoise and tortoise->next) {
		hare = hare->next;
		tortoise = tortoise->next->next;
		if (hare == tortoise) return true;
	}
	return false;
}