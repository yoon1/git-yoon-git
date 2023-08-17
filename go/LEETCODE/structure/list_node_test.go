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
