package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		input    []string
		expected int
	}{
		{[]string{"cd", "ac", "dc", "ca", "zz"}, 2},
		{[]string{"ab", "ba", "cc"}, 1},
		{[]string{"aa", "ab"}, 0},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := maximumNumberOfStringPairs(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
