package main

import (
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
)

func getAllElements(root1 *TreeNode, root2 *TreeNode) []int {
	var arr1, arr2 []int
	preorder(root1, &arr1)
	preorder(root2, &arr2)

	return mergeArrays(arr1, arr2)
}

func mergeArrays(arr1 []int, arr2 []int) []int {
	merged := make([]int, 0, len(arr1)+len(arr2))
	i, j := 0, 0

	for i < len(arr1) && j < len(arr2) {
		if arr1[i] <= arr2[j] {
			merged = append(merged, arr1[i])
			i++
		} else {
			merged = append(merged, arr2[j])
			j++
		}
	}

	for i < len(arr1) {
		merged = append(merged, arr1[i])
		i++
	}

	for j < len(arr2) {
		merged = append(merged, arr2[j])
		j++
	}

	return merged
}

func preorder(root *TreeNode, arr *[]int) {
	if root == nil {
		return
	}

	preorder(root.Left, arr)
	*arr = append(*arr, root.Val)
	preorder(root.Right, arr)

	return
}
