package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"reflect"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	var lv1, lv2 []int
	getLeaves(root1, &lv1)
	getLeaves(root2, &lv2)

	return reflect.DeepEqual(lv1, lv2)
}

func getLeaves(root *TreeNode, leaves *[]int) {
	if root == nil {
		return
	}

	if root.Left == nil && root.Right == nil { // leaf
		*leaves = append(*leaves, root.Val)
	}

	getLeaves(root.Left, leaves)
	getLeaves(root.Right, leaves)
}
