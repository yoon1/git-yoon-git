package main

import . "github.com/quiz.algorithm-solve/go/LEETCODE/structure"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func subtreeWithAllDeepest(root *TreeNode) *TreeNode {
	var (
		dfs      func(root *TreeNode, depth int)
		maxDepth = 0
		res      = root
	)

	dfs = func(node *TreeNode, depth int) {
		if node == nil {
			return
		}

		if (node.Left == nil && node.Right == nil) ||
			node.Left != nil && node.Right != nil {
			if depth > maxDepth {
				maxDepth = depth
				res = node
			}
		}

		dfs(node.Left, depth+1)
		dfs(node.Right, depth+1)
	}

	dfs(root, 0)

	return res
}
