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
	ListNode* oddEvenList(ListNode* head) {
		ListNode* pOdd = head;
		ListNode* pEven = (head->next) ? head->next : NULL;
		ListNode* p = new ListNode();
		ListNode* p2 = p;
		while (pOdd) {
			p2->next = new ListNode(pOdd->val);
			p2 = p2->next;
			pOdd = (pOdd->next && pOdd->next->next) ? pOdd->next->next : NULL;
		}

		while (pEven) {
			p2->next = new ListNode(pEven->val);
			p2 = p2->next;
			pEven = (pEven->next && pEven->next->next) ? pEven->next->next : NULL;
		}

		return p->next;
	}
};


int main() {
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution s;
	ListNode *head = s.oddEvenList(n1);

	return 0;
}
