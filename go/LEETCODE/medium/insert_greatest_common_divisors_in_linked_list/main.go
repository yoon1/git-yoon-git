package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}

	return a
}

func insertGreatestCommonDivisors(head *ListNode) *ListNode {
	p := head
	for p.Next != nil {
		node := &ListNode{
			Val:  gcd(p.Val, p.Next.Val),
			Next: p.Next,
		}
		p.Next = node
		p = p.Next.Next
	}

	return head
}
