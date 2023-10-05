package structure

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_MakeListNode(t *testing.T) {
	// given
	vals := []int{18, 6, 10, 3}

	// when
	head := MakeListNode(vals)

	// then
	res := head.Traverse()
	assert.Equal(t, res, []int{18, 6, 10, 3})
}

func Test_CompareListNode(t *testing.T) {
	tcs := []struct {
		a        *ListNode
		b        *ListNode
		expected bool
	}{
		{MakeListNode([]int{18, 6, 10, 3}), MakeListNode([]int{18, 6, 10, 3}), true},
		{MakeListNode([]int{18, 6, 10}), MakeListNode([]int{18, 6, 10, 3}), false},
		{MakeListNode([]int{18, 6, 10, 3}), MakeListNode([]int{18, 6, 10}), false},
	}

	for _, tc := range tcs {
		assert.Equal(t, CompareListNode(tc.a, tc.b), tc.expected)
	}
}
