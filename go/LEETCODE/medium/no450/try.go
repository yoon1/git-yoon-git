package main

import . "github.com/quiz.algorithm-solve/go/LEETCODE/structure"

func try(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return nil
	}

	var find func(node *TreeNode, parent *TreeNode) bool
	find = func(node *TreeNode, parent *TreeNode) bool {
		if node == nil {
			return true
		}

		if node.Val == key {
			if node.Right == nil {
				return true
			}

			temp := (*node).Left
			*node = *node.Right
			(*node).Left = temp

			return true
		}

		return find(node.Left, node) || find(node.Right, node)
	}

	find(root, nil)
	return root
}
