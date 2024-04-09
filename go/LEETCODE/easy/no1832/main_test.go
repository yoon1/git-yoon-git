package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		str      string
		expected string
	}{
		{"(()())(())", "()()()"},
		{"(()())(())(()(()))", "()()()()(())"},
		{"()()", ""},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := removeOuterParentheses(tc.str)
			assert.Equal(t, tc.expected, result)
		})
	}
}
