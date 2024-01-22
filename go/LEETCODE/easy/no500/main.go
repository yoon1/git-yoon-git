package main

import "strings"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findWords(words []string) []string {
	var res []string
	for _, word := range words {
		if sameKeyboardRow(strings.ToLower(word)) {
			res = append(res, word)
		}
	}

	return res
}

func sameKeyboardRow(s string) bool {
	rows := []string{"qwertyuiop", "asdfghjkl", "zxcvbnm"}

	var firstIdx int
	for i, row := range rows {
		if strings.Contains(row, string(s[0])) {
			firstIdx = i
			break
		}
	}

	for _, v := range s {
		if strings.Contains(rows[firstIdx], string(v)) == false {
			return false
		}
	}

	return true
}
