package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		s        string
		expected int
	}{
		{"III", 3},
		{"LVIII", 58},
		{"MCMXCIV", 1994},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := romanToInt(tc.s)
			assert.Equal(t, tc.expected, result)
		})
	}
}
