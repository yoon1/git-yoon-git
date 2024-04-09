package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		input    int
		expected bool
	}{
		{9, false},
		{4, false},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := isStrictlyPalindromic(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
