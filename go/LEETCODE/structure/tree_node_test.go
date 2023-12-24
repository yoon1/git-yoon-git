package structure

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_createTree(t *testing.T) {
	var (
		input    = []int{1, 2, 3, 4, 5, NULL, 6, 7, NULL, NULL, NULL, NULL, 8}
		expected = &TreeNode{
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
		}
	)

	var created = CreateTree(input)
	assert.Equal(t, IsSameTree(created, expected), true)
}
