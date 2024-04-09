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
func deleteNode(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return nil
	}

	if key == root.Val {
		if root.Left == nil {
			return root.Right
		}

		if root.Right == nil {
			return root.Left
		}

		m := find(root.Right)
		root.Val, root.Right = m.Val, deleteNode(root.Right, m.Val)
	}

	if key < root.Val {
		root.Left = deleteNode(root.Left, key)
		return root
	}

	if key > root.Val {
		root.Right = deleteNode(root.Right, key)
		return root
	}

	return root
}

func find(node *TreeNode) *TreeNode {
	for node.Left != nil {
		node = node.Left
	}

	return node
}
