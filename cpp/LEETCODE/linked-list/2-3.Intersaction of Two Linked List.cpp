#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *pA = headA;
		while (pA) {
			ListNode *pB = headB;
			while (pB) {
				if (&pA == &pB)
					return pA;
				pB = pB->next;
			}
			pA = pA->next;
		}

		return NULL;
	}
};

int main() {
	Solution a;
	//ListNode *node;
	//a.getIntersectionNode()
	return 0;
}

