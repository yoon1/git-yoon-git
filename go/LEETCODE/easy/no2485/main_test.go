package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	tcs := []struct {
		input    int
		expected int
	}{
		{8, 6},
		{1, 1},
		{4, -1},
		{20, -1},
		{7, -1},
		{49, 35},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := pivotInteger(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
