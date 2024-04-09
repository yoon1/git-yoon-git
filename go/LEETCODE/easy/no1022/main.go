package main

import (
	"fmt"
	. "github.com/quiz.algorithm-solve/go/LEETCODE/structure"
	"strconv"
)

func dfs(node *TreeNode, v string) int {
	if node == nil { // return
		return 0
	}

	cur := v + fmt.Sprintf("%d", node.Val)
	if node.Left == nil && node.Right == nil { // leaf
		return binaryToDecimal(cur)
	}

	return dfs(node.Left, cur) + dfs(node.Right, cur)
}

func sumRootToLeaf(root *TreeNode) int {
	return dfs(root, "")
}

func binaryToDecimal(b string) int {
	d, _ := strconv.ParseInt(b, 2, 64)
	return int(d)
}
