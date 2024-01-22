package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_leafSimilar(t *testing.T) {
	tcs := []struct {
		words    []string
		expected []string
	}{
		{[]string{"Hello", "Alaska", "Dad", "Peace"}, []string{"Alaska", "Dad"}},
		{[]string{"omk"}, []string{}},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := findWords(tc.words)
			assert.Equal(t, tc.expected, result)
		})
	}
}
