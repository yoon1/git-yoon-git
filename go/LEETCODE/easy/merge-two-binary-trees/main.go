package main

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func mergeTrees(root1 *TreeNode, root2 *TreeNode) *TreeNode {
	if root1 == nil {
		return root2
	}

	if root2 == nil {
		return root1
	}

	var res = &TreeNode{Val: root1.Val + root2.Val}

	dfs(res, root1.Left, root2.Left, true)
	dfs(res, root1.Right, root2.Right, false)

	return res
}

func dfs(res, root1 *TreeNode, root2 *TreeNode, isLeft bool) {
	if root1 == nil && root2 == nil {
		return
	}

	var newNode = &TreeNode{}
	if isLeft {
		res.Left = newNode
	} else {
		res.Right = newNode
	}

	if root1 != nil && root2 != nil {
		newNode.Val = root1.Val + root2.Val
	} else if root1 != nil {
		newNode.Val = root1.Val
	} else if root2 != nil {
		newNode.Val = root2.Val
	}

	var left1, left2, right1, right2 *TreeNode
	if root1 != nil {
		left1 = root1.Left
		right1 = root1.Right
	}
	if root2 != nil {
		left2 = root2.Left
		right2 = root2.Right
	}

	dfs(newNode, left1, left2, true)
	dfs(newNode, right1, right2, false)
}
