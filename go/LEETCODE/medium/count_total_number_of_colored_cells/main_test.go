package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortColors(t *testing.T) {
	tcs := []struct {
		input    int
		expected int64
	}{
		{1, 1},
		{2, 5},  // +4 4 (4*1) -> 1
		{3, 13}, // +8 12 (4*3) -> 2
		{4, 25}, // +12 24 (4*6) -> 3
		{5, 41}, // +12 40 {4*10) -> 4
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := coloredCells(tc.input)
			assert.Equal(t, tc.expected, result)
		})
	}
}
