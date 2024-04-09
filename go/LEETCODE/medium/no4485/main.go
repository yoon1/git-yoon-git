package main

import . "github.com/quiz.algorithm-solve/go/LEETCODE/structure"

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func insertionSortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	d := &ListNode{Next: head}

	pre := head
	for cur := head.Next; cur != nil; cur = pre.Next {
		if cur.Val >= pre.Val {
			pre = cur
			continue
		}

		insert := d
		for insert.Next != cur && insert.Next.Val < cur.Val {
			insert = insert.Next
		}

		pre.Next = cur.Next
		cur.Next = insert.Next
		insert.Next = cur
	}

	return d.Next
}
