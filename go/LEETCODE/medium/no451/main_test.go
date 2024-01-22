package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		s        string
		expected string
	}{
		//{"tree", "eert"},
		//{"cccaaa", "aaaccc"},
		//{"Aabb", "bbAa"},
		{"abbbaacacf", "aaaabbbccf"},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := frequencySort(tc.s)
			assert.Equal(t, tc.expected, result)
		})
	}
}
