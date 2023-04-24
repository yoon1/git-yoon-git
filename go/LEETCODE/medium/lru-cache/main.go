package main

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func deepestLeavesSum(root *TreeNode) int {
	var leafDepth = 0
	var res = 0
	var dfs func(node *TreeNode, depth int)
	dfs = func(node *TreeNode, depth int) {
		if node == nil {
			return
		}

		if node.Left == nil && node.Right == nil {
			if depth > leafDepth {
				leafDepth = depth
				res = 0
			}

			if depth == leafDepth {
				res += node.Val
			}
		}

		dfs(node.Left, depth+1)
		dfs(node.Right, depth+1)
	}

	dfs(root, 0)

	return res
}
