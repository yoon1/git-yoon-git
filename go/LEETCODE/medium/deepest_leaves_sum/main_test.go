package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortColors(t *testing.T) {
	tcs := []struct {
		root   *TreeNode
		aspect int
	}{
		{
			root: &TreeNode{
				Val: 1,
				Left: &TreeNode{
					Val: 2,
					Left: &TreeNode{
						Val: 4,
						Left: &TreeNode{
							Val: 7,
						},
					},
					Right: &TreeNode{
						Val: 5,
					},
				},
				Right: &TreeNode{
					Val: 3,
					Right: &TreeNode{
						Val: 6,
						Right: &TreeNode{
							Val: 8,
						},
					},
				},
			},
			aspect: 15,
		},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := deepestLeavesSum(tc.root)
			assert.Equal(t, tc.aspect, result)
		})
	}
}
