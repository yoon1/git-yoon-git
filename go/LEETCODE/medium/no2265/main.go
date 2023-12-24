package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func averageOfSubtree(root *TreeNode) int {
	var sameCount = 0
	type T struct {
		val int
		num int
	}

	var subFunc func(root *TreeNode) T
	subFunc = func(root *TreeNode) T {
		var left, right T
		// root 가 nil 이면 0을 반환하고,
		if root.Left != nil {
			left = subFunc(root.Left)
		}
		if root.Right != nil {
			right = subFunc(root.Right)
		}

		var t = T{left.val + right.val + root.Val, left.num + right.num + 1}
		if t.val/t.num == root.Val {
			sameCount++
		}
		return t
	}

	subFunc(root)

	return sameCount
}
