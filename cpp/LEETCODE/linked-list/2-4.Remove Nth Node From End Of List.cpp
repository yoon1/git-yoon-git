#include <iostream>

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
	int getListLength(ListNode* head) {
		int len = 0;
		while (head) {
			head = head->next;
			len++;
		}
		return len;
	}

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int len = getListLength(head);
		int targetN = len - n; // 3
		int idx = 1;
		ListNode *slow = head, *fast = head->next;
		while (targetN > idx && fast) {
			slow = slow->next;
			fast = fast->next;
			idx++;
		}
		//slow->next = slow->next && fast->next ? fast->next : NULL;
		slow = fast;
		return head;
	}
};

int main() {
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	//ListNode *n3 = new ListNode(3);
	//ListNode *n4 = new ListNode(4);
	//ListNode *n5 = new ListNode(5);
	n1->next = n2;
	//n2->next = n3;
	//n3->next = n4;
	//n4->next = n5;

	Solution s;
	int len = s.getListLength(n1);
	cout << len;

	s.removeNthFromEnd(n1, 2);

	//int len = s.getListLength(n2);
	return 0;
}