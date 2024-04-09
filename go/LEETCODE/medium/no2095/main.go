package main

import . "github.com/quiz.algorithm-solve/go/LEETCODE/structure"

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteMiddle(head *ListNode) *ListNode {
	if head.Next == nil {
		return nil
	}

	var half = head
	var c = -1
	for node := head; node != nil; node = node.Next {
		if c > 0 && c%2 == 0 {
			half = half.Next
		}
		c++
	}

	if half.Next != nil {
		half.Next = half.Next.Next
	}

	return head
}
