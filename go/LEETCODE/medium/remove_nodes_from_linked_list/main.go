package main

import . "github.com/quiz.algorithm-solve/go/LEETCODE/structure"

func removeNodes(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	var big = head
	for cur := head; cur.Next != nil; cur = cur.Next {
		var next = cur.Next
		if cur.Val < next.Val {
			if big.Val < next.Val {
				big = next
				continue
			}

			for p := big; p != next && p.Next != nil; p = p.Next {
				if p.Next.Val < next.Val {
					p.Next = next
				}
			}
		}
	}

	return big
}
