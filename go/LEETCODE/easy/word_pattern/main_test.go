package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_wordPattern(t *testing.T) {
	tcs := []struct {
		pattern string
		s       string
		answer  bool
	}{
		{"abba", "dog cat cat dog", true},
		{"abba", "dog cat cat fish", false},
		{"aaaa", "dog cat cat dog", false},
		{"abba", "dog dog dog dog", false},
		{"abba", "aa aa aa aa", false},
		{"abba", "dog cat cat dog", false},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := wordPattern(tc.pattern, tc.s)
			assert.Equal(t, result, tc.answer)
		})
	}
}
