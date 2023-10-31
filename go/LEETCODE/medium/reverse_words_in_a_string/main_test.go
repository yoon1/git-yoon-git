package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortColors(t *testing.T) {
	tcs := []struct {
		input    string
		expected string
	}{
		{"the sky is blue", "blue is sky the"},
		{"  hello world  ", "world hello"},
		{"a good   example", "example good a"},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := reverseWords(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
