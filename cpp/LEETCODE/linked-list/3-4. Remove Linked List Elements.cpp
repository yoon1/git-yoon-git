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
	ListNode* removeElements(ListNode* head, int val) {
		// head
		while (head && head->val == val) {
			head = head->next;
		}

		ListNode *pre = head, *cur = head->next;
		while (cur) {
			if (cur->val == val) {
				pre->next = cur->next;
				cout << "find" << endl;
			}
			pre = pre->next;
			cur = cur->next;
		}
		return head;
	}
};

int main() {
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(6);
	ListNode *n4 = new ListNode(3);
	ListNode *n5 = new ListNode(4);
	ListNode *n6 = new ListNode(5);
	ListNode *n7 = new ListNode(6);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;

	Solution s;
	ListNode *head = s.removeElements(n1, 6);

	return 0;
}