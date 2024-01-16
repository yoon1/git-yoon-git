package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
)

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapNodes(head *ListNode, k int) *ListNode {
	length := nodeLength(head)
	left := searchNode(head, k)
	right := searchNode(head, length-k+1)
	swapNode(left, right)
	return head
}

func swapNode(left, right *ListNode) {
	left.Val, right.Val = right.Val, left.Val
}

// search returns pre, right
func searchNode(head *ListNode, k int) *ListNode {
	var i = 1
	for cur := head; cur != nil && i <= k; cur = cur.Next {
		if i == k {
			return cur
		}
		i++
	}

	return nil
}

func nodeLength(head *ListNode) int {
	var length int
	for p := head; p != nil; p = p.Next {
		length++
	}

	return length
}
