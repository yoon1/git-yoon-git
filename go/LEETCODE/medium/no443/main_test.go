package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortColors(t *testing.T) {
	tcs := []struct {
		input    []byte
		expected int
	}{
		{[]byte{'a', 'a', 'b', 'b', 'c', 'c', 'c'}, 6},
		{[]byte{'a'}, 1},
		{[]byte{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}, 4},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := compress(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
