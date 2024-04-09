package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"math"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func goodNodes(root *TreeNode) int {
	if root == nil {
		return 0
	}

	return dfs(root, math.MinInt)
}

func dfs(node *TreeNode, max int) int {
	if node == nil {
		return 0
	}

	var v = 0
	if node.Val >= max {
		v = 1
		max = node.Val
	}

	return v + dfs(node.Left, max) + dfs(node.Right, max)
}
