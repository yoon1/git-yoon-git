package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_reverseVowels(t *testing.T) {
	tcs := []struct {
		input  string
		output string
	}{
		{"hello", "holle"},
		{"leetcode", "leotcede"},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := reverseVowels(tc.input)
			assert.Equal(t, tc.output, result)
		})
	}
}
