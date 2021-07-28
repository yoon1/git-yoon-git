#include <iostream>

using namespace std; 

// Definition for singly-linked list.
struct SinglyListNode {
	int val;
	SinglyListNode* next;

	SinglyListNode(int x) {
		val = x;
		next = NULL;
	}
};

class MyLinkedList {
	SinglyListNode* head;

public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		head = NULL;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		SinglyListNode* p = head;
		int i = 0;
		while (i < index && p) {
			i++;
			p = p->next;
		}
		return p->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		SinglyListNode* newNode= new SinglyListNode(val);
		newNode->next = head;
		head = newNode;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		SinglyListNode* newNode = new SinglyListNode(val);
		SinglyListNode* p = head;
		if (p != NULL) {
			while (p->next) {
				p = p->next;
			}
		}
		p->next = newNode;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		SinglyListNode* newNode = new SinglyListNode(val);
		SinglyListNode* cur = head;
		SinglyListNode* next = cur->next;
		int i = 0;
		if (cur != NULL) {
			while (++i < index && cur->next) {
				cur = cur->next;
				next = cur->next;
			}
		}
		newNode->next = next;
		cur->next = newNode;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		SinglyListNode* cur = head;
		SinglyListNode* next = NULL;
		int i = 0;
		while (i < index && cur != NULL) {
			next = cur->next;
			i++;
		}
		cur->next = next->next;
		free(next);
	}
};

int main() {
	MyLinkedList* obj = new MyLinkedList();

	obj->addAtHead(1);
	obj->addAtTail(3);
	obj->addAtIndex(1, 2);    // linked list becomes 1->2->3
	obj->get(1);              // return 2
	obj->deleteAtIndex(1);    // now the linked list is 1->3
	//obj->get(2);              // return 3

	return 0;
}